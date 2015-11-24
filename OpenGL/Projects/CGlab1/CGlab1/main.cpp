#include <iostream>
#include <GL/glut.h>
#include <Windows.h>
#include "SOIL.h"

GLuint textures[1];

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

void loadBMP(){
	
	//glEnable(GL_TEXTURE_2D);

	glGenTextures(1, &textures[0]);

	textures[0] = SOIL_load_OGL_texture
		(
		"stones.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (0 == textures[0])
	{
		std::cout << "SOIL loading error: " << SOIL_last_result() << std::endl;
	}

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


}

void display()
{
	//Set clearing value.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Clear screen.
	glClear(GL_COLOR_BUFFER_BIT);

	//Set Color. 1 = 255. 
	//RED.
	//glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	//Draw a square.
	glBegin(GL_POLYGON);
	
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glTexCoord2f(1, 0);
	glVertex3f(2.0f, 0.0f, 0.0f);

	glTexCoord2f(1, 1);
	glVertex3f(2.0f, 2.0f, 0.0f);

	glTexCoord2f(0, 1);
	glVertex3f(0.0f, 2.0f, 0.0f);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	/*glTexCoord2f(0, 1);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(-1,1);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2f(0,0);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glTexCoord2f(0, 1);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();*/

	//GREEN
	//glColor3f(0.0f, 1.0f, 0.0f);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glEnd();


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

	left = 3., right = -3., bottom = 3., top = -3.;

	// Width Height Ratio
	float wh_ratio = (right-left) - (top-bottom); // ratio = 0
	
	// Aspect ratio of the window
	float aspect = (float)w / h;
	
	//std::cerr << aspect << std::endl;

	// Set Viewport: start at (0,0)
	// and size of the whole window
	glViewport(0, 0, w/2, h/2);

	//Pushes Projection matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(left, right, bottom, top);

	glViewport(w/2, h/2, w , h );

	glPushMatrix();
	gluOrtho2D(left, right, bottom, top);
	glPopMatrix();
	//Pushes Model-View matrix to top of the stack.
	//Loads identity matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Define  ortho projection.
	// Allow window resizing.
	//if (aspect > wh_ratio)
	//{
	//	delta = ((top - bottom) * aspect - (right - left)) / 2;
	//	printWindowAspect(aspect, delta);

	//	gluOrtho2D(left - delta, right + delta, bottom, top);

	//} else {

	//	delta = ((top - bottom) / aspect - (right - left)) / 2;
	//	printWindowAspect(aspect, delta);

	//	gluOrtho2D(left, right , bottom - delta, top + delta);
	//}


	

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

	loadBMP();

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