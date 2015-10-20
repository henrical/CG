#ifndef _DYNAMIC_OBJECT_H_
#define _DYNAMIC_OBJECT_H_

#include <iostream>

#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject
{
	protected:
		Vector3* _speed;
		Vector3* acc;
		Vector3* direction;

	public:
		DynamicObject(){}
		~DynamicObject(){}

		void update(double delta_t);
		virtual void draw();

		Vector3* getAcc();
		void setAcc(double x, double y, double z);

		void setSpeed(Vector3 *vector);
		void setSpeed(double x, double y, double z);
		Vector3* getSpeed();

};

#endif