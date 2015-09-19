#include <iostream>
#include <GL/glut.h>
#include <Windows.h>

void display()
{
	//Set clearing value.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Clear screen.
	glClear(GL_COLOR_BUFFER_BIT);

	//Set Color. 1 = 255. 
	//(1,1,1) = white.
	glColor3f(1.0f, 1.0f, 1.0f);

	//Draw a square.
	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glFlush();
}

void reshape(int h, int w)
{
	GLdouble top, right, bottom, left, near_val, far_val;
	top = right = GLdouble(-2.0f);
	bottom = left = GLdouble(2.0f);
	near_val = GLdouble(-2.0f), far_val = GLdouble(2.0f);

	glViewport(10, 10, h, w);

	//Pushes Projection matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Define projection.
	glOrtho(left, right, bottom, top, near_val, far_val);
	
	//Pushes Model-View matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

int main(int argc, char** argv)
{

	int window;
	//int width = 0, height = 0;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(300, 300);

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