#include <iostream>

#include "GL\glut.h"

#define CAMERA2_EYE_X 0
#define CAMERA2_EYE_Y -2.5
#define CAMERA2_EYE_Z 1.5

#define CAMERA2_CENTER_X 0
#define CAMERA2_CENTER_Y 0
#define CAMERA2_CENTER_Z 0

#define CAMERA2_UP_X 0
#define CAMERA2_UP_Y 1
#define CAMERA2_UP_Z 0

#define FOVY 90
#define ZNEAR 0
#define ZFAR 15

#define VIEWPORT_X 800
#define VIEWPORT_Y 700

#define ASPECT_RATIO (float)VIEWPORT_X/VIEWPORT_Y

void myReshape(int h, int w)
{
	float top, right, bottom, left;
	float delta;

	left = 2., right = -2., bottom = 2., top = -2.;

	// Width Height Ratio
	float wh_ratio = (right - left) - (top - bottom); // ratio = 0

	// Aspect ratio of the window
	float aspect = (float)VIEWPORT_X / VIEWPORT_Y;

	//std::cerr << aspect << std::endl;

	// Set Viewport: start at (0,0)
	// and size of the whole window
	glViewport(0, 0, VIEWPORT_X, VIEWPORT_Y);

	//Pushes Projection matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Pushes Model-View matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Define  ortho projection.
	// Allow window resizing.
	if (aspect > wh_ratio)
	{
		delta = ((top - bottom) * aspect - (right - left)) / 2;

		gluOrtho2D(left - delta, right + delta, bottom, top);

	}
	else {

		delta = ((top - bottom) / aspect - (right - left)) / 2;

		gluOrtho2D(left, right, bottom - delta, top + delta);
	}


	gluOrtho2D(left, right, bottom, top);

}

void myDisplay()
{
	

	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOVY, ASPECT_RATIO, ZNEAR, ZFAR);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(CAMERA2_EYE_X, CAMERA2_EYE_Y, CAMERA2_EYE_Z, CAMERA2_CENTER_X, CAMERA2_CENTER_Y, CAMERA2_CENTER_Z, CAMERA2_UP_X, CAMERA2_UP_Y, CAMERA2_UP_Z);*/

	//Set clearing value.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	/*Clear screen.*/
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);


	//Draw a square.
	/*glutSolidCube(1);*/
	glBegin(GL_QUADS);
	//glNormal3f(0, 0, 1);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	int window;
	/*PerspectiveCamera *cam2 = new PerspectiveCamera(FOVY, ASPECT_RATIO, ZNEAR, ZFAR, FIXED_PERSPECTIVE_CAM);*/
	

	glutInit(&argc, argv);

	glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(800, 700);

	glutInitWindowPosition(-1, -1);

	window = glutCreateWindow("Teste de iluminação.");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);


	GLfloat amb[] = { 0.2f, 0.2f, 0.2f, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	GLfloat position[] = { 1, 1, -0.5, 1.0 };
	GLfloat directional[] = { -1.0, -1.0, 0.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	//glLightfv(GL_LIGHT1, GL_POSITION, directional);


	//###################################################
	GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_diffuse[] = { 0.6, 0.6, 0.0, 1.0 };
	GLfloat mat_specular[] = { 1, 1, 1, 1.0 };
	GLfloat mat_emission[] = { 0, 0, 0 , 1.0 };
	GLfloat mat_shine = 100.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shine);
	//############################################################



	glutMainLoop();

	return 0;
}