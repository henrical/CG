#include <iostream>

#include "Headlight.h"
#include "GL\glut.h"

Headlight::Headlight()
{
	_state = true;
	dir_x = 0;
	dir_y = 1;
}

Headlight::Headlight(int light_num, double x, double y, double z)
	:LightSource(x, y, 0.05), num(light_num)
{
	_state = true;
}

void Headlight::update(double x, double y, double z, double dir_x, double dir_y)
{
	_position->set(x, y, 0.0);
	this->dir_x = dir_x;
	this->dir_y = dir_y;
}

void Headlight::draw(){

	float xPos = _position->getX();
	float yPos = _position->getY();

	float const_aten = 0;
	float linear_aten = 0;
	float quad_aten = 100;

	GLfloat ambient[] = { HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, HEADLIGHT_INTENSITY, 1.0 };
	GLfloat diffuse[] = { HEADLIGHT_INTENSITY_DIF, HEADLIGHT_INTENSITY_DIF, HEADLIGHT_INTENSITY_DIF, 1.0 };
	GLfloat specular[] = { HEADLIGHT_INTENSITY_SPEC, HEADLIGHT_INTENSITY_SPEC, HEADLIGHT_INTENSITY_SPEC, 1.0 };
	GLfloat position[] = {xPos, yPos, 0.05, 1};
	GLfloat direction1[] = { dir_x - 0.03, dir_y, -0.1};
	GLfloat direction2[] = { dir_x + 0.03, dir_y, -0.1};
	

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

			glLightfv(GL_LIGHT6, GL_CONSTANT_ATTENUATION, &const_aten);
			glLightfv(GL_LIGHT6, GL_LINEAR_ATTENUATION, &linear_aten);
			glLightfv(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, &quad_aten);
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

			glLightfv(GL_LIGHT6, GL_CONSTANT_ATTENUATION, &const_aten);
			glLightfv(GL_LIGHT6, GL_LINEAR_ATTENUATION, &linear_aten);
			glLightfv(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, &quad_aten);
			break;
		}
	}
	else {
		
	}
}