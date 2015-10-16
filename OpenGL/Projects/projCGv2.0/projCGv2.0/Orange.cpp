#include <iostream>
#include <string>

#include "Orange.h"
#include "GL\glut.h"

Orange::Orange(Vector3 *pos)
{
	_position->set(pos->getX(), pos->getY(), pos->getZ());
}

Orange::~Orange()
{

}

void Orange::draw()
{
	//std::cout << "-----> Drawing orange in " << _position->getX() << _position->getY() << _position->getZ() << std::endl;
	glPushMatrix();
	/*std::cout << this->toString();*/
	glColor3f(OR_COLOR_R, OR_COLOR_G, OR_COLOR_B);

	GLUquadric *quad = gluNewQuadric();

	glPushMatrix();

	glTranslated(_position->getX(), _position->getY(), ORANGE_RADIUS);

	gluSphere(quad,ORANGE_RADIUS,50,50);


	glPopMatrix();
	glPopMatrix();
}