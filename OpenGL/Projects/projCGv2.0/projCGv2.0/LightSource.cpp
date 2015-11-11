#include <iostream>

#include "LightSource.h"
#include "Vector3.h"

LightSource::LightSource(){

}

LightSource::LightSource(double x, double y, double z){
	_state = false;
	_position = new Vector3(x, y, z);
}

bool LightSource::getState()
{
	return this->_state;
}

bool LightSource::setState(bool new_state)
{
	return this->_state = new_state;
}

GLenum LightSource::getNum()
{
	return _num;
}

void LightSource::setCutOff(double cut_off)
{
	this->_cutOff = cut_off;
}

void LightSource::setExponent(double exponent)
{
	this->_exponent = exponent;
}

void LightSource::setDirection(const Vector3 &vector){
	_direction = vector;
}

void LightSource::draw(){
	if (_state){
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
		GLfloat ambient[] = { 0.3, 0.3, 0.3, 1.0 };
		GLfloat diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat position[] = { _position->getX(), _position->getY(), _position->getZ(), 0.0 };
		GLfloat direction[] = {0.0, 0.0, -1.0};
	
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	}
	else{
		glDisable(GL_LIGHT0);
	}
}