#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <math.h>
#include "CollisionBox.h"

#include "DynamicObject.h"

#define CAR_SIZE 0.1

//bounding box side length
#define CAR_BBOX_LENGTH  2*CAR_SIZE 

#define MAXSPEED 0.001

#define INIT_POS_X -1.1
#define INIT_POS_Y 0 
#define INIT_POS_Z 0


class Car : public DynamicObject
{
	private:
		Vector3* speed;
		Vector3* acc;
		double angle;
		Vector3* direction;

		CollisionBox bbox;

	public:
		Car();
		~Car(){}

		void draw();
		void setSpeed(double x, double y, double z);
		void setAcc(double x, double y, double z);
		Vector3* getSpeed();
		Vector3* getAcc();
		void update(int dt);
		void rodaDireita();
		void rodaEsquerda();
		void setDirection();

		CollisionBox* getBbox();

		/*void slowDownAcceleration(double acceleration);
		void slowDownSpeed(double speed);*/
};

#endif