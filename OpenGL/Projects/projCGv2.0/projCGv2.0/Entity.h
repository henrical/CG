#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <iostream>

#include "Vector3.h"

class Entity {
	protected:
		Vector3* _position;

	public:
		Entity(){
			_position = new Vector3();
		}
		~Entity(){}

		//Cannot be overriden/redefined
		virtual Vector3* getPosition() final;
		virtual Vector3* setPosition(double x, double y, double z) final;
		virtual Vector3* setPosition(const Vector3 &vector) final;

		//Optional
		std::string toString();
};

#endif