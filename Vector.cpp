#include "Vector.h"

Vector::Vector(float i, float o, float p){
	x = i;
	y = o;
	z = p;
}

void Vector::setX(float i){
	x = i;
}

void Vector::setY(float i){
	y = i;
}

void Vector::setZ(float i){
	z = i;
}

float Vector::getX() const{
	return x;
}

float Vector::getY() const{
	return y;
}

float Vector::getZ() const{
	return z;
}

float Vector::mag() const
{
	return sqrt(x*x + y*y + z*z);
}

float Vector::dot(const Vector& h){
	return (h.x*x + h.y*y + h.z*z);
}

Vector Vector::cross(const Vector& h){
	Vector nu(y*h.z - z*h.y, z*h.x-x*h.z, x*h.y -y*h.x);
	return nu;
}

Vector Vector::operator+(const Vector& h){
	Vector nu(x+h.x, y+h.y, z+h.z);
	return nu;
}

Vector Vector::operator-(const Vector& h){
	Vector nu(x-h.x, y-h.y, z-h.z);
	return nu;
}

Vector Vector::operator*(const float& h)
{
	Vector nu(x * h, y * h, z * h);
	return nu;
}


ostream & operator<<(ostream& stream, const Vector& h){
	return stream << "x=" << h.x << ", y=" << h.y << ", z=" << h.z << "\n";
}
