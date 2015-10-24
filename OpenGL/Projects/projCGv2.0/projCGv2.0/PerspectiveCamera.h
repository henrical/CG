#ifndef _PERSP_CAMERA_H_
#define _PERSP_CAMERA_H_

#include "Camera.h"

class PerspectiveCamera : public Camera
{
private:
	double _fovy;
	double _aspect;

public:
	PerspectiveCamera(double fovy, double aspect, double znear, double zfar);
	~PerspectiveCamera();

	void update();

	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif