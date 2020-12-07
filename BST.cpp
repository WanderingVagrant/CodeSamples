#include "BST.h"
#include <vector>

/**
 * BST constructor
 */
BST::BST(): root(0), numElements(0) {
}

/**
 * BST destructor
 */
BST::~BST() {

	//Call clear
	clear();
}

/**
 * Size of BST
 */
unsigned int BST::size() const {
	return numElements;
}

/**
 * Helper funtion for BST destructor
 */
void BST::clear() {

	//If Empty do nothing
	if(root == 0)
		return;

	//Store the "actual" root while recursing
	Node * act = root;

	//Destroy the tree with leftChild as the root
	if(root->leftChild!=0){
		root = root->leftChild;
		clear();
	}

	//Restore root, then destroy the tree with rightChild as the root
	root = act;
	if(root->rightChild!=0){
		root = root->rightChild;
		clear();
	}

	//Restore the root, then delete it and decrement numElements
	root = act;
	delete root;
	root = 0;
	numElements--;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
	if(find(element))
		return false;
	Node * ele = new Node(element);
	if(root==0){
		root = ele;
		numElements++;
		return true;
	}
	Node * next = root;
	Node * parent = root;
	while(true){
		parent = next;
		if(next->data>element){
			next = next->leftChild;
			if(next == 0){
				parent->leftChild = ele;
				ele->parent = parent;
				numElements++;
				return true;
			}
		}
		else{
			next = next->rightChild;
			if(next == 0){
				parent->rightChild = ele;
				ele->parent = parent;
				numElements++;
				return true;
			}
		}
	}
}

/**
 * True if query exists within tree, False if not
 */
bool BST::find(const int & query) const {
	if(root == 0)
		return false;
	Node * curr = root;
	while(curr != 0){
		if(curr->data == query)
			return true;
		if(curr->data>query)
			curr = curr->leftChild;
		else
			curr = curr->rightChild;
	}
	return false;
}

/**
 * Finds the leftmost node
 */
BST::Node* BST::getLeftMostNode() {
	Node * left;
	if(!root)
		return 0;
	left = root->leftChild;
	while(left->leftChild!=0)
		left = left->leftChild;
	return left;
}

/**
 * Find the BST::Node successor 
 */
BST::Node* BST::Node::successor() {
	if(rightChild != 0){
		Node * curr = rightChild->leftChild;
		Node * par = rightChild;
		while(curr!=0){
			par = curr;
			curr = curr->leftChild;
		}
		return par;
	}
	Node * me = this;
	Node * curr = parent;
	while(curr != 0){
		if(curr->leftChild == me)
			return curr;
		me = curr;
		curr = curr->parent;
	}
	return 0;
}