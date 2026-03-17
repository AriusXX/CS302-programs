//*************************************************************
//Billy Rodriguez  CS302  shamrock race datastruct-header
//
//This is the header file for the tree data structure
//*************************************************************

#include "shamrock.h"

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#pragma once

//Node
class Node
{
	public:
		Node();						//default constructor
		Node(shared_ptr<ShamrockRace> &data);		//parameterized constructor
		unique_ptr<Node>& getLeft();			//getter
		unique_ptr<Node>& getRight();			//getter
		bool compareKey(const string &key) const;	//comparison
		void create();					//create
		void displayNode() const;			//display

		//getters
		string getKey() const { return key; }
		shared_ptr<ShamrockRace> getData() const { return data; }
		
	
	private:
		string key;					//contestant name
		shared_ptr<ShamrockRace> data;			//data
		unique_ptr<Node> left;				//tree left side
		unique_ptr<Node> right;				//tree right side
};


//Binary Search Tree
class BST
{
	public:
		BST();						//constructor
		bool insert(shared_ptr<ShamrockRace> &data);	//insert wrapper
		bool display() const;				//display wrapper
		bool remove(const string &key);			//remove wrapper
		bool removeAll();				//remove all wrapper
	
	private:
		unique_ptr<Node> root;							//pointer to root
		bool insert(unique_ptr<Node> &node, shared_ptr<ShamrockRace> &data);	//insert
		bool display(const unique_ptr<Node> &node) const;			//display
		bool remove(unique_ptr<Node> &node, const string &key);			//remove
};

#endif
