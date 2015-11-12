#include <iostream>
#include <iomanip>

#include "GL/glut.h"
#include "generic.h"
#include "CollisionBox.h"
#include "Car.h"
#include "GameManager.h"


Car::Car(){
	_speed = new Vector3();
	_position->set(INIT_POS_X, INIT_POS_Y, INIT_POS_Z);
	_speed->set(0, 0, 0);
	acc = new Vector3();
	acc->set(0, 0, 0);
	angle = 0;
	direction = new Vector3(0, 1, 0);
	hasCollision = false;

	bbox = CollisionBox(INIT_POS_X - 0.06 , INIT_POS_Y - 0.06, INIT_POS_X + 0.45*CAR_BBOX_LENGTH, INIT_POS_Y + 0.45*CAR_BBOX_LENGTH);
}

void Car::draw()
{	
	float xPos, yPos;
	xPos = _position->getX();
	yPos = _position->getY();

	glPushMatrix();
	glTranslatef(xPos, yPos, 0);
	glRotatef((angle * 180 / 3.14159) - 90, 0, 0, 1);
	glScalef(CAR_SIZE, CAR_SIZE, CAR_SIZE);

	//cubo da frente
	GLfloat ambi[] = { 1.0, 0, 0.0, 1.f };
	GLfloat diff[] = { 1, 0.1, 0.0, 1.f };
	GLfloat spec[] = { 0, 0, 0, 1.f };
	glColor3f(1.0, 0.2, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glPushMatrix();

	glTranslatef(-0.5, 0, 0.35);
	glScalef(1.0, 1.0, 0.5);
	
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();

	glPopMatrix();

	//cubo traseiro
	GLfloat ambi2[] = { 1, 0.1, 0.1, 1.f };
	GLfloat diff2[] = { 1, 0.1, 0.1, 1.f };
	GLfloat spec2[] = { 0, 0, 0, 1.f };
	glColor3f(1.0, 0.1, 0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec2);
	glPushMatrix();

	glTranslatef(0.5, 0, 0.6);
	glScalef(1.0, 1.0, 1.0);
	
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();

	glPopMatrix();

	//roda fronteira esquerda
	GLfloat ambi3[] = { 0.02, 0.02, 0.02, 1.f };
	GLfloat diff3[] = { 0.01, 0.01, 0.01, 1.f };
	GLfloat spec3[] = { 0.04, 0.04, 0.04, 1.f };
	glColor3f(0.3, 0.3, 0.3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec3);

	glPushMatrix();
	glTranslatef(-0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);

	glutSolidTorus(0.5, 0.6, 50, 50);

	glPopMatrix();

	//roda fronteira direita
	glPushMatrix();
	glTranslatef(-0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira direita
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	//roda dianteira esquerda
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0.3);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidTorus(0.5, 0.6, 50, 50);
	glPopMatrix();

	glPopMatrix();

	bbox.setCordinates(xPos - 0.06, yPos - 0.06, xPos + 0.45*CAR_BBOX_LENGTH, yPos + 0.45*CAR_BBOX_LENGTH);

	if (GameManager::viewCollisionBoxes() == 1)
		bbox.draw();

	/*float* cordinates = bbox.getCordinates();
	std::cout << std::setprecision(3)  << "CAR: Bounding box from [" << cordinates[0] << ", " << cordinates[1] << "] to [" << cordinates[2] << ", " << cordinates[3] << "];" << std::endl;*/
}

void Car::setSpeed(double x, double y, double z){
	_speed->set(x, y, z);
}

void Car::invertSpeed(){
	_speed->set(-0.8*_speed->getX(), -0.8*_speed->getY(), 0);
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
	return _speed;
}

CollisionBox* Car::getBbox(){
	return &bbox;
}



void Car::rodaDireita(){
	angle -= 0.2;
	setDirection();
}


void Car::rodaEsquerda(){
	angle +=0.2;
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
	if (hasCollision)
	{

		moveBack(dt);
		hasCollision = false;
		return;
	}

	if (abs(sqrt(_speed->getX() * _speed->getX() + _speed->getY() * _speed->getY())) < MAXSPEED)
		_speed->set(_speed->getX() + getAcc()->getX() * dt, _speed->getY() + getAcc()->getY() * dt, 0);
	
	
	_position->set(_position->getX() + getSpeed()->getX() * dt * direction->getX(), _position->getY() + getSpeed()->getY() * dt * direction->getY(), _position->getZ());

	glFlush();

	//std::cout << "----->carro speed x=" << speed->getX() << " y=" << speed->getY() << " dir x=" << direction->getX() << " y="<< direction->getY() << std::endl;
	/*std::cout << "----->carro angle=" << angle * 180 / 3.14159 << " dir x=" << direction->getX() << " y=" << direction->getY() << std::endl*/
	hasCollision = false;
}

void Car::moveBack(int dt){
	this->_position->set(_position->getX() -   dt * getSpeed()->getX() * direction->getX(), _position->getY() - dt * getSpeed()->getY() * direction->getY(), _position->getZ());
	_speed->set(0, 0, 0);
	acc->set(0, 0, 0);
}

void Car::restartPosition(){
	_position->set(INIT_POS_X, INIT_POS_Y, INIT_POS_Z);
	_speed->set(0, 0, 0);
	acc->set(0, 0, 0);
	direction->set(0,1,0);
	this->setAngle(0);
}