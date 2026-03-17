//*************************************************************
//Billy Rodriguez  CS302  board game header
//
//This is the header file for the main menu
//*************************************************************

#ifndef MENU_H
#define MENU_H


#include "DLL.h"
#include "rapland.h"

//main menu
class Menu
{
	public:
		Menu();
		void displayMainMenu();
		void addPlayers(DLL<Player> &gameBoard, vector<Node<Player>*> &playerPositions);
		void startGame(DLL<Player> &gameBoard, vector<Node<Player>*> &playerPositions);
	
	private:
		int numPlayers;
};

#endif
