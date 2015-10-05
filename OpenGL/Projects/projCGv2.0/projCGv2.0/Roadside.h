#ifndef _ROADSIDE_H_
#define __ROADSIDE_H_

#include "StaticObject.h"

// Road padding: specifies the space between each cheerio.
#define ROAD_PADDING 0.1
#define ROAD_WIDTH 0.4

class Roadside : public StaticObject {
public:
	Roadside();
	~Roadside();
	void draw(const float color[]);
	void drawRoadsideSegment(const float color[]/*Vector3 inicial, int numtorus, Vector3 direction*/);
};

#endif