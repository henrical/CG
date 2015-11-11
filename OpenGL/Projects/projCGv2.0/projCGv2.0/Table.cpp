#include "generic.h"
#include "Table.h"
#include "GL/Glut.h"

void Table::draw(){
	glPushMatrix();
	//glColor3f(0.81960784, 0.8, 1);
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();
	//glTranslatef(0.0, 0.0, -1.5);

	//glutSolidCube(3);
	GLfloat ambi[] = { 0.5, 0.5, 1.0, 1.f };
	GLfloat diff[] = { 0.0, 0.3, 0.74, 1.f };
	GLfloat spec[] = { 0.6, 0.8, 0.6, 1.f };
	glColor3f(0.5, 0.78, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1);
	glVertex3f(-1.5, -1.5, 0.0);
	glVertex3f(-1.5, 1.5, 0.0);
	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(1.5, -1.5, 0.0);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}