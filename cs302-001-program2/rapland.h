//*************************************************************
//Billy Rodriguez  CS302  board game header
//
//This is the header file for the board game
//*************************************************************

#ifndef RAPLAND_H
#define RAPLAND_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


//Base Class: Player
class Player
{
	public:
		//constructor/destructor
		Player();					//constructor
		Player(const char *name, int points, bool hasWon);		//constructor
		Player(const Player &other);			//copy-constructor
		Player &operator=(const Player &other);		//assignment operator
		~Player();					//destructor

		//opeartor overloads
		bool operator<(const Player &other) const;	//< operator overload
		bool operator>(const Player &other) const;	//> operator overload
		bool operator==(const Player &other) const;	//== operator overload
		bool operator!=(const Player &other) const;	//!= operator overload
		friend ostream &operator<<(ostream &os, const Player &p);	//<< operator overload
		Player operator+(int points) const;		//+ operator overload
		Player &operator+=(int points);			//+= operator overload
		Player &operator-=(int points);			//-= operator overload

		//Gameplay methods
		void move();					//Player movement
		void answerTrivia();				//Player answer trivia
		bool checkWinCondition() const;			//Player win check
		void resetPlayer();				//Player reset
		int getPoints() const;				//Player retrieves points
		const char *getName() const;			//Player retrieves name
		void displayInfo() const;			//Player Display

	protected:
		char *name;				//Player name
		int points;				//Player points
		bool hasWon;				//Player wins
};




//Derived Class: npcLevel
class NpcLevel: public Player
{
	public:
		NpcLevel();					//constructor
		NpcLevel(const char *name = "NPC", int points = 0, bool hasWon = false);		//constructor
		~NpcLevel();					//destructor

		//Npc player methods
		void move();					//Only move forward
		void answerTrivia();				//Easy trivia	

	protected:
};



//Derived Class: knowledge level
class KnowledgeLevel: public Player
{
	public:
		KnowledgeLevel();				//constructor
		KnowledgeLevel(const char *name = "Knowledge", int points = 0, bool hasWon = false);	//constructor
		~KnowledgeLevel();				//destructor

		//Knowledge player methods
		void move();					//Can move forward or backwards
		void answerTrivia();				//Medium trivia

	protected:



};



//Derived Class: well-cultured level
class CulturedLevel: public Player
{
	public:
		CulturedLevel();				//constructor
		CulturedLevel(const char *name = "Cultured", int points = 0, bool hasWon = false);	//constructor
		CulturedLevel(const CulturedLevel &other);	//copy constructor
		CulturedLevel &operator=(const CulturedLevel &other);	//assignment operator
		~CulturedLevel();				//destructor

		//Cultured player methods
		void move();					//Can move forward or backwards
		void answerTrivia();				//Hard trivia
		void setAlias(const char *alias);		//Change rap alias
		void displayAlias() const;			//Show rap alias

	protected:
		char *rapAlias;				//Rap Alias name


};

#endif
