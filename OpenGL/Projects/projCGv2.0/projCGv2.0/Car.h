#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <math.h>
#include "CollisionBox.h"

#include "DynamicObject.h"
#include "Headlight.h"

#define CAR_SIZE 0.055

#define HEADLIGHT_NUM 2
#define HEADLIGHT_DISTANCE 0.02
//bounding box side length
#define CAR_BBOX_LENGTH  2*CAR_SIZE 

#define MAXSPEED 0.0006

#define INIT_POS_X -1.1
#define INIT_POS_Y 0 
#define INIT_POS_Z 0

 


class Car : public DynamicObject
{
	private:

		CollisionBox bbox;

		Headlight headlights[HEADLIGHT_NUM];

	public:
		Car();
		~Car(){}


		void draw();

		void setSpeed(double x, double y, double z);
		void invertSpeed();
		void moveBack(int dt);
		
		Vector3* getSpeed();

		
		void update(int dt);
		void rodaDireita();
		void rodaEsquerda();
		
		void restartPosition();
		
		bool getHeadlightStatus();
		void setHeadlights(bool);

		CollisionBox* getBbox();

		/*void slowDownAcceleration(double acceleration);
		void slowDownSpeed(double speed);*/
};

#endif