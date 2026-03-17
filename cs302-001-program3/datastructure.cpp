//*************************************************************
//Billy Rodriguez  CS302  shamrock race datastruct functions
//
//These are the functions for the tree data structure
//*************************************************************

#include "datastructure.h"


//NODE FUNCTIONS
//******************************************************************************

//Constructors/Destructors

//default constructor
Node::Node()
{}

//parameterized constructor
Node::Node(shared_ptr<ShamrockRace> &data): key(data->getName()), data(data), left(nullptr), right(nullptr)
{}


//Member-Functions

//get left node
unique_ptr<Node>& Node::getLeft() { return left; }

//get right node
unique_ptr<Node>& Node::getRight() { return right; }

//compare keys
bool Node::compareKey(const string &searchkey) const { return key > searchkey; }

//create key
void Node::create() { key = data->getName(); }

//display
void Node::displayNode() const
{
	if(data)
		data->display();
}

//******************************************************************************
//BST FUNCTIONS

//Constructors/Destructors

//default constructor
BST::BST(): root(nullptr)
{}

//insert wrapper
bool BST::insert(shared_ptr<ShamrockRace> &toInsert)
{
	if(!root)
	{
		root = make_unique<Node>(toInsert);
		root->create();
		return true;
	}
	return insert(root, toInsert);
}

//insert
bool BST::insert(unique_ptr<Node> &current, shared_ptr<ShamrockRace> &toInsert)
{
	if(!current)
	{
		current = make_unique<Node>(toInsert);
		current->create();
		return true;
	}

	if(current->compareKey(toInsert->getName()))
		return insert(current->getLeft(), toInsert);
	else	
		return insert(current->getRight(), toInsert);
}

//display wrapper
bool BST::display() const
{
	if(!root) return false;
	return display(root);
}

//display
bool BST::display(const unique_ptr<Node>& current) const
{
	if(!current) return false;

	current->displayNode();
	display(current->getLeft());
	display(current->getRight());

	return true;
}

//remove wrapper
bool BST::remove(const string &key)
{
	if(!root) return false;
	return remove(root, key);
}

//remove
bool BST::remove(unique_ptr<Node> &current, const string &key)
{
	if (key < current->getKey())
		return remove(current->getLeft(), key);
	else if (key > current->getKey())
		return remove(current->getRight(), key);
	else 
	{
		if (!current->getLeft()) 
			current = move(current->getRight());
		else if (!current->getRight()) 
			current = move(current->getLeft());
		else 
		{
			unique_ptr<Node> &successor = current->getRight();
			while (successor->getLeft())
				successor = move(successor->getLeft());
			current->getData() = successor->getData();
			current->getKey() = successor->getKey();
			return remove(current->getRight(), successor->getKey());
		}
		return true;	
	}
}

//remove all wrapper
bool BST::removeAll()
{
	if(!root) return false;
	root.reset();
	return true;
}


