#ifndef _ROADSIDE_H_
#define __ROADSIDE_H_

#include "StaticObject.h"

//The directions of the Road segments.
#define HORIZONTAL 1
#define VERTICAL 2

//The directions of the road margins(lines of cheerios).
#define SOUTHEAST 1
#define NORTHEAST 2
#define SOUTHWEST 3
#define NORTHWEST 4

//Specifies which side of the road is longer
//this is necessary to have proper curves.
#define INSIDE_CURVE 1
#define OUTSIDE_CURVE 2

// Road padding: specifies the space between each cheerio.
#define ROAD_PADDING 0.1
#define ANGLED_ROAD_PADDING 0.06
#define ROAD_WIDTH 0.4

class Roadside : public StaticObject {
private:
	bool game_has_started;

public:
	Roadside();
	~Roadside();
	void draw();
	void drawRoadsideSegment(const float color[], Vector3 initial, int num_torus, int direction, int curve);
	void drawRoadsideMargin(const float color[], Vector3 initial, int num_torus, int direction);
};

#endif