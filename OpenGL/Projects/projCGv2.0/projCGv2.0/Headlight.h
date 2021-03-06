#ifndef _HEADLIGHT_H_
#define _HEADLIGHT_H_

#include "LightSource.h"
#include "GL\glut.h"

#define LIGHT6 6
#define LIGHT7 7


#define HEADLIGHT_INTENSITY 0.3f
#define HEADLIGHT_INTENSITY_DIF 0.4f
#define HEADLIGHT_INTENSITY_SPEC 0.45f


class Headlight : public LightSource
{
private:
	int num;

	float dir_x;
	float dir_y;

	static const GLint spot_cutoff = 10;
	static const GLint spot_exponent = 2;

public:
	Headlight();
	Headlight(int light_num, double x, double y, double z);
	
	void draw();
	void update(double, double, double, double, double);
};

#endif