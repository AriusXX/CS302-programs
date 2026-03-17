//*************************************************************
//Billy Rodriguez  CS302  board game header
//
//These are the functions for the main menu
//*************************************************************

#include "menu.h"
#include "DLL.h"
#include "trivia.h"

//constructor
Menu::Menu(): numPlayers(0)
{}

//main menu
void Menu::displayMainMenu()
{
	cout << "**************************\n";
	cout << " Welcome to Rapland \n";
	cout << "**************************\n";
	cout << "1. Start Game\n";
	cout << "2. Exit\n";
	cout << "Enter your choice: ";
}

//adding players
void Menu::addPlayers(DLL<Player> &gameBoard, vector<Node<Player>*> &playerPositions)
{
	//enter amount of players 1-3
	cout << "Enter number of players (1-3): ";
	cin >> numPlayers;

	//only used when error
	while(numPlayers < 1 || numPlayers > 3)
	{
		cout << "Invalid number. Enter 1-3";
		cin >> numPlayers;
	}

	//allow set conditions for each player
	for (int i = 0; i < numPlayers; i++) 
	{
		//create player menu choices
		string name;
		int choice;

		//set player conditions
		cout << "Enter Player " << i + 1 << " name: ";
		cin >> name;
		cout << "Select Level: 1. NPC  2. Knowledge  3. Cultured\n";
		cin >> choice;
		cin.ignore(1000, '\n');

		//set values to player object
		Player newPlayer;
		if (choice == 1) 
			newPlayer = Player(name.c_str(), 0, false);
		else if (choice == 2) 
			newPlayer = Player(name.c_str(), 0, false);
		
		//cultured players get to have their unique nickname
		else if (choice == 3) 
		{
			string alias;
			cout << "Enter Rap Alias: ";
			cin >> alias;

			CulturedLevel culturedPlayer(name.c_str(), 0, false);
			culturedPlayer.setAlias(alias.c_str());
			newPlayer = culturedPlayer;

		}

		//insert player onto board
		gameBoard.insertAtEnd(newPlayer);
		if (i == 0) playerPositions.push_back(gameBoard.getHead());
		else playerPositions.push_back(playerPositions[i - 1]->next);
	}
}


//game starts
void Menu::startGame(DLL<Player> &gameBoard, vector<Node<Player>*> &playerPositions)
{
	cout << "Game is starting!\n";
    	bool gameRunning = true;

	//game starts
    	while (gameRunning) 
	{
		//cycle through each player for their turn
        	for (int i = 0; i < numPlayers; i++)
		{
            		cout << playerPositions[i]->data.getName() << "'s turn!\n";
            		playerPositions[i]->data.move();
            		gameBoard.askTrivia(playerPositions[i], playerPositions[i]->data);
			
			//whenever player wins
            		if (playerPositions[i]->data.checkWinCondition())
			{
                		cout << playerPositions[i]->data.getName() << " wins the game!\n";
                		gameRunning = false;
                		break;
            		}
        	}
    	}
}

