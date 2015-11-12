#ifndef _CANDLE_H_
#define _CANDLE_H_

#include "LightSource.h"
#include "GL\glut.h"

#define CANDLE_HEIGHT 0.3f
#define CANDLE_RADIUS 0.03f
#define CANDLE_RADIUS_TOP CANDLE_RADIUS * 0.55

class Candle : public LightSource
{
	public:
		Candle(double x, double y, double z);
		void draw();
};

#endif