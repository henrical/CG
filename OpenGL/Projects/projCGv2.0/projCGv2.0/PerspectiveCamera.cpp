#include <iostream>

#include "PerspectiveCamera.h"
#include "GL\glut.h"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double znear, double zfar, int camera_num)
	:Camera(znear, zfar)
{
	_fovy = fovy;
	_aspect = aspect;
	_camera_num = camera_num;


}

PerspectiveCamera::~PerspectiveCamera(){

}

void PerspectiveCamera::update(double car_pos_x, double car_pos_y, double car_dir_x, double car_dir_y){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, _near, _far);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (_camera_num == 2)
		gluLookAt(CAMERA2_EYE_X, CAMERA2_EYE_Y, CAMERA2_EYE_Z, CAMERA2_CENTER_X, CAMERA2_CENTER_Y, CAMERA2_CENTER_Z, CAMERA2_UP_X, CAMERA2_UP_Y, CAMERA2_UP_Z);
	else if (_camera_num == 3){
		double eyex = car_pos_x;
		double eyey = -1 + car_pos_y;

		gluLookAt(car_pos_x, -1 + car_pos_y, 1,      car_dir_x + eyex, car_dir_y + eyey, 0,       0, 1, 0);


		/*gluLookAt(car_pos_x, -1 + car_pos_y, 1, car_pos_x, car_pos_y, 0, 0, 1, 0); */
	}
}

void PerspectiveCamera::computeProjectionMatrix()
{

}

void PerspectiveCamera::computeVisualizationMatrix()
{

}