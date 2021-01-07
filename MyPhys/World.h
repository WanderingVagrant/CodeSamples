#ifndef WORLD_H
#define WORLD_H
#include "Vector.h"
#include "GameObject.h"
#include "List.h"
class World
{
private:
	List* GameObjects;				//List of GameObjects in the World
	float air_resistance;			//The constant for air resistance
	void (*forceField)(GameObject*);//A function that applies the forcefield of the world to the object
	float time_step;				//The time_step of the world in ms, how often we caclulate and update each objects pos, accel, vel

	//Calculates the forces on the objects
	void forces();

	//Calculates the collision and resolves
	void collision();

	//Moves the objects over one time_step
	void move();

public:
	//Adds the given gameobject to the world
	GameObject* add(GameObject* o);

	//Calculate forces, handle collisions, then move over one time_step
	void next();

	//Constructor that takes in the air resistance, forcefield, and the timestep
	World(void (*forceField)(GameObject*), float air = 0, float time = 100);

	//Updates the forcefield
	void updateField(void (*forceField)(GameObject*));


	//Allows printing of the World
	friend ostream& operator<<(ostream& stream, const World& h);

	//Deallocates all memory associated with the world
	~World();
};
#endif
