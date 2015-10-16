#ifndef _TABLE_H_
#define _TABLE_H_

#include "Obstacle.h"

class Table : public Obstacle
{
public:
	Table(){}
	~Table();

	void draw();

};

#endif