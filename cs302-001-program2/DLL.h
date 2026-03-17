//*************************************************************
// Billy Rodriguez  CS302  DLL Header File
//
// This is the header for the doubly linked list
//*************************************************************

#ifndef DLL_H
#define DLL_H


#include "rapland.h"

//Node Class [convert to any data type]
template <typename T>
class Node
{
	public:
		Node(const T& data);	//constructor

		T data;			//object data
		string triviaQuestion;	//question
		string triviaAnswer;	//answer

		Node<T> *next;		//Node next
		Node<T> *prev;		//Node previous

};


//DLL Class [convert to any data type]
template <typename T>
class DLL
{
	public:
		DLL();					//constructor
		~DLL();					//destructor
		Node<T> *getHead();
		void insertAtEnd(const T& data);	//insertion
		void remove(const T& data);		//removal
		void askTrivia(Node<T> *node, Player &player);	//ask trivia questions
		bool search(const T& data) const;	//search
		void display() const;			//display
		
	private:
		Node<T> *head;
		Node<T> *tail;
		
		void insertRecursive(Node<T> * &current, Node<T> *prev, const T &data);
		void displayRecursive(Node<T> *current) const;
		Node<T> *searchRecursive(Node<T> *current, const T &data) const;
};

#include "DLL.tpp"
			
#endif
