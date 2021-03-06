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

	destroyed = false;

}

Orange::~Orange()
{

}

void Orange::draw()
{
	glPushMatrix();
	//glColor3f(OR_COLOR_R, OR_COLOR_G, OR_COLOR_B);
	GLfloat ambi[] = { 1.0, 0.5, 0.0, 1.f };
	GLfloat diff[] = { 0.7, 0.5, 0.0, 1.f };
	GLfloat spec[] = { 0.7, 0.5, 0.0, 1.f };
	glColor3f(1.0, 0.5, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);

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

bool Orange::destroyedp(){
	return destroyed;
}

void Orange::destroy(){
	destroyed = true;
}

void Orange::update(int dt){
	_position->set(_position->getX() + getSpeed()->getX() * dt * direction->getX(), _position->getY() + getSpeed()->getY() * dt * direction->getY(), 0);
}