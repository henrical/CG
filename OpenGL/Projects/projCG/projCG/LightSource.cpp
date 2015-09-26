#include <iostream>

#include "LightSource.h"

bool LightSource::getState()
{
	return _state;
}

bool LightSource::setState(bool new_state)
{
	return _state = new_state;
}

GLenum LightSource::getNum()
{
	return _num;
}