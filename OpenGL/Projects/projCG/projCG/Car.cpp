#include <iostream>

#include "GL/glut.h"
#include "generic.h"

#include "Car.h"

void Car::draw()
{
	//desenho da parte de tras do carro
	glColor3f(changeScale(140), changeScale(226), changeScale(255));
	glutSolidCube(0.1);

	//desenho da parte da frente do carro
	glColor3f(0, changeScale(191), changeScale(255));
	glTranslatef(0, -0.09, 0);
	glutSolidCube(0.08);

	//desenho da roda da frente direita.
	glTranslatef(-0.04, 0, 0);
	glRotatef(90, 0, 1, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(0.006, 0.015, 50, 50);

	glLoadIdentity();

	//desenho da roda da frente esquerda.
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.1,0,0);
	glutSolidTorus(0.006,0.015,50, 50);


};