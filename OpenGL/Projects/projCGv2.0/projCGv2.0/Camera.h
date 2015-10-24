#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Entity.h"
#include "Vector3.h"

class Camera : public Entity
{
	protected:
		double _near;
		double _far;
		Vector3 _up;
		Vector3 _center;
		Vector3 _at;

	public:
		Camera(double near, double far);
		~Camera();

		void update();

		virtual void computeProjectionMatrix();
		virtual void computeVisualizationMatrix();
};

#endif