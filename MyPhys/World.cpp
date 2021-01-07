#include "World.h"

World::World(void (*forceField)(GameObject*), float air, float time) :
	air_resistance(air), forceField(forceField), time_step(time)
{
	GameObjects = new List();
}

void World::updateField(void(*forceField)(GameObject*))
{
	this->forceField = forceField;
}

void World::forces()
{
	for (int i = 0; i < GameObjects->NumElements(); ++i) {
		GameObject* curr = GameObjects->rotate();
		forceField(curr);
	}
}

GameObject* World::add(GameObject* o)
{
	return ((GameObject*)GameObjects->Insert(o, END));
}

void World::next()
{
	if (GameObjects->NumElements()) {
		forces();
		collision();
		move();
	}
}

void World::collision() {
	return;
}

void World::move() {
	for (int i = 0; i < GameObjects->NumElements(); ++i) {
		GameObjects->rotate()->updatePos(time_step);
	}
}

World::~World()
{
	delete GameObjects;
}

ostream& operator<<(ostream& stream, const World& h)
{
	for (int i = 0; i < h.GameObjects->NumElements(); ++i) {
		stream << *(h.GameObjects->rotate());
	}
	return stream;
}
