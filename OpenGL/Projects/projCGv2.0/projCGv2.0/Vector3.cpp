#include <iostream>
#include <sstream>

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z){
	this->_x = x;
	this->_y = y;
	this->_z = z;

	this->isNull = false;
}

Vector3::Vector3(){
	this->isNull = true;

}

Vector3::~Vector3(){
}

double Vector3::getX() const{
	return this->_x;
}

double Vector3::getY() const{
	return this->_y;
}

double Vector3::getZ() const{
	return this->_z;
}

void Vector3::set(double x, double y, double z){
	this->_x = x;
	this->_y = y;
	this->_z = z;

	this->isNull = false;
}

std::string Vector3::toString(){
	std::ostringstream convert;

	convert << "(" << this->getX();
	convert << ", " << this->getY();
	convert << ", " << this->getZ() << ")." << std::endl;

	return convert.str();
}

bool Vector3::nullp(){
	return isNull;
}
