//*************************************************************
//Billy Rodriguez  CS302  shamrock race functions
//
//These are the functions for the shamrock race
//*************************************************************

#include "shamrock.h"


//ABSTACT-BASE-CLASS FUNCTIONS
//**************************************************************************************************************************************************************************

//Constructors/Destructors

//default constructor
ShamrockRace::ShamrockRace(): name("None"), speed(0), time(0.0), inRace(false)
{}

//parameterized constructor
ShamrockRace::ShamrockRace(const string &contestantName, int contestantSpeed, float time, bool inRace): name(contestantName), speed(contestantSpeed), time(time), inRace(inRace)
{}

//destructor
ShamrockRace::~ShamrockRace()
{}


//Member-Functions

//register
void ShamrockRace::registerRace()
{
	inRace = true;
	
	cout << name << " has registered for the Shamrock Race!" << endl;
}

//stop race
bool ShamrockRace::stopRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}
	inRace = false;
	cout << name << " has stopped racing!" << endl;
	return true;
}

//quit race
bool ShamrockRace::quitRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}
	inRace = false;
	cout << name << " has quit the race!" << endl;
	return true;
}

//display
void ShamrockRace::display() const
{
	cout << "Contestant: " << name << "\nSpeed: " << speed 
	     << "\nTime: " << time << "\nStatus: "; if(inRace) 
	cout << "In Race"; else cout << "Not in Race" << endl;
}

//get name
string ShamrockRace::getName() const { return name; }

//**************************************************************************************************************************************************************************
//[ONE-LEGGED] DERIVED CLASS FUNCTIONS 

//Constructors/Destructors

//default constructor
OneLegged::OneLegged(): ShamrockRace(), flag(false), risky_leap(false)
{}

//parameterized constructor
OneLegged::OneLegged(const string &contestantName, int contestantSpeed, float time, bool inRace, bool flag, bool risky_leap): ShamrockRace(contestantName, contestantSpeed, time, inRace), flag(flag), risky_leap(risky_leap)
{}

//destructor
OneLegged::~OneLegged()
{}


//Member-Functions

//register
void OneLegged::registerRace()
{
	inRace = true;	

	cout << name << " has registered for the One-Legged Race!" << endl;
}

//start race
bool OneLegged::startRace()
{
	if(!inRace)
	{
		cout << name << " cannot start the race without registering!" << endl;
		return false;
	}

	cout << name << " starts hopping on one leg with a speed of " << speed << "!" << endl;
	if(risky_leap)
	{
		cout << name << " attempts a risky leap for more speed" << endl;
		speed += 5;
	}

	if(flag)
	{
		cout << name << " has cheated in the race and is disqualified!" << endl;
		inRace = false;
	}		
	return true;
}

//stop race
bool OneLegged::stopRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}

	inRace = false;
	cout << name << " has stopped racing!" << endl;
	return true;
}
		
//quit race
bool OneLegged::quitRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}
	inRace = false;
	cout << name << " has quit the race!" << endl;
	return true;
}

//display
void OneLegged::display() const
{
	ShamrockRace::display();	//show registration info
	cout << "One-Legged Racer: " << name << "\nSpeed: " << speed
	     << "\nRisky Leap: "; if(risky_leap) cout << "True"; else cout << "False";
	cout << "\nCurrently Racing: "; if(inRace) cout << "Yes"; else cout << "False" << endl;
}

//**************************************************************************************************************************************************************************
//[SPRINT] DERIVED CLASS FUNCTIONS 

//Constructors/Destructors

//default constructor
Sprint::Sprint(): ShamrockRace(), trip(false), runners_high(false)
{}
	
//parameterized constructor	
Sprint::Sprint(const string &contestantName, int contestantSpeed, float time, bool inRace, bool trip, bool runners_high): ShamrockRace(contestantName, contestantSpeed, time, inRace), trip(trip), runners_high(runners_high)
{}

//destructor
Sprint::~Sprint()
{}


//Member-Functions

//register
void Sprint::registerRace()
{
	inRace = true;	

	cout << name << " has registered for the Sprint Race!" << endl;
}

//start race
bool Sprint::startRace()
{

	if(!inRace)
	{
		cout << name << " cannot start the race without registering!" << endl;
		return false;
	}

	cout << name << " starts hopping on one leg with a speed of " << speed << "!" << endl;
	if(runners_high)
	{
		cout << name << " gets an insane burst of runner's high!" << endl;
		speed += 10;
	}
	if(trip)
	{
		cout << name << " trips and loses speed!" << endl;
		speed -= 5;
	}
	return true;
}

//stop race
bool Sprint::stopRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}

	inRace = false;
	cout << name << " has stopped racing!" << endl;
	return true;
}

//quit race
bool Sprint::quitRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}
	inRace = false;
	cout << name << " has quit the race!" << endl;
	return true;
}

//display
void Sprint::display() const
{
	ShamrockRace::display();	//show registration info
	cout << "Sprint Contestant: " << name << "\nSpeed: " << speed
	     << "\nrunners high: "; if(runners_high) cout << "True"; else cout << "False";
	cout << "\nCurrently Racing: "; if(inRace) cout << "Yes"; else cout << "False" << endl;
}

//**************************************************************************************************************************************************************************
//[BICYCLE] DERIVED CLASS FUNCTIONS 

//Constructors/Destructors

//default constructor
Bicycle::Bicycle(): ShamrockRace(), popped_tires(false), rest(false)
{}

//parameterized constructor
Bicycle::Bicycle(const string &contestantName, int contestantSpeed, float time, bool inRace, bool popped_tires, bool rest): ShamrockRace(contestantName, contestantSpeed, time, inRace), popped_tires(popped_tires), rest(rest)
{}

//destructor
Bicycle::~Bicycle()
{}


//Member-Functions

//register
void Bicycle::registerRace()
{
	inRace = true;	

	cout << name << " has registered for the Bicycle Race!" << endl;
}

//start race
bool Bicycle::startRace()
{

	if(!inRace)
	{
		cout << name << " cannot start the race without registering!" << endl;
		return false;
	}

	cout << name << " starts hopping on one leg with a speed of " << speed << "!" << endl;
	if(rest)
	{
		cout << "Looks like " << name << " has started to take a rest!" << endl;
		speed -= 10;
	}

	if(popped_tires)
	{
		cout << name << " has gotten popped tires and cannot continue the race!" << endl;
		inRace = false;
	}		
	return true;
}

//stop race
bool Bicycle::stopRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}

	inRace = false;
	cout << name << " has stopped racing!" << endl;
	return true;
}

//quit race
bool Bicycle::quitRace()
{
	if(!inRace)
	{
		cout << name << " is not in the race!" << endl;
		return false;
	}
	inRace = false;
	cout << name << " has quit the race!" << endl;
	return true;
}

//display
void Bicycle::display() const
{
	ShamrockRace::display();	//show registration info
	cout << "Bicycle Contestant: " << name << "\nSpeed: " << speed
	     << "\nPopped-Tires: "; if(popped_tires) cout << "True"; else cout << "False";
	cout << "\nCurrently Racing: "; if(inRace) cout << "Yes"; else cout << "False" << endl;
}

//contestant does a bike trick [RTTI]
bool Bicycle::doTrick()
{
	cout << name << " attempts an impressive Bicycle trick in the air!" << endl;
	return true;
}

//**************************************************************************************************************************************************************************


