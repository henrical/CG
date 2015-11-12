#include <iostream>
#include "Candle.h"

Candle::Candle(double x, double y, double z)
:LightSource(x, y, z)
{
}

void Candle::draw(){
	
	float xPos = _position->getX();
	float yPos = _position->getY();
	
	GLUquadric*  quad = gluNewQuadric();

	glPushMatrix();
	glTranslatef(xPos, yPos, 0.01);
	
	glColor3f(1.0, 0.0, 0.61);
	
	GLfloat ambi[] = { 1.0, 1.0, 1.0, 1.f };
	GLfloat diff[] = { 0.86, 0.90, 0.85, 1.f };
	GLfloat spec[] = { 0.87, 0.96, 0.95, 1.f };
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glPushMatrix();
	
	glColor3f(0.95f, 0.93f, 0.9f);

	gluCylinder(	quad,
					CANDLE_RADIUS,
					CANDLE_RADIUS_TOP,
					CANDLE_HEIGHT,
					120,
					120);



	glPopMatrix();
	glPopMatrix();

	if (_state){
		//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//glClear(GL_COLOR_BUFFER_BIT);

		//GLfloat ambient[] = { 0.3, 0.3, 0.3, 1.0 };
		//GLfloat diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
		//GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };
		//GLfloat position[] = { _position->getX(), _position->getY(), _position->getZ(), 0.0 };
		//GLfloat direction[] = { 0.0, 0.0, -1.0 };

		//glEnable(GL_LIGHT0);
		//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		//glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
		//glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
		//glLightfv(GL_LIGHT0, GL_POSITION, position);
		////glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	}
	else{
		/*glDisable(GL_LIGHT0);*/
	}
}