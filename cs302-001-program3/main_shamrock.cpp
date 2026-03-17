//*************************************************************
//Billy Rodriguez  CS302  shamrock race 
//
//This is the main for shamrock race
//*************************************************************

#include "shamrock.h"
#include "menu.h"
#include "datastructure.h"

int main() 
{
	BST myTree;
	shared_ptr<ShamrockRace> object;
	int choice = 0;

	do 
	{
		choice = treeOption();

		if(choice == 1) 
		{
			pickContestant(object);
			if(object) 
			{
				myTree.insert(object);
				cout << object->getName() << " has been added to the Shamrock Race!\n";
			}
		}
		if(choice == 2) 
			myTree.display();
		if(choice == 3) 
		{
			string name;
			cout << "Enter contestant name to remove: ";
			cin >> name;
			if (myTree.remove(name)) 
				cout << name << " was removed from the race.\n";
			else 
				cout << "Contestant not found.\n";
		}
		if(choice == 4) 
		{
			myTree.removeAll();
			cout << "All contestants removed!\n";
		}

	}while (choice != 5);

	return 0;
}
