#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
class Vector
{
		float x;
		float y;
		float z;
	public:
		Vector(float i = 0, float o = 0, float p = 0);
		void setX(float i);
		void setY(float i);
		void setZ(float i);
		float getX() const;
		float getY() const;
		float getZ() const;
		float mag() const;
		float dot(const Vector& h);
		Vector cross(const Vector& h);
		Vector operator+(const Vector& h);
		Vector operator-(const Vector& h);
		Vector operator*(const float& h);
		friend ostream & operator<<(ostream& stream, const Vector& h);
};
#endif
