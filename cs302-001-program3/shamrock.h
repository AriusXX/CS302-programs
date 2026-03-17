//*************************************************************
//Billy Rodriguez  CS302  shamrock race header
//
//This is the header file for the shamrock race
//*************************************************************

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <memory>

#ifndef SHAMROCK_H
#define SHAMROCK_H
#pragma once

using namespace std;

//Abstract-Base-Class(ABC)
class ShamrockRace
{
	public:
		ShamrockRace();			//constructor
		ShamrockRace(const string &contestantName, int contestantSpeed, float time, bool inRace);	//parameterized constructor
		virtual ~ShamrockRace();	//destructor
		virtual void registerRace();	//contestant registers 
		virtual bool startRace() = 0;	//Shamrock race starts
		virtual bool stopRace();	//Shamrock race stops	
		virtual bool quitRace();	//contestant quits
		virtual void display() const;	//display contestant's
		
		string getName() const;		//get name
	
	protected:
		string name;			//contestant's name
		int speed;			//contestant's racing pace
		float time;			//contestant's finished time
		bool inRace;			//contestant is in the race
				
};


//Derived-Class
class OneLegged: public ShamrockRace
{
	public:
		OneLegged();			//constructor
		OneLegged(const string &contestantName, int contestantSpeed, float time, bool inRace, bool flag, bool risky_leap);	//parameterized constructor
		~OneLegged();			//destructor
		void registerRace();		//contestant registers 
		bool startRace();		//Shamrock race starts
		bool stopRace();		//Shamrock race stops	
		bool quitRace();		//contestant quits
		void display() const; 		//display contestant's
		
	
	protected:
		bool flag;			//check to see if contestant is on one leg
		bool risky_leap;		//contestant takes a risky leap, giving them the upperhand	
		
};


//Derived-Class
class Sprint: public ShamrockRace
{
	public:
		Sprint();			//constructor
		Sprint(const string &contestantName, int contestantSpeed, float time, bool inRace, bool trip, bool runners_high);	//parameterized constructor
		~Sprint();			//destructor
		void registerRace();		//contestant registers 
		bool startRace();		//Shamrock race starts
		bool stopRace();		//Shamrock race stops	
		bool quitRace();		//contestant quits
		void display() const; 		//display contestant's
	
	protected:
		bool trip;			//contestant trips
		bool runners_high; 		//contestant sprints the fastest they can
		
};	


//Derived-Class
class Bicycle: public ShamrockRace
{
	public:
		Bicycle();			//constructor
		Bicycle(const string &contestantName, int contestantSpeed, float time, bool inRace, bool popped_tires, bool rest);	//parameterized constructor
		~Bicycle();			//destructor
		void registerRace();		//contestant registers 
		bool startRace();		//Shamrock race starts
		bool stopRace();		//Shamrock race stops	
		bool quitRace();		//contestant quits
		void display() const; 		//display contestant's
		
		//RTTI function
		bool doTrick();			//contestant does a biycycle trick
		

	protected:
		bool popped_tires;		//bicycle's tires get popped
		bool rest;			//bicyclist gets tired and rests for a bit

};	

#endif
