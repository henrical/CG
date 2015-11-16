#include <iostream>
#include "Candle.h"

Candle::Candle(int light_num, double x, double y, double z)
	:LightSource(x, y, z), num(light_num) 
{
	_state = false;
}

void Candle::draw(){
	


	float xPos = _position->getX();
	float yPos = _position->getY();
	
	GLUquadric*  quad = gluNewQuadric();

	glPushMatrix();
	glTranslatef(xPos, yPos, 0.01);
	
	glColor3f(1.0, 0.0, 0.61);
	
	GLfloat ambi[] = { 0.7, 0.7, 0.55, 1.f };
	GLfloat diff[] = { 0.8, 0.8, 0.6, 1.f };
	GLfloat spec[] = { 1, 1, 0.8, 1.f };
	
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


	GLfloat ambient[] = { LIGHT_INTENSITY, LIGHT_INTENSITY, LIGHT_INTENSITY, 1.0 };
	GLfloat diffuse[] = { LIGHT_INTENSITY, LIGHT_INTENSITY, LIGHT_INTENSITY, 1.0 };
	GLfloat specular[] = { LIGHT_INTENSITY, LIGHT_INTENSITY, LIGHT_INTENSITY, 1.0 };
	GLfloat position[] = { _position->getX(), _position->getY(), CANDLE_HEIGHT, 0.0 };
	GLfloat direction[] = { 0.0, 0.0, -1.0 };

	/*glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);*/

	

	if (_state){
		switch (num)
		{
		case LIGHT1:
			glEnable(GL_LIGHT1);
			glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT1, GL_POSITION, position);
			break;
		case LIGHT2:
			glEnable(GL_LIGHT2);
			glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT2, GL_POSITION, position);
			break;
		case LIGHT3:
			glEnable(GL_LIGHT3);
			glLightfv(GL_LIGHT3, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT3, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT3, GL_POSITION, position);
			break;
		case LIGHT4:
			glEnable(GL_LIGHT4);
			glLightfv(GL_LIGHT4, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT4, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT4, GL_POSITION, position);
			break;
		case LIGHT5:
			glEnable(GL_LIGHT5);
			glLightfv(GL_LIGHT5, GL_AMBIENT, ambient);
			glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse);
			glLightfv(GL_LIGHT5, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT5, GL_POSITION, position);
			break;
		}
	}
	else{
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
	}
}