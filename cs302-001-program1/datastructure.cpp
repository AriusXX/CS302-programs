//*************************************************************************************************
//Billy Rodriguez  CS302  1/14/2025  PROGRAM_1
//
//These are the functions for the datastructures
//*************************************************************************************************

#include "datastructure.h"

//CLOTHING NODE FUNCTIONS

//constructor
ClothingNode::ClothingNode(const char *a_name, float a_price, const string &a_size, const string &a_color): Clothing(a_name, a_price, a_size, a_color), next(nullptr) 
{}

//destructor
ClothingNode::~ClothingNode()	
{}

//get next node
ClothingNode * ClothingNode::getNext() const 
{
	return next;
}

//set next node
void ClothingNode::setNext(ClothingNode *nextNode)
{ 
	next = nextNode; 
}	




//CLOTHING LIST FUNCTIONS

//constructor
ClothingList::ClothingList(): head(nullptr)
{}

//destructor
ClothingList::~ClothingList() 
{ 
	clear(); 
}

//wrapper function for insert
void ClothingList::insert(const char *a_name, float a_price, const string &a_size, const string &a_color)
{
	insertRecursive(head, a_name, a_price, a_size, a_color);
}

//wrapper function for display
void ClothingList::display() const 
{ 
	displayRecursive(head); 
}

//wrapper function for remove
void ClothingList::remove(const char *a_name) 
{ 
	removeRecursive(head, a_name); 
}

//wrapper function for clear
void ClothingList::clear() 
{ 
	clearRecursive(head); 
}

//recursive function for insert
void ClothingList::insertRecursive(ClothingNode * &current, const char *a_name, float a_price, const string &a_size, const string &a_color)
{
	if(!current)
	{
		current = new ClothingNode(a_name, a_price, a_size, a_color);
		return;
	}

	ClothingNode *nextNode = current->getNext();
	insertRecursive(nextNode, a_name, a_price, a_size, a_color);
}

//recursive function for display
void ClothingList::displayRecursive(const ClothingNode *current) const
{
	if(current)
	{
		current->display();
		displayRecursive(current->getNext());
	}
}

//recursive function for removal
bool ClothingList::removeRecursive(ClothingNode * &current, const char *a_name)
{
	if(!current)
		return false;
	if(strcmp(current->getName(), a_name) == 0)
	{
		ClothingNode *temp = current;
		current = current->getNext();
		delete temp;
		return true;
	}

	ClothingNode *nextNode = current->getNext();
	return removeRecursive(nextNode, a_name);
}

//recursive function for clear
void ClothingList::clearRecursive(ClothingNode * &current)
{
	if(!current)
		return;
	ClothingNode *nextNode = current->getNext();
	delete current;
	current = nullptr;
	clearRecursive(nextNode);
}



//ARR DATASTRUCTURE FOR CLOTHING PRODUCTS

//constructor
ClothingInventory::ClothingInventory()
{}

//destructor
ClothingInventory::~ClothingInventory()
{
	clear();
}

//inserting clothing product into a category
void ClothingInventory::insert(int category, const char *a_name, float a_price, const string &a_size, const string &a_color)
{
	if(category >= 0 && category < NUM_CATEGORIES)
		categories[category].insert(a_name, a_price, a_size, a_color);
	else
		cout << "Invalid Category." << endl;
}

//displaying desired clothing category
void ClothingInventory::display() const
{
	for(int i = 0; i < NUM_CATEGORIES; ++i)
	{
		cout << "Category " << i + 1 << ":\n";
		categories[i].display();
	}
}

//clear clothing products in category
void ClothingInventory::clear()
{
	for(int i = 0; i < NUM_CATEGORIES; ++i)
		categories[i].clear();
}





//FOOD NODE FUNCTIONS

//constructor
FoodNode::FoodNode(const char *a_name, float a_price, int a_expirationdays, float a_weight): Food(a_name, a_price, a_expirationdays, a_weight), next(nullptr)
{}

//destructor
FoodNode::~FoodNode()
{}

//get the next node
FoodNode *FoodNode::getNext() const
{
	return next;
}

//set the next node
void FoodNode::setNext(FoodNode *nextNode)
{
	next = nextNode;
}




//CLL DATASTRUCTURE FOR FOOD PRODUCTS

//constructor
FoodCLL::FoodCLL(): rear(nullptr)
{}

//destructor
FoodCLL::~FoodCLL()
{
	clear();
}

//wrapper function for insert
void FoodCLL::insert(const char *a_name, float a_price, int a_expirationdays, float a_weight)
{
	insertRecursive(rear, a_name, a_price, a_expirationdays, a_weight);
}

void FoodCLL::display() const
{
	if(!rear)
	{
		cout << "The inventory is empty." << endl;
		return;
	}
	displayRecursive(rear, rear->getNext());
}

//wrapper function for remove
void FoodCLL::remove(const char *a_name)
{
	if(rear)
	{
		FoodNode *current = rear->getNext();
		if(removeRecursive(rear, current, a_name))
			cout << a_name << " has been removed." << endl;
		else
			cout << a_name << " not found." << endl;
	}
}

//wrapper function for clear
void FoodCLL::clear()
{
	if(rear)
		clearRecursive(rear, rear->getNext());
	rear = nullptr;
}

//recursive function for insert
void FoodCLL::insertRecursive(FoodNode * &rear, const char *a_name, float a_price, int a_expirationdays, float a_weight)
{
	if(!rear)
	{
		rear = new FoodNode(a_name, a_price, a_expirationdays, a_weight);
		rear->setNext(rear);
		return;
	}

	FoodNode *newNode = new FoodNode(a_name, a_price, a_expirationdays, a_weight);
	newNode->setNext(rear->getNext());
	rear->setNext(newNode);
	rear = newNode;
}

//recursive function for display
void FoodCLL::displayRecursive(FoodNode *rear, FoodNode *current) const
{
	if (!current || current == rear)
	{
		rear->display(); // Display the rear node
		return;
	}
	current->display();
	displayRecursive(rear, current->getNext());
}

//recursive function for remove

bool FoodCLL::removeRecursive(FoodNode *&rear, FoodNode *&current, const char *a_name)
{
	if (!current)
		return false;

	if (strcmp(current->getName(), a_name) == 0)
	{
		if (current == rear)
		{
			if (current->getNext() == current)
			{
				delete current;
				rear = nullptr;
				return true;
			}
			rear->setNext(current->getNext());
			delete current;
			current = rear->getNext();
			return true;
		}
		FoodNode *temp = current;
		current = current->getNext();
		rear->setNext(current);
		delete temp;
		return true;
	}
	FoodNode *nextNode = current->getNext();
	return removeRecursive(rear, nextNode, a_name);
}

//recursive function for clear

void FoodCLL::clearRecursive(FoodNode *&rear, FoodNode *current)
{
	if (current == rear)
	{
		delete current;
		rear = nullptr;
		return;
	}
	clearRecursive(rear, current->getNext());
	delete current;
}

//recursive function for find
FoodNode *FoodCLL::findRecursive(FoodNode *current, const char *a_name) const
{
	if (!current || strcmp(current->getName(), a_name) == 0)
		return current;
	if (current == rear)
		return nullptr;
	return findRecursive(current->getNext(), a_name);
}




//VECTOR FOR TECH PRODUCTS

//insert tech products
void TechInventory::add(const Tech &item)
{
	inventory.push_back(item);
}

//display tech products
void TechInventory::display() const
{
	for(const auto &item:inventory)
		item.display();
}

//remove tech products
void TechInventory::remove(const char *model)
{
	inventory.erase(remove_if(inventory.begin(), inventory.end(), [&](const Tech &item){return strcmp(item.getModel(), model) == 0;}),
	inventory.end());
}
	
