#!

# This is statement is required by the build system to query build info
if __name__ == '__build__':
	raise Exception

import string
__version__ = string.split('$Revision: 1.1.1.1 $')[1]
__date__ = string.join(string.split('$Date: 2007/02/15 19:25:21 $')[1:3], ' ')
__author__ = '<Modificado por: --------------->'


#
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import sys

# Some api in the chain is translating the keystrokes to this octal string
# so instead of saying: ESCAPE = 27, we use the following.
ESCAPE = '\033'

# Number of the glut window.
window = 0

trimove = -0.5
cuadmove= 0.5

# A general OpenGL initialization function.  Sets all of the initial parameters. 
def InitGL(Width, Height):				# We call this right after our OpenGL window is created.
    glClearColor(0.0, 0.0, 0.0, 0.0)	# This Will Clear The Background Color To Black
    glClearDepth(1.0)					# Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS)				# The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST)				# Enables Depth Testing
    glShadeModel(GL_SMOOTH)				# Enables Smooth Color Shading
	
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()					# Reset The Projection Matrix
										# Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0, float(Width)/float(Height), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)

# The function called when our window is resized (which shouldn't happen if you enable fullscreen, below)
def ReSizeGLScene(Width, Height):
    if Height == 0:						# Prevent A Divide By Zero If The Window Is Too Small 
	    Height = 1

    glViewport(0, 0, Width, Height)		# Reset The Current Viewport And Perspective Transformation
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    global c
    gluPerspective(45.0, float(Width)/float(Height), 0.1, 100.0)
    glMatrixMode(GL_MODELVIEW)
    
cuad = 0
tri = 0
x=0
y=0
z=0
# The main drawing function. 
def DrawGLScene():
	
	# Clear The Screen And The Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glLoadIdentity()					# Reset The View 
	
	global tri,x,y,z
	
	tri = (tri+3)%360

	# Move Left 1.5 units and into the screen 6.0 units.

	# Since we have smooth color mode on, this will be great for the Phish Heads :-).
	# Draw a triangle
	glPushMatrix();
	glTranslatef(-1.5+x, 0.0+y, -6.0+z)
	glRotatef(tri, 0.0, 1.0, 0.0)
	

	glBegin(GL_POLYGON)                 
	glColor3f(1.0, 0.0, 0.0)            
	glVertex3f(0.0, 0.7, 0.0)           
	glVertex3f(0.7, 0.0, 0.0)          
	glVertex3f(-0.7, 0.0, 0.0)         
	glEnd()            
	
	glBegin(GL_POLYGON)
	                
	glColor3f(0.7, 0.0, 0.0)
	glVertex3f(0.0, 0.0, 0.7)           
	glVertex3f(0.0, -0.0, -0.7)          
	glVertex3f(0.0, 0.7, 0.0)         
	
	
	glEnd()                             # We are done with the polygon
	glPopMatrix();
	
	glPushMatrix();
	

	glTranslatef(-1.5+x, 0.0+y, -6.0+z)
	# Draw a square (quadrilateral)
	glColor3f(0.0, 0.5, 1.0)            # Bluish shade
	glBegin(GL_POLYGON)                   # Start drawing a 4 sided polygon          # Bottom Right
	glVertex3f(0.0,0.0,0.0)         # Bottom Left
	glVertex3f(0.8,-0.32,0.0)
	glVertex3f(0.8,-1.0,0.0)
	glVertex3f(-0.8,-1.0,0.0)
	glVertex3f(-0.8,-0.32,0.0)
	
	
	glEnd()                             # We are done with the polygon
	glPopMatrix();

	#  since this is double buffered, swap the buffers to display what just got drawn. 
	glutSwapBuffers()
	

# The function called whenever a key is pressed. Note the use of Python tuples to pass in: (key, x, y)  
def keyPressed(*args):
	global x,y,z,c
	if args[0] == ESCAPE:
		sys.exit()
	if args[0] == 'a':
		x-=1
	if args[0] == 'w':
		z-=1
	if args[0] == 's':
		z+=1
	if args[0] == 'd':
		x+=1
	if args[0] == 'u':
		y+=0.5
	if args[0] == 'i':
		y-=0.5
	
def main():
	global window
	# For now we just pass glutInit one empty argument. I wasn't sure what should or could be passed in (tuple, list, ...)
	# Once I find out the right stuff based on reading the PyOpenGL source-, I'll address this.
	glutInit(sys.argv)

	# Select type of Display mode:   
	#  Double buffer 
	#  RGBA color
	# Alpha components supported 
	# Depth buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)
	
	# get a 640 x 480 window 
	glutInitWindowSize(640, 480)
	
	# the window starts at the upper left corner of the screen 
	glutInitWindowPosition(0, 0)

	window = glutCreateWindow("Practica semana 4 - transformaciones")

   	# Register the drawing function with glut, BUT in Python land, at least using PyOpenGL, we need to
	# set the function pointer and invoke a function to actually register the callback, otherwise it
	# would be very much like the C version of the code.	
	glutDisplayFunc(DrawGLScene)
	
	# Uncomment this line to get full screen.
	#glutFullScreen()

	# When we are doing nothing, redraw the scene.
	glutIdleFunc(DrawGLScene)
	
	# Register the function called when our window is resized.
	glutReshapeFunc(ReSizeGLScene)
	
	# Register the function called when the keyboard is pressed.  
	glutKeyboardFunc(keyPressed)

	# Initialize our window. 
	InitGL(640, 480)

	# Start Event Processing Engine	
	glutMainLoop()

# Print message to console, and kick off the main to get it rolling.
print "Hit ESC key to quit."
main()
