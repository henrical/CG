#include <iostream>

#include "generic.h"

//Converts an RGB value (0-255) to [0,1] scale required by OpenGL.
float changeScale(int RGB){
	return (float)RGB / 255;
}