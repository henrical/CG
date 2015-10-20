#include <iostream>

#include "CollisionBox.h"
#include "GL\glut.h"

CollisionBox::CollisionBox(float xm, float ym, float xM, float yM)
	:xMin(xm), yMin(ym), xMax(xM), yMax(yM) {}

CollisionBox::CollisionBox(){

}

CollisionBox::~CollisionBox(){

}

void CollisionBox::setCordinates(float xm, float ym, float xM, float yM){
	xMin = xm;
	yMin = ym;
	xMax = xM;
	yMax = yM;
}

float CollisionBox::getXMin(){
	return xMin;
}

float CollisionBox::getYMin(){
	return yMin;
}

float CollisionBox::getXMax(){
	return xMax;
}

float CollisionBox::getYMax(){
	return yMax;
}

void CollisionBox::draw()
{
	//float width = xMax - xMin;
	//float height = yMax - yMin; //pode ser negativo?

	glPushMatrix();

	glColor3f(1,0,0); //RED

	//glTranslatef(xMin, yMin, 0);
	//
	//glScalef(1, height / width, 0.3); //divisoes por zero?

	//glutSolidCube(width);

	glBegin(GL_POLYGON);
	glVertex3f(xMin,yMin,0);
	glVertex3f(xMax, yMin, 0);
	glVertex3f(xMax, yMax, 0);
	glVertex3f(xMin, yMax, 0);
	glEnd();

	glPopMatrix();
}
