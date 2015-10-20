#include <iostream>

#include "DynamicObject.h"

void DynamicObject::update(double delta_t)
{

}

void DynamicObject::draw(){

}

void DynamicObject::setSpeed(Vector3 *vector)
{
	this->_speed = vector;
}

Vector3* DynamicObject::getSpeed()
{
	if (_speed->nullp())
		std::cout << "WARNING: Tried to get DynamicObject's speed, but speed has not been initialized yet" << std::endl;
	
	return _speed;
}

Vector3* DynamicObject::getAcc(){
	return acc;
}

void DynamicObject::setAcc(double x, double y, double z){
	acc->set(x, y, z);
}

void DynamicObject::setSpeed(double x, double y, double z)
{
	this->_speed = new Vector3(x, y, z);
}