#include <iostream>

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double znear, double zfar)
	:Camera(znear, zfar)
{
	_fovy = fovy;
	_aspect = aspect;

}

PerspectiveCamera::~PerspectiveCamera(){

}

void PerspectiveCamera::update(){

}

void PerspectiveCamera::computeProjectionMatrix()
{

}

void PerspectiveCamera::computeVisualizationMatrix()
{

}