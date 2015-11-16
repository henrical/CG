#include <iostream>

#include "Headlight.h"
#include "GL\glut.h"

Headlight::Headlight()
{
	_state = false;
}

Headlight::Headlight(int light_num, double x, double y, double z)
	:LightSource(x, y, 0.05), num(light_num)
{
	_state = false;
}

void Headlight::update(double x, double y, double z)
{
	_position->set(x, y, 0.05);
}

void Headlight::draw(){



	float xPos = _position->getX();
	float yPos = _position->getY();

	//GLUquadric*  quad = gluNewQuadric();

	glPushMatrix();
	glTranslatef(xPos, yPos, 0.01);



	GLfloat ambient[] = { HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, 1.0 };
	GLfloat diffuse[] = { HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, 1.0 };
	GLfloat specular[] = { HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, 1.0 };
	GLfloat position[] = { _position->getX(), _position->getY(), 0.0 };
	GLfloat direction[] = { 0.0, 1.0, 0.5 };



	if (_state){
		switch (num)
		{
		case LIGHT6:
			glEnable(GL_LIGHT6);
			glLightfv(GL_LIGHT6, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT6, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT6, GL_POSITION, direction);
			break;
		case LIGHT7:
			break;
		}
	}
	else{

	}
}