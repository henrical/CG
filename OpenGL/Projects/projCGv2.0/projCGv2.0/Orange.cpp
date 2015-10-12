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

	glPushMatrix();

	glTranslated(_position->getX(), _position->getY(), _position->getZ());


	glPopMatrix();
}