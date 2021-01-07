#include "World.h"
#include <cmath>
#include <iostream>
using namespace std;

void gravityrotates(GameObject * obj) {
	obj->acc = Vector(0, -9.8);
	obj->a_accel = 3.14159;
}

int main (int argc, char * const * argv) {

	//constructor tests
	Vector one(1, 2, 0);
	Vector two(2, 1, 0);

	std::cout << "One is " << one;
	std::cout << "Two is " << two;

	//Addition and subtraction
	std::cout << "one + two is " << (one+two);
	std::cout << "one - two is " << (one-two);

	//dot and cross
	std::cout << "one dot two is " << one.dot(two) << "\n";
	std::cout << "one cross two is " << one.cross(two);

	//GameObject Test
	Vector cube[4] = { Vector(0,0), Vector(4, 0), Vector(4,4), Vector(0, 4) };
	GameObject * test = new GameObject(4, cube, 1);
	std::cout << *test;

	//World and Movement Test
	Vector concave[] = { Vector(0,0), Vector(2,0), Vector(2,2), Vector(1,1), Vector(0, 2) };
	GameObject * test1 = new GameObject(5, concave, 1);
	World wr(0, &gravityrotates, 1);
	wr.add(test);
	wr.add(test1);
	cout << "Initial: " << wr << "\n";
	for (int i = 0; i < 10000; ++i) {
		wr.next();
		if ((i % 1000) == 0) {
			cout << "World at " << (i / 1000) << " is: " << wr << "\n";
		}
	}

	//Rotation Test
}