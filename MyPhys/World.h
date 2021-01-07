#ifndef WORLD_H
#define WORLD_H
#include "Vector.h"
#include "GameObject.h"
#include "List.h"
class World
{
	public:
		List * GameObjects;
		float air_resistance;
		void (*forceField)(GameObject *);
		float time_step;
		GameObject * add(GameObject * o);
		void next();
		World (float air, void (*forceField)(GameObject *), float time);
		World (float air, void (*forceField)(GameObject *));
		void updateField(void (*forceField)(GameObject *));
		void forces();
		void collision();
		void move();
		friend ostream& operator<<(ostream& stream, const World& h);
		~World();
};
#endif
