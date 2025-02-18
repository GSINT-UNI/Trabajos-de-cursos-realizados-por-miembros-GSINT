
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <FreeImage.h>

#include "tga.h"
#include "terrain.h"


// ILUMINACION
GLfloat lAmbient[] = {0.3,0.3,0.3,1.0};
GLfloat lDiffuse[] = {1.0,1.0,1.0,1.0};
GLfloat lSpecular[] = {1.0,1.0,1.0,1.0};

GLfloat lPosition[] = {0.0,100.0,0.0,1.0};

// MATERIALES
GLfloat mSpecular[] = {1.0,1.0,1.0,1.0};
//QUE TAN BRILLANTE SERA EL TERRENO
GLfloat mShininess[] = {64.0};

//COLORES
GLfloat cBlack[] = {0.0,0.0,0.0,1.0};
GLfloat cOrange[] = {1.0,0.5,0.5,1.0}; 
GLfloat cWhite[] = {1.0,1.0,1.0,1.0}; 
GLfloat cGrey[] = {0.1,0.1,0.1,1.0};
GLfloat cLightGrey[] = {0.9,0.9,0.9,1.0};

#define FLY	1
#define WALK	2

int navigationMode = WALK;
float angle=0.0,deltaAngle = 0.0,ratio;
float x=39.0f,y=240.0f,z=389.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f,deltaMove=0.0;
int h,w;
int font=(int)GLUT_BITMAP_8_BY_13;
static GLint snowman_display_list;
int bitmapHeight=13;
int mode;
float angle2,angle2Y,angleY;
static int deltaX=-1000,deltaY;

int terrainDL,iterations = 0,totalIterations = 0;
char s[60];

int frame,time,timebase=0;
char currentMode[80];

char gameModeString[40] = "640x480";


void init();

void changeSize(int w1, int h1)
	{

	// PREVIENE DIVISON ENTRE CERO CUANDO LA VENTANA ES MUY PEQUENA	
	if(h1 == 0)
		h1 = 1;

	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	
    glViewport(0, 0, w, h);

	
	gluPerspective(45,ratio,0.1,1000);

	//VISTA INICIAL
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}


void initScene() {
        
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	terrainDL = terrainCreateDL(0,0,0);
	//y = terrainGetHeight(0,0) + 1.75;
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,lAmbient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lDiffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,lSpecular);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void orientMe(float ang) {

	lx = sin(ang);
	lz = -cos(ang);
}


void moveMeFlat(float i) {

	x = x + i*lx;
	z = z + i*lz;
	y = y + i*ly;
}

void setOrthographicProjection() {


	glMatrixMode(GL_PROJECTION);
	//GUARDA LA MATRIZ
	glPushMatrix();
	// RESETEA LA MATRIZ
	glLoadIdentity();
	// ESTABLECE UNA PROYECCION ORTOGONAL 2D
	gluOrtho2D(0, w, 0, h);
	// INVIERTE EL EJE Y, ABAJO ES POSITIVO 
	glScalef(1, -1, 1);	
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
	// ESTABLECE LA MATRIZ A GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	// RESTABLECE LA MATRIZ ANTERIOR
	glPopMatrix();
	// REGRESA A LA MATRIZ GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font,char *string)
{
  
  char *c;
  
  glRasterPos2f(x, y);
  
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
  
}


void renderScene(void) {


// ESTABLECE EL MOVIMIENTO
	if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + 10*lx,y + 10*ly,z + 10*lz,
			  0.0f,1.0f,0.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0,GL_POSITION,lPosition);

// DIBUJA EL TERRENO EN LA ESCENA



	glMaterialfv(GL_FRONT, GL_SPECULAR, mSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS,mShininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, cGrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cWhite);
				
	glCallList(terrainDL);

	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	/*if (time - timebase > 1000) {
		printf("FPS:%4.2f\n",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}*/
	glDisable(GL_LIGHTING);
	glColor3f(0.0f,1.0f,1.0f);
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();	
	glPopMatrix();
	resetPerspectiveProjection();
	glEnable(GL_LIGHTING);
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27) {
		terrainDestroy();
		exit(0);
	}
}

void pressKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.05f;break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.05f;break;
		case GLUT_KEY_UP : 
			if (navigationMode == FLY)
				deltaMove = 5;
			else
				deltaMove = 5;
			break;
		case GLUT_KEY_DOWN : 			
			if (navigationMode == FLY)
				deltaMove = -5;
			else
				deltaMove = -5;
			break;		
	}
	if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) == 0)
		sprintf(currentMode,"Current Mode: Window");
	else
		sprintf(currentMode,
			"Current Mode: Game Mode %dx%d at %d hertz, %d bpp",
			glutGameModeGet(GLUT_GAME_MODE_WIDTH),
			glutGameModeGet(GLUT_GAME_MODE_HEIGHT),
			glutGameModeGet(GLUT_GAME_MODE_REFRESH_RATE),
			glutGameModeGet(GLUT_GAME_MODE_PIXEL_DEPTH));
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT : if (deltaAngle < 0.0f) 
								 deltaAngle = 0.0f;
							 break;
		case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f) 
								 deltaAngle = 0.0f;
							 break;
		case GLUT_KEY_UP :	 if (deltaMove > 0) 
								 deltaMove = 0;
							 break;
		case GLUT_KEY_DOWN : if (deltaMove < 0) 
								 deltaMove = 0;
							 break;
	}
}


void activeMouseMotion(int x, int y) {

		angle2 = angle + (x-deltaX)*0.001;
		angle2Y = angleY + (y-deltaY) * 0.001;
		if (angle2Y > 1.57)
			angle2Y = 1.57;
		else if (angle2Y < -1.57)
			angle2Y = -1.57;
		lx = cos(angle2Y)*sin(angle2);
		lz = -cos(angle2Y)*cos(angle2);
		ly = -sin(angle2Y);
}


void mousePress(int button, int state, int x, int y) {

	if (state == GLUT_DOWN) {

		deltaX = x;
		deltaY = y;

		navigationMode = FLY;
	} 
	else if (state == GLUT_UP) {
		angleY = angle2Y;
		angle = angle2;
		navigationMode = WALK;
	}
}





void init() {
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutMotionFunc(activeMouseMotion);
	glutMouseFunc(mousePress);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	initScene();

}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1280,800);
	glutCreateWindow("MAPA1");

	if (terrainLoadFromImage("mapa.tga",1) != TERRAIN_OK)
		return(-1);
	terrainScale(0,40);
	
	
	init();
	

	glutMainLoop();


	return(0);
}
