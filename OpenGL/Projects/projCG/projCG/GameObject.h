#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "Entity.h"

class GameObject : public Entity
{
	public:
		GameObject(){}
		~GameObject(){}

		//Virtual: forces subclasses to redefine methods.
		virtual void draw();
		virtual void update(double delta_t);
};

#endif