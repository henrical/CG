#ifndef _CHEERIO_H_
#define _CHEERIO_H_

#include "Obstacle.h"
#include "CollisionBox.h"

#define C_COLOR_R 0.6392156863
#define C_COLOR_G 0.2980392157
#define C_COLOR_B 0

// Representa o raio interior e exterior do torus.
#define TORUS_INNER_RADIUS 0.01
#define TORUS_OUTER_RADIUS 0.02

#define CHEERIO_BBOX_LENGTH 2*TORUS_OUTER_RADIUS

class Cheerio : public Obstacle
{
private:
	bool has_collision;
	bool game_has_started;

	CollisionBox bbox;

public:
	Cheerio(Vector3 *pos);
	~Cheerio();

	void draw();

};

#endif