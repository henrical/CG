#ifndef _ORANGE_H_
#define _ORANGE_H_

#include "Obstacle.h"
#include "CollisionBox.h"

#define OR_COLOR_R 1
#define OR_COLOR_G 0.61568627
#define OR_COLOR_B 0

// Representa o raio da laranja.
#define ORANGE_RADIUS 0.12

#define ORANGE_BBOX_LENGTH 2*ORANGE_RADIUS 

class Orange : public Obstacle
{
	
	private:
		bool destroyed;

	public:
		Orange(Vector3 *pos);
		~Orange();

		void draw();

		bool destroyedp();

		void update(int dt);

};

#endif