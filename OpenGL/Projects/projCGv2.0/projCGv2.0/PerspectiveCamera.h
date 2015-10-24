#ifndef _PERSP_CAMERA_H_
#define _PERSP_CAMERA_H_

#include "Camera.h"

#define CAMERA2_EYE_X 0
#define CAMERA2_EYE_Y -2.5
#define CAMERA2_EYE_Z 1.5

#define CAMERA2_CENTER_X 0
#define CAMERA2_CENTER_Y 0
#define CAMERA2_CENTER_Z 0

#define CAMERA2_UP_X 0
#define CAMERA2_UP_Y 1
#define CAMERA2_UP_Z 0



class PerspectiveCamera : public Camera
{
private:
	double _fovy;
	double _aspect;
	int _camera_num;


public:
	PerspectiveCamera(double fovy, double aspect, double znear, double zfar, int camera_num);
	~PerspectiveCamera();

	void update(double car_pos_x, double car_pos_y, double car_dir_x, double car_dir_y);

	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif