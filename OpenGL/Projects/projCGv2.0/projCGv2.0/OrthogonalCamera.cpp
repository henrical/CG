#include <iostream>

#include "OrthogonalCamera.h"
#include "GL\glut.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far)
	:Camera(near,far)
{
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;

}

OrthogonalCamera::~OrthogonalCamera(){

}

void OrthogonalCamera::update(){
	
}

void OrthogonalCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(_left, _right, _bottom, _top, _near, _far);
}

void OrthogonalCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}