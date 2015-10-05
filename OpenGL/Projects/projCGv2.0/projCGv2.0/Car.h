#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>

#include "DynamicObject.h"

class Car : public DynamicObject
{
	public:
		Car(){}
		~Car(){}

		void draw();
};

#endif