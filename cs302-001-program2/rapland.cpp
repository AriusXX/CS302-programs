//*************************************************************
//Billy Rodriguez  CS302  board game functions
//
//These are the functions for rapland
//*************************************************************

#include "rapland.h"

//RNG roller
void initializeRNG() { srand(time(0)); }


//Base-Class[Player]
//*************************************************************************************************
//CONSTRUCTORS/DESTRUCTORS

//default constructor
Player::Player(): name(nullptr), points(0), hasWon(false)
{}

//constructor
Player::Player(const char *name, int points, bool hasWon): points(points), hasWon(hasWon)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//copy constructor
Player::Player(const Player &other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	points = other.points;
	hasWon = other.hasWon;
}

//assignment operator
Player &Player::operator=(const Player &other)
{
	if(this != &other)
	{
		delete [] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		points = other.points;
		hasWon = other.hasWon;
	}
	return *this;
}

//destructor
Player::~Player() { delete [] name; }


//OPERATOR OVERLOADS

//< operator
bool Player::operator<(const Player &other) const { return points < other.points; }
//> operator
bool Player::operator>(const Player &other) const { return points > other.points; }
//== operator
bool Player::operator==(const Player &other) const { return (strcmp(name, other.name) == 0) && (points == other.points); }
//!= operator
bool Player::operator!=(const Player &other) const { return !(*this == other); }

//<< operator
ostream &operator<<(ostream &os, const Player &p)
{
	os << "Player: " << p.name << " | Points: " << p.points << " | Status: "; if(p.hasWon == true) os << "Won"; else os << "Playing";
	return os;
}

//+ operator
Player Player::operator+(int points) const { return Player(name, this->points + points, hasWon); }
//+= operator
Player &Player::operator+=(int points) {this->points += points; return *this; }
//-= operator
Player &Player::operator-=(int points) {this->points -= points; return *this; }


//GAME FUNCTIONS

//player movement
void Player::move()
{
	//dice roll 1-6
	int roll = (rand() & 6) + 1;	
	cout << name << " rolled a " << roll << " and moves " << roll << " spaces." << endl;
}

//player trivia
void Player::answerTrivia() { cout << name << " answers a trivia question.\n"; }

//check win condition
bool Player::checkWinCondition() const { return points >= 200; } 

//reset player stats
void Player::resetPlayer()
{
	points = 0;
	hasWon = false;
}

//get points
int Player::getPoints() const { return points; }

//get name
const char *Player::getName() const { return name; }

//display player
void Player::displayInfo() const { cout << *this << endl; }
//*************************************************************************************************

//Derived-Class[npc]


//constructor
NpcLevel::NpcLevel(): Player("NPC", 0, false) {}
//constructor
NpcLevel::NpcLevel(const char *name, int points, bool hasWon): Player(name, points, hasWon) {}
//destructor
NpcLevel::~NpcLevel() {}

//npc player movement
void NpcLevel::move()
{
	//dice roll 1-6
	int roll = (rand() & 6) + 1;	
	cout << name << " rolled a " << roll << " and moves " << roll << " spaces." << endl;
}

//npc player trivia
void NpcLevel::answerTrivia() { cout << name << " answers an easy trivia question.\n"; }

//*************************************************************************************************

//Derived-Class[knowledge]

//constructor
KnowledgeLevel::KnowledgeLevel(): Player("Knowledge", 0, false) {}
//constructor
KnowledgeLevel::KnowledgeLevel(const char *name, int points, bool hasWon): Player(name, points, hasWon) {}
//destructor
KnowledgeLevel::~KnowledgeLevel() {}

//knowledge player movement
void KnowledgeLevel::move()
{
	//dice roll 1-6
	int roll = (rand() & 6) + 1;	
	cout << name << " rolled a " << roll << " and moves " << roll << " spaces." << endl;
}

//knowledge player trivia
void KnowledgeLevel::answerTrivia() { cout << name << " answers a medium trivia question.\n"; }

//*************************************************************************************************

//Derived-Class[cultured]

//constructor
CulturedLevel::CulturedLevel(): Player("Cultured", 0, false), rapAlias(nullptr) {}
//constructor
CulturedLevel::CulturedLevel(const char *name, int points, bool hasWon): Player(name, points, hasWon), rapAlias(nullptr) {}

//copy constructor
CulturedLevel::CulturedLevel(const CulturedLevel &other): Player(other)
{
	rapAlias = new char[strlen(other.rapAlias) + 1];
	strcpy(rapAlias, other.rapAlias);
}

//assignment operator
CulturedLevel &CulturedLevel::operator=(const CulturedLevel &other)
{
	if(this != &other)
	{
		Player::operator=(other);
		delete [] rapAlias;
		rapAlias = new char[strlen(other.rapAlias) + 1];
		strcpy(rapAlias, other.rapAlias);
	}
	return *this;
}

//destructor
CulturedLevel::~CulturedLevel() { delete [] rapAlias; }

//cultured player movement
void CulturedLevel::move()
{
	//dice roll 1-6
	int roll = (rand() & 6) + 1;	
	cout << name << " rolled a " << roll << " and moves " << roll << " spaces." << endl;
}

//cultured player trivia
void CulturedLevel::answerTrivia() { cout << name << " answers a hard trivia question.\n"; }

//set rap alias
void CulturedLevel::setAlias(const char *alias)
{
	delete [] rapAlias;
	rapAlias = new char[strlen(alias) + 1];
	strcpy(rapAlias, alias);
}

//display rap alias
void CulturedLevel::displayAlias() const { cout << "Rap Alias: "; if(rapAlias) cout << rapAlias; else cout << "None" << endl; }

//*************************************************************************************************















