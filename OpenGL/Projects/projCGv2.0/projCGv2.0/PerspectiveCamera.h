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
	Vector3* _position;
	Vector3* _at;
	Vector3* _up;


public:
	PerspectiveCamera(Vector3* VRC, Vector3* VPN, Vector3* VUV, double fovy, double aspect, double znear, double zfar, int camera_num);
	~PerspectiveCamera();

	void update(Vector3* VRC, Vector3* VPN);

	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif