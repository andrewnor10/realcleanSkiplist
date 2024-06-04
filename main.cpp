#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include "ComputerScientist.h"
#include "Skiplist.h"
using namespace std;

vector<string> split(const string& s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

// Helper function to Read in the CStist info and puts it into vector of CStist* and then shuffled thier order
vector<ComputerScientist*> load(const string& filename) {
	vector<ComputerScientist*> list;
	std::ifstream file(filename);

	std::string str;
	while (std::getline(file, str))
	{
		vector<string> tokens = split(str, ',');

		list.push_back(new ComputerScientist(tokens[1], tokens[2], tokens[3], stoi(tokens[0])));
	}

	auto rng = default_random_engine{};
	//I wonder why I need this?
	std::shuffle(std::begin(list), std::end(list), rng);
	return list;
}

int main() {
	vector<ComputerScientist*> list = load("csListSmall.txt");
	skipList skipList;
	for (auto& c : list) {
		skipList.insert(*c);
	}
	
	skipList.print();
	return 0;
}