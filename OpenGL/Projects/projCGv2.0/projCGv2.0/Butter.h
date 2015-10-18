#ifndef _BUTTER_H_
#define _BUTTER_H_

#include "Obstacle.h"
#include "CollisionBox.h"

#define B_COLOR_R 0.9647058824
#define B_COLOR_G 1
#define B_COLOR_B 0.2705882353

// Representa o tamanho do lado mais curto.
#define BUTTER_SIZE 0.17

// Representa a divisao entre o comprimento do
// lado mais comprido e o mais curto.
#define SIDES_RATIO 1.3 

class Butter : public Obstacle
{	
private:
	float _angle;

	

public:
	Butter(Vector3 *pos, float angle);
	~Butter();

	void draw();

};

#endif