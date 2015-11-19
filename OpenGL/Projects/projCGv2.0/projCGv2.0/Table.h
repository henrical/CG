#ifndef _TABLE_H_
#define _TABLE_H_

#include "Obstacle.h"

/* TABLE_SIDE % POLYGON_COMPONENT_SIDE == 0 is a requirement */
#define TABLE_SIDE 4.5f
#define SUBDIVISIONS 55

#define POLYGON_SIDE TABLE_SIDE / SUBDIVISIONS
//#define VERTEX_DEVIATION_FROM_AXIS POLY

class Table : public Obstacle
{
public:
	Table(){}
	~Table();

	void draw();

};

#endif