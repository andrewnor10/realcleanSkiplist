#include "Skiplist.h"
#include "ComputerScientist.h"
#include <iostream>
using namespace std;

skipList::skipList() {
	header = nullptr;
	level = 1;
	sizeOfList = 0;
} //end default constructor

void skipList::createNode(ComputerScientist& data, int NodeLevel, Node*& newNode) {
	newNode = new Node(data, NodeLevel);
	newNode->forward = new Node * [NodeLevel];
	for (int i = 0; i < NodeLevel; i++)
	{
		newNode->forward[i] = nullptr; // Level is 0 no 3 need to investigate
	}
	
} // end createNode

skipList::~skipList() {
	deleteList();
} // end destructor

// Generate a random level for how high the node will go
int skipList::randomLevel() {
	int level = 1;
	while (rand() % 2) {
		level++;
	}
	return level;
} // end randomLevel


void skipList::insert(ComputerScientist& data) 
{
	if (sizeOfList == 8)
	{
		cout << "stopPoint";
	}
	Node* current = header; // Main iterator
	Node** update = new Node * [level]; // Trailer to keep track of the pointers
	if (header == nullptr)
	{
		int newLevel = randomLevel();
		Node* newNode;
		
		createNode(data, newLevel, newNode);
		header = newNode;
		level = newLevel;

		sizeOfList++;
		newNode = nullptr;
		delete[] update;
		return;
	}
	
	for (int i = level - 1; i >= 0; i--)
	{ // Traverse the list from the top level
	cout << current <<  " " << current->forward[i] << endl;
		while (current->forward[i] != nullptr)
		{ // Traverse the list until the next node is greater than the key
			if (current->forward[i]->data != nullptr && *(current->forward[i]->data) < data)
			{
				cout << *(current->forward[i]->data) << " " << (data) << endl;
				current = current->forward[i];
			}
			else
			{
				break;
			}
		}
		update[i] = current;
	}
	current = current->forward[0];

	if (current == nullptr || !(*(current->data) == data))
	{ // If the key is not in the list
		int newLevel = randomLevel();
		if (newLevel > level)
		{ // If the new level is greater than the current level
			Node** temp = new Node * [newLevel];
			std::copy(update, update + level, temp);
			for (int i = level; i < newLevel; i++)
			{
				temp[i] = header;
			}
			delete[] update;
			update = temp;
			level = newLevel;
		}
		Node* newNode;
		createNode(data, newLevel, newNode);

		for (int i = 0; i < newLevel; i++)
		{ // Insert the new node into the list
			newNode->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = newNode;
		}
		sizeOfList++;
	} 
	delete[] update;
} //end insert


void skipList::remove(ComputerScientist data)
{
	Node* current = header;
	Node** update = new Node*[level];
	for (int i = level - 1; i >= 0; i--)
	{
		while (current->forward[i] != nullptr && *(current->forward[i]->data) < data)
		{
			current = current->forward[i];
		}
		update[i] = current;
	}
	current = current->forward[0];
	if (current != nullptr && *(current->data) == data)
	{
		for (int i = 0; i < level; i++)
		{
			if (update[i]->forward[i] != current)
			{
				break;
			}
			update[i]->forward[i] = current->forward[i];
		}
		delete current;
		while (level > 0 && header->forward[level - 1] == nullptr)
		{
			level--;
		}
		sizeOfList--;
	}
	delete[] update;
}	// end remove	

void skipList::print() {
	// Print the contents on each level
	for (int i = 0; i < level; i++)
	{
		Node* current = header->forward[i];
		cout << "Level " << i << ": ";
		while (current != nullptr)
		{
			cout << *(current->data) << " ";
			current = current->forward[i];
		}
		cout << endl;
	}
}
int skipList::size() {
	return sizeOfList;
}

void skipList::deleteList() {
	// Delete the list
	if (header == nullptr)
	{
		return;
	}
	Node* current = header->forward[0];
	while (current != nullptr)
	{
		Node* next = current->forward[0];
		delete current;
		current = next;
	}
	delete header;
}


	
