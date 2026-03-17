//*************************************************************
//Billy Rodriguez  CS302  board game main
//
//This is the main for rapland
//*************************************************************


#include "rapland.h"
#include "menu.h"


int main()
{

	Menu menu;
	DLL<Player> gameBoard;
	vector<Node<Player>*> playerPostions;

	int choice;

	while(true)
	{
		menu.displayMainMenu();
		cin >> choice;

		if(choice == 1)
		{
			menu.addPlayers(gameBoard, playerPostions);
			menu.startGame(gameBoard, playerPostions);
			break;
		}
		else if(choice == 2)
		{
			cout << "Exiting Rapland. Bye!\n";
			break;
		}
		else
			cout << "Invalid. Try again.\n";
	}


	return 0;



}
