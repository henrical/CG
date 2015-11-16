#ifndef _HEADLIGHT_H_
#define _HEADLIGHT_H_

#include "LightSource.h"
#include "GL\glut.h"

#define LIGHT6 6
#define LIGHT7 7


#define HEADLIGHT_INTENSITY 0.5f

class Headlight : public LightSource
{
private:
	int num;

public:
	Headlight();
	Headlight(int light_num, double x, double y, double z);
	void draw();
	void update(double, double, double);
};

#endif