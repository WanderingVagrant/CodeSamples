#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "GameObject.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node;

class List{
	long occupancy;
	Node* joint;
public:
	List (void);
	~List (void);
	GameObject * Insert(GameObject*, long);
	GameObject * Remove (long);
	GameObject * View (long);
	GameObject * rotate();
	long IsEmpty (void) {
		return ! NumElements ();
	}
	long NumElements (void) {
		return occupancy;
	}
	ostream & Write (ostream &);
};

/* where to insert, view, remove */
#define FRONT 0
#define END 1

#endif
