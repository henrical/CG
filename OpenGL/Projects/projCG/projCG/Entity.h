#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <iostream>

#include "Vector3.h"

class Entity {
	private:
		Vector3* _position;

	public:
		Entity(){
			_position = new Vector3();
		}
		~Entity(){}

		Vector3* getPosition();
		Vector3* setPosition(double x, double y, double z);
		Vector3* setPosition(const Vector3 &vector);

		//Optional
		std::string toString();
};

#endif