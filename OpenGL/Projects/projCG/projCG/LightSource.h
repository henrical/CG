#ifndef _LIGHTSOURCE_H_
#define _LIGHTSOURCE_H_

#include <iostream>

#include "GL/glut.h"

class LightSource {

	private:
		double _ambient[4];
		double _diffuse[4];
		double _specular[4];
		double _cutOff;
		double _exponent;
		GLenum _num;
		bool _state;

	public:
		LightSource(int mode); //Mode tem de estar no enum "_num"
		~LightSource();

		bool getState();
		bool setState(bool new_state);
		GLenum getNum();
		void setPosition(/*Vector4 &vector*/); //TODO: define Vector4

		//POR ACABAR
};		

#endif