#include <iostream>

#include "GL/glut.h"
#include "generic.h"

#include "Car.h"

Car::Car(){
	speed = new Vector3();
	_position->set(-1.1, 0, 0);
	speed->set(0, 0, 0);
	acc = new Vector3();
	acc->set(0, 0, 0);
	angle = -90;
	direction = new Vector3(0, 1, 0);
}

void Car::draw()
{	
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glRotatef(angle, 0, 0, 1);
	glScalef(0.1, 0.1, 0.1);

	//frente
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-0.5, 0, 0.35);
	glScalef(1.0, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//traseira
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.5, 0, 0.6);
	glScalef(1.0, 1.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//roda fronteira esquerda
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(-0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda fronteira direita
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(-0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira direita
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira esquerda
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	glPopMatrix();
}

void Car::setSpeed(double x, double y, double z){
	speed->set(x, y, z);
}

void Car::setAcc(double x, double y, double z){
	acc->set(x, y, z);
}

//void Car::slowDownAcceleration(double acceleration){
//	
//	if (getSpeed()->getX() > 0 && getSpeed()->getY() > 0)
//		acc->set(getAcc()->getX() - acceleration, getAcc()->getY() - acceleration, getAcc()->getZ() - acceleration);
//}
//
//void Car::slowDownSpeed(double speed){
//	
//	if (getSpeed()->getX() > 0 && getSpeed()->getY() > 0)
//		this->speed->set(getSpeed()->getX() - speed, getSpeed()->getY() - speed, getSpeed()->getZ() - speed);
//}

Vector3* Car::getSpeed(){
	return speed;
}

Vector3* Car::getAcc(){
	return acc;
}

void Car::setDirection(){
	double y;
	double x;
	y = direction->getY()*sin(angle * 3.14159 / 180);
	x = direction->getY()*cos(angle * 3.14159 / 180);
	//normalizar
	direction->set(x/sqrt(x*x + y*y), y/sqrt(x*x + y*y), 0);
}

void Car::rodaDireita(){
	angle -= 10;
	setDirection();
}

void Car::rodaEsquerda(){
	angle += 10;
	setDirection();
}

void Car::update(int dt){
	// speed = speed + acc*dt
	//pos = pos + speed*dt
	/*if (getSpeed()->getX() < MAXSPEED && getSpeed()->getX() >= 0){
		setSpeed(getSpeed()->getX() + getAcc()->getX()*dt, getSpeed()->getY(), getSpeed()->getZ());
	}
	else if (getSpeed()->getX() > -(MAXSPEED) && getSpeed()->getX() <= 0){
		setSpeed(getSpeed()->getX() + getAcc()->getX()*dt, getSpeed()->getY(), getSpeed()->getZ());
	}
	if (getSpeed()->getY() < MAXSPEED && getSpeed()->getY() >= 0){
		setSpeed(getSpeed()->getX(), getSpeed()->getY() + getAcc()->getY()*dt, getSpeed()->getZ());
	}
	else if (getSpeed()->getY() > -(MAXSPEED) && getSpeed()->getY() <= 0)
		setSpeed(getSpeed()->getX(), getSpeed()->getY() + getAcc()->getY()*dt, getSpeed()->getZ());*/
	speed->set(speed->getX() + getAcc()->getX() * dt, speed->getY() + getAcc()->getY() * dt, 0);
	_position->set(_position->getX() + getSpeed()->getX() * dt * direction->getX(), _position->getY() + getSpeed()->getY() * dt * direction->getY(), _position->getZ());
	
	
	//std::cout << "----->carro speed x=" << speed->getX() << " y=" << speed->getY() << " dir x=" << direction->getX() << " y="<< direction->getY() << std::endl;
}