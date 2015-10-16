#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <math.h>

#include "DynamicObject.h"

#define MAXSPEED 0.001

class Car : public DynamicObject
{
	protected:
		Vector3* speed;
		Vector3* acc;
		double angle;
		Vector3* direccao;
	public:
		Car();
		~Car(){}

		void draw();
		void setSpeed(double x, double y, double z);
		void setAcc(double x, double y, double z);
		Vector3* getSpeed();
		Vector3* getAcc();
		void update(int dt);
		void rodaDireita();
		void rodaEsquerda();
		void setDireccao();
};

#endif