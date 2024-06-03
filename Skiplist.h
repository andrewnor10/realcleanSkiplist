#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include "ComputerScientist.h"
#include <string>
using namespace std;
class skipList {
	
	public:
		class Node {
		public:
			ComputerScientist* data;
			Node** forward;
			
			Node(ComputerScientist& passedData, int level = 0) {
				this->data = &passedData;
				forward = new Node * [level];
				for (int i = 0; i < level; i++) {
					forward[i] = nullptr;
				}
			}
			Node() {
				data = nullptr;
				forward = nullptr;
			}
			Node(const Node& rhs) {
				data = rhs.data;
				forward = rhs.forward;
			}
			bool operator == (const Node& rhs) const {
				return this->data == rhs.data;
			}
			bool operator < (const Node& rhs) const {
				{
					return this->data < rhs.data;
				}
			}
		};
		skipList();
		~skipList();
		void insert(ComputerScientist& data);
		void remove(ComputerScientist data);
		void print();
		int size();
		bool isEmpty();
		void clear();	
		void deleteList();
		skipList& operator = (const skipList& rhs);
		friend ostream& operator << (ostream &out, const skipList &list);
		int randomLevel();
		void createNode(ComputerScientist& data, int NodeLevel, Node*& newNode);
private:
	Node* header;
	int level; // Highest level of the list
	int maxLevel;
	int sizeOfList;
};

#endif