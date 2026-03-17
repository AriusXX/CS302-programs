//*************************************************************
// Billy Rodriguez  CS302  board game trivia functions
//
// This is the implementation of the trivia functions
//*************************************************************

#include "trivia.h"

//constructor
Trivia::Trivia()
{
	questions = 
	{
		{"Who created the rap sub-genre 'Drill Rap'?", "Chief Keef"},
		{"Who started the wave of baby-voice rap?", "Playboi Carti"},
		{"What does 'MC' stand for in rap?", "Master of Ceromonies"},
    		{"Who was known as the 'Notorious B.I.G.'?", "Biggie Smalls"},
    		{"Which artist released the album 'Illmatic' in 1994?", "Nas"},
    		{"Which rap group is known for the hit song 'Straight Outta Compton'?", "N.W.A"},
    		{"Who is the founder of Aftermath Entertainment?", "Dr. Dre"},
    		{"What is Jay-Z's real name?", "Shawn Carter"},
    		{"Which rapper is known for the hit 'Hotline Bling'?", "Drake"},
    		{"What city is Kendrick Lamar from?", "Compton, California"},
    		{"Who is the artist behind the song 'Sicko Mode'?", "Travis Scott"},
    		{"Which female rapper's real name is Belcalis Almanzar?", "Cardi B"},
    		{"Who released the song 'Old Town Road'?", "Lil Nas X"}
	};

	srand(time(0));	//seed RNG
}

//Generate random question
pair<string, string> Trivia::getRandomQuestion()
{
	int index = rand() % questions.size();		//random question selected
	return questions[index];
}
