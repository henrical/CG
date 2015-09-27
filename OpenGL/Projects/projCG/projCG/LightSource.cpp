#include <iostream>

#include "LightSource.h"
#include "Vector3.h"

LightSource::LightSource(){

}

LightSource::LightSource(int mode){

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