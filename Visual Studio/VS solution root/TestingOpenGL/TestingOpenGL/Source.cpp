#include <iostream>
#include <GL/glut.h>


int main(int argc, char** argv)
{
	//GLbyte* c = new GLbyte();

	GLfloat* c = new GLfloat();

	glGetFloatv(GL_CURRENT_COLOR, c);

	std::cerr << c << std::endl;

	std::getchar();

	return 0;

}