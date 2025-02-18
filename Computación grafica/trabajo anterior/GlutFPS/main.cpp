/*
FPS control demo in GLUT by Nghia Ho

SPACEBAR - toggle FPS control
W,A,S,D - to move
mouse - look around, inverted mouse
left/right mouse - fly up/down
ESC - quit

*/
#include "GL/glut.h"
#include <iostream>
#include "Camera.cpp"
//#include <cmath>
#include "glm.h"

using namespace std;



void Display();
void Reshape (int w, int h);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void MouseMotion(int x, int y);
void Mouse(int button, int state, int x, int y);
void Timer(int value);
void Idle();

void Grid();

Camera g_camera;
bool g_key[256];
bool g_shift_down = false;
bool g_fps_mode = false;
int g_viewport_width = 0;
int g_viewport_height = 0;
bool g_mouse_left_down = false;
bool g_mouse_right_down = false;

// Movement settings
const float g_translation_speed = 0.05;
const float g_rotation_speed = M_PI/180*0.2;

int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1290, 710);
    glutCreateWindow("FPS demo by Nghia Ho - Hit SPACEBAR to toggle FPS mode");

    //incio de posicion
    g_camera.SetPos(0,5,0);

    glutIgnoreKeyRepeat(1);

    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(Mouse);
    glutMotionFunc(MouseMotion);
    glutPassiveMotionFunc(MouseMotion);
    glutKeyboardFunc(Keyboard);
    glutKeyboardUpFunc(KeyboardUp);
    glutIdleFunc(Idle);

    glutTimerFunc(1, Timer, 0);
    glutMainLoop();

    return 0;
}

void Grid()
{
    glPushMatrix();
    glColor3f(1,1,1);

    for(int i=-50; i < 50; i++) {
        glBegin(GL_LINES);
        glVertex3f(i, 0, -50);
        glVertex3f(i, 0, 50);
        glEnd();
    }

    for(int i=-50; i < 50; i++) {
        glBegin(GL_LINES);
        glVertex3f(-50, 0, i);
        glVertex3f(50, 0, i);
        glEnd();
    }

    glPopMatrix();
}


void cursor(void){
  float vec[3];
  float pos[3];
  g_camera.GetDirectionVector(vec[0],vec[1],vec[2]);
  g_camera.GetPos(pos[0],pos[1],pos[2]);
  glLineWidth(2);

  glPushMatrix();

  glTranslatef(pos[0]+vec[0],pos[1]+vec[1],pos[2]+vec[2]);
  glRotatef(g_camera.GetYaw()*180/M_PI,0,-1,0);
  glRotatef(g_camera.GetPitch()*180/M_PI,0,0,1);

  glColor3f(1,0,0);

  glBegin(GL_LINES);
  glVertex3f(0,0,0.05);
  glVertex3f(0,0,0.02);

  glVertex3f(0,0,-0.05);
  glVertex3f(0,0,-0.02);

  glVertex3f(0,0.05,0);
  glVertex3f(0,0.02,0);

  glVertex3f(0,-0.05,0);
  glVertex3f(0,-0.02,0);

  glEnd();

  glPopMatrix();
  glLineWidth(1);
}

void Display (void) {
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();

    g_camera.Refresh();

    glColor3f(0,1,0);

    glutWireTeapot(0.5);

    cursor();

    Grid();

    glutSwapBuffers(); //swap the buffers
}

void Reshape (int w, int h) {
    g_viewport_width = w;
    g_viewport_height = h;

    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0 , 100.0); //set the perspective (angle of sight, width, height, ,depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void Keyboard(unsigned char key, int x, int y)
{
    if(key == 27) {
        exit(0);
    }

    if(key == ' ') {
        g_fps_mode = !g_fps_mode;

        if(g_fps_mode) {
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(g_viewport_width/2, g_viewport_height/2);
        }
        else {
            //hace aparecer el cursor
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }

    if(glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
        g_shift_down = true;
    }
    else {
        g_shift_down = false;
    }

    g_key[key] = true;
}

void KeyboardUp(unsigned char key, int x, int y)
{
    g_key[key] = false;
}

void Timer(int value)
{
    if(g_fps_mode) {
        if(g_key['w'] || g_key['W']) {
            g_camera.Move(g_translation_speed);
        }
        if(g_key['s'] || g_key['S']) {
            g_camera.Move(-g_translation_speed);
        }
        if(g_key['a'] || g_key['A']) {
            g_camera.Strafe(g_translation_speed);
        }
        if(g_key['d'] || g_key['D']) {
            g_camera.Strafe(-g_translation_speed);
        }
        if(g_mouse_left_down) {
            g_camera.Fly(-g_translation_speed);
        }
        if(g_mouse_right_down) {
            g_camera.Fly(g_translation_speed);
        }
    }

    glutTimerFunc(1, Timer, 0);
}

void Idle()
{
    Display();
}

void Mouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = true;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = true;
        }
    }
    else if(state == GLUT_UP) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = false;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = false;
        }
    }
}

void MouseMotion(int x, int y)
{
    // This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
    // This avoids it being called recursively and hanging up the event loop
    static bool just_warped = false;

    if(just_warped) {
        just_warped = false;
        return;
    }

    if(g_fps_mode) {
        int dx = x - g_viewport_width/2;
        int dy =g_viewport_height/2 - y;

        if(dx) {
            g_camera.RotateYaw(g_rotation_speed*dx);
        }

        if(dy) {
            g_camera.RotatePitch(g_rotation_speed*dy);
        }

        glutWarpPointer(g_viewport_width/2, g_viewport_height/2);

        just_warped = true;
    }
}
