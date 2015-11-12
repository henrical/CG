#ifndef _CANDLE_H_
#define _CANDLE_H_

#include "LightSource.h"
#include "GL\glut.h"

#define CANDLE_HEIGHT 0.3f
#define CANDLE_RADIUS 0.03f
#define CANDLE_RADIUS_TOP CANDLE_RADIUS * 0.55

#define LIGHT1 1
#define LIGHT2 2
#define LIGHT3 3
#define LIGHT4 4
#define LIGHT5 5
#define LIGHT6 6

#define LIGHT_INTENSITY 0.06f

class Candle : public LightSource
{
	private:
		int num;

	public:
		Candle(int light_num, double x, double y, double z);
		void draw();
};

#endif