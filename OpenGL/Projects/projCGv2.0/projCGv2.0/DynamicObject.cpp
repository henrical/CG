#include <iostream>

#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
	direction = new Vector3();
	_speed = new Vector3();
	acc = new Vector3();
}

void DynamicObject::setDirection(){
	double y;
	double x;
	double angulo = angle - (3.14159 / 2);

	/*std::cout << "Direction before turn: [" << direction->getX() << ", " << direction->getY() << "]" << std::endl;*/
	
	double dir = -1 *  sqrt(direction->getX() * direction->getX() + direction->getY() * direction->getY());
	/*std::cout << "Angle turn: " <<  angulo << std::endl;*/

	y = dir*sin(angulo /** 3.14159 / 180*/);
	x = dir*cos(angulo /** 3.14159 / 180*/);

	std::cout << sin(x) << ", " << sin(y) << std::endl;
	//normalizar
	direction->set(x / sqrt(x*x + y*y), y / sqrt(x*x + y*y), 0);

	/*std::cout << "(Sin,Cos) = [" << sin(angulo) << ", " << cos(angulo) << "]" << std::endl;*/

	/*std::cout << "Direction after turn: [" << direction->getX() << ", " << direction->getY() << "]" << std::endl;*/
}

void DynamicObject::setDirection(double x, double y, double z){
	this->direction->set(x, y, z);
}

void DynamicObject::update(double delta_t)
{

}

void DynamicObject::draw(){

}


double DynamicObject::getAngle()
{	
	return this->angle;
}

void DynamicObject::setAngle(double val)
{
	this->angle = val;
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

void DynamicObject::triggerCollision(){
	hasCollision = true;
}

bool DynamicObject::hasCollisionp(){
	return hasCollision;
}

bool DynamicObject::hasJustCollidedp(){
	return justCollided;
}

Vector3 DynamicObject::getDirection(){
	return *direction;
}