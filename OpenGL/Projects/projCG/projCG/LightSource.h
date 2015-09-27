#ifndef _LIGHTSOURCE_H_
#define _LIGHTSOURCE_H_

#include <iostream>

#include "GL/glut.h"
#include "Vector3.h"

class LightSource {

	private:
		double _ambient[4];
		double _diffuse[4];
		double _specular[4];
		double _cutOff;
		double _exponent;
		GLenum _num;
		bool _state;
		Vector3 _direction;
		Vector3 _position;

	public:
		LightSource();
		LightSource(int mode); //Mode tem de estar no enum "_num", acho
		~LightSource(){}

		bool getState();
		bool setState(bool new_state);
		GLenum getNum();
		void setPosition(/*const Vector4 &vector*/); //TODO: define Vector4
		void setDirection(const Vector3 &vector); //TODO
		void setCutOff(double cut_off);
		void setExponent(double exponent);
		void setAmbient(/*const Vector4 &vector*/); //TODO
		void setDiffuse(/*const Vector4 &vector*/); //TODO
		void setSpecular(/*const Vector4 &vector*/); //TODO
		void draw(); //TODO
};
#endif