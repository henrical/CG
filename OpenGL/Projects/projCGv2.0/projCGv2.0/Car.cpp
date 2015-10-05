#include <iostream>

#include "GL/glut.h"
#include "generic.h"

#include "Car.h"

void Car::draw()
{	
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(0, 0, 0, 0);
	glScalef(0.1, 0.1, 0.1);

	//frente
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-0.5, 0, 0.35);
	glScalef(1.0, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//traseira
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.5, 0, 0.6);
	glScalef(1.0, 1.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//roda fronteira esquerda
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(-0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda fronteira direita
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(-0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira direita
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira esquerda
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	glPopMatrix();
};