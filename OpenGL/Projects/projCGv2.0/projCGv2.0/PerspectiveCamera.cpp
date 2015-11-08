#include <iostream>

#include "PerspectiveCamera.h"
#include "GL\glut.h"

PerspectiveCamera::PerspectiveCamera(Vector3* VRC, Vector3* VPN, Vector3* VUV, double fovy, double aspect, double znear, double zfar, int camera_num)
	:Camera(znear, zfar)
{
	_fovy = fovy;
	_aspect = aspect;
	_camera_num = camera_num;
	_position = VRC;
	_at = VPN;
	_up = VUV;
}

PerspectiveCamera::~PerspectiveCamera(){

}

void PerspectiveCamera::update(Vector3* VRC, Vector3* VPN){
	_position = VRC;
	_at = VPN;
}

void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (_camera_num == 2)
		gluLookAt(CAMERA2_EYE_X, CAMERA2_EYE_Y, CAMERA2_EYE_Z, CAMERA2_CENTER_X, CAMERA2_CENTER_Y, CAMERA2_CENTER_Z, CAMERA2_UP_X, CAMERA2_UP_Y, CAMERA2_UP_Z);
	else if (_camera_num == 3)
		gluLookAt(_position->getX(), _position->getY(), _position->getZ(), _at->getX(), _at->getY(), _at->getZ(), _up->getX(), _up->getY(), _up->getZ());
}