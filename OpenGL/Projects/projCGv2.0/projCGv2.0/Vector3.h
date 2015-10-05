#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

#include <iostream>

class Vector3 {
	private:
		double _x;
		double _y;
		double _z;

		//vector is null initially
		bool isNull = true;

	public:
		Vector3();
		Vector3(double x, double y, double z);
		~Vector3();

		//const: function does not modify object
		double getX() const; 
		double getY() const;
		double getZ() const;

		void set(double x, double y, double z);

		// vector1 = vector2; 
		Vector3 operator=(const Vector3 &vector){
			return Vector3(vector.getX(), vector.getY(), vector.getZ());
		}

		//vector1 = vector1 * n
		Vector3 operator*(double n){
			return Vector3(this->_x * n, this->_y * n, this->_z * n);
		}

		//vector1 = vector1 + vector2
		Vector3 operator+(const Vector3 &vector){
			return Vector3(this->_x + vector.getX(), this->_y + vector.getY(), this->_z + vector.getZ());
		}

		//vector1 = vector1 - vector2
		Vector3 operator-(const Vector3 &vector){
			return Vector3(this->_x - vector.getX(), this->_y - vector.getY(), this->_z - vector.getZ());
		}

		//Optional
		std::string toString();
		bool nullp();
};
#endif