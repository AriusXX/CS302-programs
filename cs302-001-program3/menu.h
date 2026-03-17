//*************************************************************
//Billy Rodriguez  CS302  shamrock race main-menu
//
//This is the main-menu interface for the program
//*************************************************************


#include "shamrock.h"
#include "datastructure.h"
#include <iostream>
#include <memory>

#ifndef MENU_H
#define MENU_H
#pragma once

using namespace std;

//allow user to select a contestant type
void pickContestant(shared_ptr<ShamrockRace> &ptr) 
{
	int choice;
	cout << "Select race type:\n1. One-Legged Race\n2. Sprint Race\n3. Bicycle Race\n";
	cin >> choice;

	string name;
	cout << "Enter contestant name: ";
	cin >> name;
	

	//deciding which contest
	if(choice == 1) 
		ptr = make_shared<OneLegged>(name, 5, 0.0, false, true, false);
	else if(choice == 2) 
		ptr = make_shared<Sprint>(name, 20, 0.0, false, false, false);
	else if(choice == 3) 
		ptr = make_shared<Bicycle>(name, 50, 0.0, false, false, false);
	else
	{
		cout << "Invalid choice!\n";
		ptr = nullptr;
	}
}

//display menu options and get user input
int treeOption() 
{
	//menu options
	int choice;
	cout << "\nShamrock Race Menu:\n";
	cout << "1. Add Contestant\n";
	cout << "2. Display All Contestants\n";
	cout << "3. Remove a Contestant\n";
	cout << "4. Remove All Contestants\n";
	cout << "5. Quit\n";
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

#endif
