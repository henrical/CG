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

int* CollisionBox::getCordinates(){
	int* result = (int*)malloc(4*sizeof(int));

	result[0] = xMin;
	result[1] = yMin;
	result[2] = xMax;
	result[3] = yMax;

	return result;
}

void CollisionBox::draw()
{
	float width = xMax - xMin;
	float height = yMax - yMin; //pode ser negativo?

	glPushMatrix();

	glColor3f(1,0,0); //RED

	glTranslatef(xMin, yMin, 0);
	
	glScalef(1, height / width, 0.3); //divisoes por zero?

	glutSolidCube(width);

	glPopMatrix();
}
