#include "GameObject.h"

void GameObject::updatePos(float time)
{

	float secs = time / 1000.0;
	//Translational motion
	centroid = centroid + (vel * secs);

	//Rotational motion
	float angle = (a_vel * secs);
	float sine = sin(angle);
	float cosine = cos(angle);
	
	for (int i = 0; i < verts; ++i) {
		shape[i] = Vector((shape[i].getX() * cosine) - (shape[i].getY() * sine), (shape[i].getX() * sine) + (shape[i].getY() * cosine));
	}

	//Newton Approx
	vel = vel + (acc*secs);
	a_vel += (a_accel*secs);
}

/*
* verticies is a list of the verticies of the polygon given counter-clockwise
*/
GameObject::GameObject(int verts, Vector verticies[], float density): verts(verts)
{
	float a = 0;
	Vector cent = Vector();
	float part = 0;
	//Calulate Centroid and Area using Surveyor's formula
	for (int i = 0; i < verts-1; ++i) {
		part = verticies[i].cross(verticies[i+1]).getZ();
		a += part;
		cent = cent + ((verticies[i] + verticies[i + 1]) * part);
	}
	part = verticies[verts - 1].cross(verticies[0]).getZ();
	a += part;
	a = a * 0.5;
	cent = cent + ((verticies[verts - 1] + verticies[0]) * part);
	cent = cent * (1 / (6 * a));
	area = a;
	centroid = cent;
	mass = density * area;
	
	//Calculate shape relative to centroid
	Vector * sh = new Vector[verts];
	for (int i = 0; i < verts; ++i) {
		sh[i] = verticies[i] - centroid;
	}
	shape = sh;
	
	//Caluculate moment of Inertia using second moment of area
	float mom = 0;
	for (int i = 0; i < verts-1; ++i) {
		mom += shape[i].cross(shape[i + 1]).getZ()* pow(((shape[i] + shape[i + 1]).mag()), 2);
	}
	mom += shape[verts - 1].cross(shape[0]).getZ() * pow(((shape[verts - 1] + shape[0]).mag()), 2);
	moment = (1.0 / 12.0) * mom;
	a_accel = 0;
	a_vel = 0;
}

GameObject::~GameObject()
{
}

ostream& operator<<(ostream& stream, const GameObject& h)
{
	stream << "Mass is: " << h.mass << " Moment is: " << h.moment << "\n";
	stream << "Center is: " << h.centroid << " .";
	for (int i = 0; i < h.verts; ++i) {
		stream << "Vertex " << i << " is: " << (h.shape[i] + h.centroid) << " ,";
	}
	stream << "\n";
	return stream;
}
