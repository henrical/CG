#include <iostream>
#include <string>
#include <sstream>

#include "Entity.h"
#include "Vector3.h"

Vector3* Entity::getPosition(){
	return this->_position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	this->_position = new Vector3(x, y, z);
	
	return this->_position;
}

Vector3* Entity::setPosition(const Vector3 &vector){
	this->_position = new Vector3(vector.getX(), vector.getY(), vector.getZ());

	return this->_position;
}

std::string Entity::toString(){
	std::ostringstream convert;

	convert << "Entity at position: " << this->_position->toString();

	return convert.str();
}