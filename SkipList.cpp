#include "Skiplist.h"
#include "ComputerScientist.h"
#include <iostream>
using namespace std;

skipList::skipList() {
	header = nullptr;
	level = 0;
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
	if (header == nullptr)
	{

		int newLevel = sizeOfList + 1;
		Node* newNode;
		createNode(data, newLevel, newNode);
		header = new Node(newLevel);
		for (int i = 0; i < newLevel; i++)
		{
			header->forward[i] = newNode;
		}
		level = newLevel;

		sizeOfList++;
		// newNode = nullptr;
		return;
	}
	Node* current;
	Node** update = new Node * [level]; // Main iterator
	 // Trailer to keep track of the pointers

	for (int i = level - 1; i >= 0; i--)
	{ // Traverse the list from the top level
		current = header->forward[level - i];

		cout << current << " " << current->forward[i]->data->getID() << endl;
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
		int newLevel = sizeOfList + 1;
		Node* newNode;
		createNode(data, newLevel, newNode);

		if (newLevel > level)
		{ // If the new level is greater than the current level
			// Allocate new arrays with the new level size
			Node** newUpdate = new Node * [newLevel];
			Node** newForward = new Node * [newLevel];

			// Copy existing elements up to the current level
			std::copy(update, update + level, newUpdate);
			std::copy(header->forward, header->forward + level, newForward);

			// Initialize new elements in newUpdate
			for (int i = level; i < newLevel; i++)
			{
				newUpdate[i] = newNode;
			}

			// Initialize new elements in newForward to newNode
			for (int i = level; i < newLevel; i++)
			{
				newForward[i] = newNode;
			}

			// Free old memory
			delete[] update;
			delete[] header->forward;

			// Reassign pointers
			update = newUpdate;
			header->forward = newForward;
			level = newLevel;
		}


		for (int i = 0; i < newLevel; i++)
		{ // Insert the new node into the list
			newNode->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = newNode;
		}
		sizeOfList++;
	}
	delete[] update;
} //end insert


void skipList::remove(ComputerScientist& data)
{
	Node* current = header;
	Node** update = new Node * [level];
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
			cout << (current->data->getID()) << " ";
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



