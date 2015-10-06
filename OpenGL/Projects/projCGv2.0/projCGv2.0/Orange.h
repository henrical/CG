#ifndef _ORANGE_H_
#define _ORANGE_H_

#include "Obstacle.h"

class Orange : public Obstacle
{
	public:
		Orange();
		~Orange();

		void draw();
};

#endif