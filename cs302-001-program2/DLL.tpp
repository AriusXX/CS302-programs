//*************************************************************
// Billy Rodriguez  CS302  Board Game DLL implementation
//
// This is the implementation of the doubly linked list
//*************************************************************


#include "DLL.h"
#include "trivia.h"

//Node constructor
template <typename T>
Node<T>::Node(const T &data): data(data), next(nullptr), prev(nullptr)
{}

//DLL constructor
template <typename T>
DLL<T>::DLL(): head(nullptr), tail(nullptr)
{}

//DLL destructor
template <typename T>
DLL<T>::~DLL()
{
	Node<T> *current = head;
	while(current)
	{
		Node<T> *toDelete = current;
		current = current->next;
		delete toDelete;
	}
	head = tail = nullptr;
}

//access to head
template <typename T>
Node<T> *DLL<T>::getHead()
{
	return head;
}



//insert 
template <typename T>
void DLL<T>::insertAtEnd(const T& data)
{
	Node<T> *newNode = new Node<T>(data);
	if(!head)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

}


//removal
template <typename T>
void DLL<T>::remove(const T &data)
{
	Node<T> *current = head;
	while(current)
	{
		//connections
		if(current->data == data)
		{
			if(current->prev) current->prev->next = current->next;
            		if (current->next) current->next->prev = current->prev;
            		if (current == head) head = current->next;
            		if (current == tail) tail = current->prev;
            		delete current;
			return;
		}
		
		//traverse
		current = current->next;
	}
}

//ask trivia questions
template <typename T>
void DLL<T>::askTrivia(Node<T> *node, Player &player)
{
	Trivia trivia;
	pair<string, string> question = trivia.getRandomQuestion();


	cout << "Trivia time for " << player.getName() << "! \n ";
	cout << question.first << endl;
	
	string userAnswer;
	getline(cin, userAnswer);

	//converting client's answer to all lowercase
	for(int i = 0; i < userAnswer.size(); i++)
	{
		if(userAnswer[i] >= 'A' && userAnswer[i] <= 'Z')
		{
			userAnswer[i] = userAnswer[i] + 32;	//convert to lowercase
		}
	}

	//have correct answer string have a defined name
	string correctAnswer = question.second;
	
	//converting right answer to all lowercase
	for(int i = 0; i < correctAnswer.size(); i++)
	{
		if(correctAnswer[i] >= 'A' && correctAnswer[i] <= 'Z')
		{
			correctAnswer[i] = correctAnswer[i] + 32;	//convert to lowercase
		}
	}

	//correct answer to the trivia
	if(userAnswer == correctAnswer)
	{
		cout << "Correct! You earn 10 points!\n";
		cout << endl;
		player += 10;
	}


	//wrong answer to the trivia
	else
	{
		cout << "Wrong, -5 points! The correct answer was: " << correctAnswer << endl;
		cout << endl;
		player -= 5;
	}

}	

//search wrapper
template <typename T>
bool DLL<T>::search(const T &data) const
{
	return searchRecursive(head, data) != nullptr;
}

//search recursive
template <typename T>
Node<T> *DLL<T>::searchRecursive(Node<T>* current, const T& data) const 
{
	if (!current) return nullptr;
    	if (current->data == data) return current;

    	return searchRecursive(current->next, data);
}

//display wrapper
template <typename T>
void DLL<T>::display() const
{
	displayRecursive(head);
}

//display recursive
template <typename T>
void DLL<T>::displayRecursive(Node<T> *current) const
{
	if(!current)
	{
		cout << endl;
		return;
	}
	
	cout << current->data << " <-> ";
	displayRecursive(current->next);
}





