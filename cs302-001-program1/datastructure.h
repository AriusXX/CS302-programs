//*************************************************************************************************
//Billy Rodriguez  CS302  1/14/2025  PROGRAM_1
//
//This is the header for the datastructures for the program
//*************************************************************************************************

#include "product.h"


//Node for clothing product
class ClothingNode: public Clothing
{
	public:
		ClothingNode(const char *a_name, float a_price, const string &a_size, const string &a_color);	//constructor
		~ClothingNode();			//destructor
		ClothingNode *getNext() const;		//get next node for read only
		void setNext(ClothingNode *next);	//set the next node
		
	private:
		ClothingNode *next;			//next node
};

//LLL for clothing products
class ClothingList
{
	public:
		ClothingList();				//constructor
		~ClothingList();			//destructor
		void insert(const char *a_name, float a_price, const string &a_size, const string &a_color);	//insert clothing products
		void display() const;			//display clothing products
		void remove(const char *a_name);	//remove clothing product
		void clear();				//clear clothing products

	private:
		ClothingNode *head;			//private data

		void insertRecursive(ClothingNode * &current, const char *a_name, float a_price, const string &a_size, const string &a_color);	//insert clothing product
    		void displayRecursive(const ClothingNode *current) const;			//display clothing product
    		bool removeRecursive(ClothingNode * &current, const char *a_name);		//remove clothing product
    		void clearRecursive(ClothingNode * &current);					//clear clothing products
};

//ARR for clothing products
class ClothingInventory
{
	public:
		ClothingInventory();			//constructor
		~ClothingInventory();			//destructor
		void insert(int category, const char *a_name, float a_price, const string &a_size, const string &a_color);		//insert clothing product
		void display() const;			//display clothing products
		void clear();				//clear clothing products

	private:
		static const int NUM_CATEGORIES = 3;	//men, women, children
		ClothingList categories[NUM_CATEGORIES];//array of each category
};


//Node for food product
class FoodNode: public Food
{
	public:
		FoodNode(const char *a_name, float a_price, int a_expirationdays, float a_weight);	//constructor
		~FoodNode();				//destructor
		FoodNode *getNext() const;		//get next node for read only
		void setNext(FoodNode *next);		//set the next node

	private:
		FoodNode *next;				//next node
};

//CLL for food products
class FoodCLL
{
	public:
		FoodCLL();
		~FoodCLL();
		void insert(const char *a_name, float a_price, int a_expirationdays, float a_weight);
		void display() const;
		void remove(const char *a_name);
		void clear();
		FoodNode *find(const char *a_name) const;
		
	private:
		FoodNode *rear;
		void insertRecursive(FoodNode * &rear, const char *a_name, float a_price, int a_expirationdays, float a_weight);
		void displayRecursive(FoodNode *rear, FoodNode *current) const;
		bool removeRecursive(FoodNode * &rear, FoodNode * &current, const char *a_name);
		void clearRecursive(FoodNode * &rear, FoodNode *current);
		FoodNode *findRecursive(FoodNode *current, const char *a_name) const;
};



//VECTOR for tech products
class TechInventory
{
	public:
		void add(const Tech &item);
		void display() const;
		void remove(const char *model);

	private:
		vector<Tech>inventory;
};
