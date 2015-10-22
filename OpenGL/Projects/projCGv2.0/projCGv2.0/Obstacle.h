#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "DynamicObject.h"
#include "CollisionBox.h"

#define CHEERIO_ACCELERATION 0.000001

class Obstacle : public DynamicObject
{
	protected:
		CollisionBox bbox;

	public: 
		Obstacle();
		~Obstacle();

		virtual void draw();
		virtual void update(double delta_t, Vector3 hit_direction);

		CollisionBox* getBbox();

};

#endif