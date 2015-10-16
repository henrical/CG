#include "generic.h"
#include "Table.h"
#include "GL/Glut.h"

void Table::draw(){
	glPushMatrix();
	glColor3f(0.81960784, 0.8, 1);
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.5);
	glutSolidCube(3);
	glPopMatrix();
	glPopMatrix();
}