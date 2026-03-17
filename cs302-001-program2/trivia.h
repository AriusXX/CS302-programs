//*************************************************************
// Billy Rodriguez  CS302  board game trivia header
//
// This is the header for the trivia questions
//*************************************************************

#ifndef TRIVIA_H
#define TRIVIA_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Trivia
{
	public:
		Trivia();
		pair<string, string> getRandomQuestion();

	private:
		vector<pair<string, string>> questions;
};

#endif
