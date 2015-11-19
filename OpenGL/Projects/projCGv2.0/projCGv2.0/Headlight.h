#ifndef _HEADLIGHT_H_
#define _HEADLIGHT_H_

#include "LightSource.h"
#include "GL\glut.h"

#define LIGHT6 6
#define LIGHT7 7


#define HEADLIGHT_INTENSITY 0.3f
#define HEADLIGHT_INTENSITY_DIF 0.35f
#define HEADLIGHT_INTENSITY_SPEC 0.45f

class Headlight : public LightSource
{
private:
	int num;
	static const GLint spot_cutoff = 8;
	static const GLint spot_exponent = 0;

public:
	Headlight();
	Headlight(int light_num, double x, double y, double z);
	void draw();
	void update(double, double, double);
};

#endif