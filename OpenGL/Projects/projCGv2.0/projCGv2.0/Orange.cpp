#include <iostream>
#include <string>

#include "Orange.h"
#include "GL\glut.h"

Orange::Orange(Vector3 *pos)
{
	_position = pos;
}

Orange::~Orange()
{

}

void Orange::draw()
{
	/*std::cout << this->toString();*/
	glColor3f(OR_COLOR_R, OR_COLOR_G, OR_COLOR_B);

	GLUquadric *quad = gluNewQuadric();

	glPushMatrix();

	glTranslated(_position->getX(), _position->getY(), _position->getZ());

	gluSphere(quad,ORANGE_RADIUS,50,50);


	glPopMatrix();
}