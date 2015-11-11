#ifndef _DYNAMIC_OBJECT_H_
#define _DYNAMIC_OBJECT_H_

#include <iostream>

#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject
{
	protected:
		double angle;

		Vector3* _speed;
		Vector3* acc;
		Vector3* direction;

		bool hasCollision;
		bool justCollided;

	public:
		DynamicObject();
		~DynamicObject(){}

		bool hasCollisionp();
		bool hasJustCollidedp();

		void triggerCollision();

		void update(double delta_t);
		virtual void draw();

		double getAngle();
		void setAngle(double);

		Vector3* getAcc();
		Vector3 getDirection();

		void setAcc(double x, double y, double z);

		void setSpeed(Vector3 *vector);
		void setSpeed(double x, double y, double z);
		Vector3* getSpeed();

		void setDirection();
		void setDirection(double x, double y, double z);

};

#endif