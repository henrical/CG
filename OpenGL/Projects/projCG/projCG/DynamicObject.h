#ifndef _DYNAMIC_OBJECT_H_
#define _DYNAMIC_OBJECT_H_

#include <iostream>

#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject
{
	private:
		Vector3 _speed;

	public:
		DynamicObject(){}
		~DynamicObject(){}

		void update(double delta_t);
		virtual void draw();

		void setSpeed(const Vector3 &vector);
		void setSpeed(double x, double y, double z);
		Vector3 getSpeed();

};

#endif