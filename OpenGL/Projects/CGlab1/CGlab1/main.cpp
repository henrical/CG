#include <iostream>
#include <GL/glut.h>
#include <Windows.h>

/* ALTERNATIVA*/
//void display()
//{
//	//Set clearing value.
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	//Clear screen.
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//Set Color. 1 = 255. 
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	//Draw a square.
//	glBegin(GL_POLYGON);
//	glVertex3f(0.0f, 1.0f, 0.0f);
//	glVertex3f(-1.0f, 1.0f, 0.0f);
//	glVertex3f(-1.0f, -1.0f, 0.0f);
//	glVertex3f(0.0f, -1.0f, 0.0f);
//
//
//	glColor3f(0.0f, 1.0f, 0.0f);
//
//	glVertex3f(0.0f, -1.0f, 0.0f);
//	glVertex3f(1.0f, -1.0f, 0.0f);
//	glVertex3f(1.0f, 1.0f, 0.0f);
//	glVertex3f(0.0f, 1.0f, 0.0f);
//
//
//	glEnd();
//
//	glFlush();
//}


void printWindowAspect(float aspect, float delta)
{
	std::cerr << "Aspect: " << aspect << std::endl << "Delta: " << delta << std::endl;
	std::cerr << "================================" << std::endl;
}

void display()
{
	//Set clearing value.
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	//Clear screen.
	glClear(GL_COLOR_BUFFER_BIT);

	//Set Color. 1 = 255. 
	//RED.
	glColor3f(0.0f, 0.0f, 0.0f);

	//Draw a square.
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();

	//GREEN
	/*glColor3f(0.0f, 1.0f, 0.0f);*/

	/*glBegin(GL_POLYGON);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();*/


	glFlush();
}

 /** 
 **	 'h' and 'w' is the height and width 
 **  of the openGL window.
 **  They are updated everytime the window
 **  is resized. 
 */
void reshape(int h, int w)
{
	float top, right, bottom, left ;
	float delta;

	left = 2., right = -2., bottom = 2., top = -2.;

	// Width Height Ratio
	float wh_ratio = (right-left) - (top-bottom); // ratio = 0
	
	// Aspect ratio of the window
	float aspect = (float)w / h;
	
	//std::cerr << aspect << std::endl;

	// Set Viewport: start at (0,0)
	// and size of the whole window
	glViewport(0, 0, w, h);

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
		printWindowAspect(aspect, delta);

		gluOrtho2D(left - delta, right + delta, bottom, top);

	} else {

		delta = ((top - bottom) / aspect - (right - left)) / 2;
		printWindowAspect(aspect, delta);

		gluOrtho2D(left, right , bottom - delta, top + delta);
	}


	gluOrtho2D(left, right, bottom, top);

}

int main(int argc, char** argv)
{

	int window;
	//int width = 0, height = 0;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(600, 600);

	glutInitWindowPosition(0, 0);

	window = glutCreateWindow("Teste");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	//GLbyte* c = new GLbyte();

	//GLfloat* c = new GLfloat();

	//glGetFloatv(GL_CURRENT_COLOR, c);

	//std::cerr << c << std::endl;

	//std::getchar();

	return 0;

}