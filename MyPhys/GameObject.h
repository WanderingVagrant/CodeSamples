#ifndef GameObject_H
#define GameObject_H
#include "Vector.h"
class GameObject
{
public:
	Vector centroid;	//Coords of the center relative to origin
	//const float mrad; 
	Vector* shape;		//Verticies relative to centroid
	const int verts;    //Number of verticies
	float mass;			//Mass of object in kg
	float moment;		//The moment of inertia of the polygon kg m^2
	float area;			//The area of the polygon m^2
	Vector acc;			//The Linear acceleration of the polygon m/s^2
	Vector vel;			//The Linear velocity of the polygon m/s
	float a_accel;		//The angular acceleration of the polygon Rad/s^2
	float a_vel;		//The angular velcoity of the polygon Rad/s

	//Update the position and velocities of this object over a time_step
	void updatePos(float time);

	//Print this object to stream
	friend ostream& operator<<(ostream& stream, const GameObject& h);

	//Constructor taking int the number of verticies, the verticies themselves, and a density
	GameObject(int verts, Vector verticies[], float density);

	//Deallocates all memory associated with this GameObject
	~GameObject();
};
#endif




