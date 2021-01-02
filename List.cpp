#include <iostream>
#include "GameObject.h"
#include "List.h"
using namespace std;

struct Node {
	GameObject * data;
	struct Node * pre;
	struct Node * next;

	Node (GameObject* element) : data (element), pre (NULL), next (NULL) {}
	~Node (void);
	ostream & Write (ostream & stream) {
		return stream << *(data);
	}
};

List :: List (void) : joint (NULL), occupancy (0) {}

List :: ~List (void) {
	GameObject * data;

	/* empty list */
	while (occupancy) {

		/* remove top element from list */
		data = Remove (END);

		/* delete data element */
		delete data;
	}
}

GameObject * List :: Remove (long where) {
	Node * old_node;		/* working node */
	GameObject * retval;

	/* check status of list */
	if (!occupancy) {
		cerr << "Popping from an empty list!!!\n";
		return NULL;
	}

	/* adjust FRONT if necessary to always remove from the END */
	if (where == FRONT)
		joint = joint->next;;

	old_node = joint->pre;
	retval = old_node->data;

	/* remove old_node from list */
	old_node->pre->next = joint;
	joint->pre = old_node->pre;

	/* delete the empty node */
	delete old_node;

	/* update occupancy */
	occupancy--;

	return retval;
}

GameObject * List :: Insert (GameObject * element, long where) {
	GameObject * retval;
	Node * new_node;

	/* store element in a Node */
	new_node = new Node (element);
	retval = new_node->data;

	/* is this the only element in the list??? */
	if (!occupancy)
		joint = new_node->next = new_node->pre = new_node;
	
	else {
		new_node->next = joint;
		new_node->pre = joint->pre;
		joint->pre->next = new_node;
		joint->pre = new_node;
	}

	if (where == FRONT)
		joint = new_node;

	/* update occupancy */
	occupancy++;

	return retval;
}

GameObject * List :: View (long where) {

	/* empty list */
	if (!occupancy)
		return NULL;

	return (where == END) ? joint->pre->data : joint->data;
}

GameObject* List::rotate() {
	if (!occupancy)
		return NULL;
	joint = joint->next;
	return joint->pre->data;
}

ostream & List :: Write (ostream & stream) {
	long count;		/* to know how many elements to print */
	Node * n;			/* working node */

	n = joint;
	for (count = 1; count <= occupancy; count++) {
		n->Write (stream);
		n = n->next;
	}
		
	return stream;
}

Node :: ~Node (void) {
	data = NULL;
	next = pre = NULL;
}
