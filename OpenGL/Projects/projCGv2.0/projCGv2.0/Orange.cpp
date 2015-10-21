#include <iostream>
#include <string>
#include <iomanip>

#include "Orange.h"
#include "GL\glut.h"
#include "GameManager.h"

Orange::Orange(Vector3 *pos)
{
	_position->set(pos->getX(), pos->getY(), pos->getZ());

	bbox = CollisionBox(_position->getX() - ORANGE_RADIUS, _position->getY() - ORANGE_RADIUS, _position->getX() + ORANGE_RADIUS, _position->getY() + ORANGE_RADIUS);
	hasCollision = false;

}

Orange::~Orange()
{

}

void Orange::draw()
{
	glPushMatrix();
	glColor3f(OR_COLOR_R, OR_COLOR_G, OR_COLOR_B);

	GLUquadric *quad = gluNewQuadric();

	glPushMatrix();

	glTranslated(_position->getX(), _position->getY(), ORANGE_RADIUS);

	gluSphere(quad,ORANGE_RADIUS,50,50);

	glPopMatrix();
	glPopMatrix();

	bbox.setCordinates(_position->getX() - ORANGE_RADIUS, _position->getY() - ORANGE_RADIUS, _position->getX() + ORANGE_RADIUS, _position->getY() + ORANGE_RADIUS);

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();

	
}