#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "DynamicObject.h"
#include "CollisionBox.h"

class Obstacle : public DynamicObject
{
	protected:
		CollisionBox bbox;

	public: 
		Obstacle();
		~Obstacle();

		virtual void draw();

		CollisionBox* getBbox();

};

#endif