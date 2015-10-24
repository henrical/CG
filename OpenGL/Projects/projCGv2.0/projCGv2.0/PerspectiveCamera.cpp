#include <iostream>

#include "PerspectiveCamera.h"
#include "GL\glut.h"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double znear, double zfar, int camera_num, double car_pos_x, double car_pos_y)
	:Camera(znear, zfar)
{
	_fovy = fovy;
	_aspect = aspect;
	_camera_num = camera_num;

	_car_pos_x = car_pos_x;
	_car_pos_y = car_pos_y;

}

PerspectiveCamera::~PerspectiveCamera(){

}

void PerspectiveCamera::update(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, _near, _far);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (_camera_num == 2)
		gluLookAt(CAMERA2_EYE_X, CAMERA2_EYE_Y, CAMERA2_EYE_Z, CAMERA2_CENTER_X, CAMERA2_CENTER_Y, CAMERA2_CENTER_Z, CAMERA2_UP_X, CAMERA2_UP_Y, CAMERA2_UP_Z);
	else if(_camera_num == 3)
		gluLookAt(0, -2.5, 1.5, _car_pos_x, _car_pos_y, 0, 0, 1, 0);
}

void PerspectiveCamera::computeProjectionMatrix()
{

}

void PerspectiveCamera::computeVisualizationMatrix()
{

}