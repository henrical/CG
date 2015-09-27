#include <iostream>

#include "DynamicObject.h"

void DynamicObject::update(double delta_t)
{

}


void DynamicObject::setSpeed(const Vector3 &vector)
{
	this->_speed = vector;
}

Vector3 DynamicObject::getSpeed()
{
	if (_speed.nullp())
		std::cout << "WARNING: Tried to get DynamicObject's speed, but speed has not been initialized yet" << std::endl;
	
	return _speed;
}

void DynamicObject::setSpeed(double x, double y, double z)
{
	this->_speed = Vector3(x, y, z);
}