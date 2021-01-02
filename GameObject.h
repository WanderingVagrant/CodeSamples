#ifndef GameObject_H
#define GameObject_H
#include "Vector.h"
class GameObject
{
	public: 
		Vector centroid;
		//const float mrad; 
		Vector * shape;		//Verticies relative to centroid
		const int verts;
		float mass;
		float moment;
		float area;
		Vector acc;
		Vector vel;
		float a_accel;
		float a_vel;
		void updatePos(float time);
		friend ostream& operator<<(ostream& stream, const GameObject& h);
		GameObject(int verts, Vector verticies[], float density);
		~GameObject();

};
#endif




