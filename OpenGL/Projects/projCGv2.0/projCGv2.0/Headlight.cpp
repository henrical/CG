#include <iostream>

#include "Headlight.h"
#include "GL\glut.h"

Headlight::Headlight()
{
	_state = true;
}

Headlight::Headlight(int light_num, double x, double y, double z)
	:LightSource(x, y, 0.05), num(light_num)
{
	_state = true;
}

void Headlight::update(double x, double y, double z)
{
	_position->set(x, y, 0.05);
}

void Headlight::draw(){


	float xPos = _position->getX();
	float yPos = _position->getY();

	//GLUquadric*  quad = gluNewQuadric();

	glMatrixMode(GL_MODELVIEW);

	/*glPushMatrix();
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xPos, yPos, 0.5);
	glVertex3f(xPos - 0.02, yPos, 0.5);
	glVertex3f(xPos - 0.02, yPos + 0.16, 0.5);
	glVertex3f(xPos , yPos + 0.16, 0.5);
	glEnd();
	glPopMatrix();*/
	

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(xPos, yPos, 0.01);
	glutSolidCube(0.1);
	glPopMatrix();
	

	GLfloat ambient[] = { HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, 1.0 };
	GLfloat diffuse[] = { HEADLIGHT_INTENSITY_DIF, HEADLIGHT_INTENSITY_DIF, HEADLIGHT_INTENSITY_DIF, 1.0 };
	GLfloat specular[] = { HEADLIGHT_INTENSITY_SPEC, HEADLIGHT_INTENSITY_SPEC, HEADLIGHT_INTENSITY_SPEC, 1.0 };
	GLfloat position[] = {xPos, yPos, 0.05, 1};
	GLfloat direction1[] = { -0.06, 1, -0.1 };
	GLfloat direction2[] = { 0.06, 1, -0.1 };

	

	if (_state){
		switch (num)
		{
		case LIGHT6:
			glEnable(GL_LIGHT6);
			glLightfv(GL_LIGHT6, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT6, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT6, GL_POSITION, position);
			glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, direction1);
			glLightiv(GL_LIGHT6, GL_SPOT_CUTOFF, &spot_cutoff);
			glLightiv(GL_LIGHT6, GL_SPOT_EXPONENT, &spot_exponent);
			break;
		case LIGHT7:
			glEnable(GL_LIGHT7);
			glLightfv(GL_LIGHT7, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT7, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT7, GL_POSITION, position);
			glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, direction2);
			glLightiv(GL_LIGHT7, GL_SPOT_CUTOFF, &spot_cutoff);
			glLightiv(GL_LIGHT7, GL_SPOT_EXPONENT, &spot_exponent);
			break;
		}
	}
	else {
		
	}
}