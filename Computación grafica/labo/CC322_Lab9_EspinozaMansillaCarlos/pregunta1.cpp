/*       Lab09_1.c 
 *
 *  This displays three multisegment bezier curves.
 *  The first uses two segments to make a curly bracket, drawn in black.
 *
 *  The second uses a small set of contol points to make a closed
 *  curve that looks like a circle, which is drawn in red.
 *
 *  The third plots enough control points exactly on a circle to
 *  allow for N Bezier segments.  This is drawn in green.
 *
 *  All of these are drawn in the y-z plane, with the x-axis coming
 *  out at the viewer.
 */

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

GLfloat data[7][3] = { 
  {0.0, -3.0, 0.0},  {0.0, -2.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, -0.7, 0.3},
  {0.0, -1.0, 1.3}, {0.0, -2.0, 0.6}, {0.0, -3.0, 1.0}
  };
/* This is enough data for two Bezier curve segments.
 */


/* The following makes a closed curve; if you inscribe this in a box
 * it will be tangent to each of the sizes of the box.  This makes
 * 4 Bezier segments.  The figure is drawn in red.
 */
GLfloat data2[13][3] = { {0.0, -2.0, 0.0},{0.0, -2.0, 1.0},{0.0, -1.0, 2.0},
			{0.0, 0.0, 2.0}, {0.0, 1.0, 2.0}, {0.0, 2.0, 1.0},
			{0.0, 2.0, 0.0}, {0.0, 2.0, -1.0}, {0.0, 1.0, -2.0},
			{0.0, 0.0, -2.0}, {0.0, -1.0, -2.0}, {0.0, -2.0, -1.0},
			{0.0, -2.0, 0.0}};

#define PI 3.1415926535
#define N 10
#define SIZE N*3+1

/* The buildCircle function below fills this with control points.
 */
GLfloat data3[SIZE][3];

void buildCircle(float r) {
  /* This fills the data3 matrix with enough control points to make
     N Bezier segments, with the control points on a circle of radius r.*/
  int i;
  float theta = 2*PI/(SIZE-1);
  for (i = 0; i < SIZE; i++ ) {
    data3[i][0] = 0.0;
    data3[i][1]= r*cos(theta*i);
    data3[i][2]=r*sin(theta*i);
  }
}

/* Here is the code to display the curves */


void display(void) {
  int i;
  
  glClear(GL_COLOR_BUFFER_BIT);
  
  /* CONTORNO DEL ROSTRO */  
  buildCircle(2.0);
  glPushMatrix();
  glTranslatef(0.0, 0.0, 0.7);
  glColor3f( 0.0, 1.0, 0.0);
  for (i = 0; i < N; i++ ) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data3[0+3*i][0]);
    glMapGrid1f(10, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, 10);
  }
  glPopMatrix();  
  
  /*pelos del gato*/
  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0);
  /* FIRST BLACK SEGMENT: */
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data[0][0]);
  glMapGrid1f(10, 0.0, 1.0);
  glEvalMesh1(GL_LINE, 0, 10);
  /* SECOND BLACK SEGMENT */
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data[3][0]);
  glMapGrid1f(10, 0.0, 1.0);
  glEvalMesh1(GL_LINE, 0, 10);
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180,0.0,0.0,1.0);
  glColor3f( 0.0, 0.0, 0.0);
  /* FIRST BLACK SEGMENT: */
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data[0][0]);
  glMapGrid1f(10, 0.0, 1.0);
  glEvalMesh1(GL_LINE, 0, 10);
  /* SECOND BLACK SEGMENT */
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data[3][0]);
  glMapGrid1f(10, 0.0, 1.0);
  glEvalMesh1(GL_LINE, 0, 10);
  glPopMatrix();
  
  
  /*BOCA DEL GATO*/
  glPushMatrix();
  glScalef(0.3,0.3,0.3);  
  glPushMatrix();  
  glTranslatef(0.0, -2.0, 0.0);
  glColor3f( 1.0, 0.0, 0.0);
  for (i = 2; i < 4; i++ ) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data2[0+3*i][0]);
    glMapGrid1f(10, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, 10);
  }
  glPopMatrix();
  glPushMatrix();  
  glTranslatef(0.0, 2.0, 0.0);
  glColor3f( 1.0, 0.0, 0.0);
  for (i = 2; i < 4; i++ ) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data2[0+3*i][0]);
    glMapGrid1f(10, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, 10);
  }
  glPopMatrix();
  glPopMatrix();
  
  /* OJOS DEL GATO */  
  buildCircle(2.0);
  glPushMatrix();
  glScalef(0.27,0.27,0.27); 
  glTranslatef(0.0, 3.2, 5.0);
  glColor3f( 0.0, 0.0, 1.0);
  for (i = 0; i < N; i++ ) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data3[0+3*i][0]);
    glMapGrid1f(10, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, 10);
  }
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180,0.0,0.0,1.0);
  glScalef(0.27,0.27,0.27); 
  glTranslatef(0.0, 3.2, 5.0);
  glColor3f( 0.0, 0.0, 1.0);
  for (i = 0; i < N; i++ ) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &data3[0+3*i][0]);
    glMapGrid1f(10, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, 10);
  }
  glPopMatrix();
  
  /*OREJAS*/
  glPushMatrix();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex3f(0.0,-1.6,1.9);
  glVertex3f(0.0,-1.8,3.5);
  glEnd();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex3f(0.0,-1.8,3.5);
  glVertex3f(0.0,-0.7,2.5);
  glEnd();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180,0.0,0.0,1.0);
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex3f(0.0,-1.6,1.9);
  glVertex3f(0.0,-1.8,3.5);
  glEnd();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex3f(0.0,-1.8,3.5);
  glVertex3f(0.0,-0.7,2.5);
  glEnd();
  glPopMatrix();
  glutSwapBuffers();
  
}

void myInit() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 60.0, 1.0, 0.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

  glEnable(GL_MAP1_VERTEX_3);
  glClearColor(1.0, 1.0, 1.0, 1.0);
}




int main(int argc, char *argv[]) {
  int i, j, k, m, n;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize(500, 500);
  glutCreateWindow( "test" );
  myInit();
  glutDisplayFunc(display);

  glutMainLoop();
}










