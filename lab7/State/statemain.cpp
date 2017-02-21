// statemain.cpp
// This program uses the State class to create a mini "database" with a 
// menu of options for a user 
//
// Marcus Schimizzi
// 10/28/16

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "state.h"

void printall(vector<State> &);
void popAbove(vector<State> &);
void popBelow(vector<State> &);
void enteredBefore(vector<State> &);
void nReps(vector<State> &);

int main() {

	ifstream ifs;
	string filename;
	string abb, name, capital, pop_s, year_s, reps_s;
	int pop, year, reps;
	vector<State> states;
	State st;

	cout << "Input the data file name: ";
	cin >> filename;
	ifs.open(filename);
	if (!ifs) {
		cout << "ERROR: " << filename << " does not exist" << endl;
		return 1;
	}
	
	char c = ifs.peek();
	while (c != EOF) {
		getline(ifs, abb, ','); getline(ifs, name, ',');
		getline(ifs, capital, ','); getline(ifs, pop_s, ',');
		getline(ifs, year_s, ','); getline(ifs, reps_s, '\n');
		pop = stoi(pop_s); year = stoi(year_s); reps = stoi(reps_s);
		st = State(abb, name, capital, pop, year, reps);
		states.push_back(st);
		c = ifs.peek();
	}
	
	int flag = 1, choice;		
	while (flag) { 
		cout << "Possible tasks:" << endl;
		cout << "1. Display all." << endl;
		cout << "2. Display states with population above a certain number." << endl; 
		cout << "3. Display states with population below a certain number." << endl;
		cout << "4. Display states that entered the union before a given year." << endl;
		cout << "5. Display states with a given number of representatives." << endl;
		cout << "6. Quit program" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice) {
			case 1: printall(states);
				break;
			case 2: popAbove(states);
				break;
			case 3: popBelow(states);
				break;
			case 4: enteredBefore(states);
				break;
			case 5: nReps(states);
				break;
			case 6: flag = 0;
				break;
		}
	}
	return 0;	
}

void printall(vector<State> &s) {
	for (auto it = s.begin(); it != s.end(); ++it) {
		it->print();
	}
}

void popAbove(vector<State> &s) {
	cout << "Enter population cutoff: ";
	int popCut;
	cin >> popCut;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->getPop() > popCut) {
			cout << it->getName() << endl;
			cout << "  Population: " << it->getPop();
			cout << "\n\n";
		}
	}
}

void popBelow(vector<State> &s) {
	cout << "Enter population cutoff: ";
	int popCut;
	cin >> popCut;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->getPop() < popCut) {
			cout << it->getName() << endl;
			cout << "  Population: " << it->getPop();
			cout << "\n\n";
		}
	}
}

void enteredBefore(vector<State> &s) {
	cout << "Enter cutoff year: ";
	int year;
	cin >> year;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->getYear() < year) {
			cout << it->getName() << endl;
			cout << " Year: " << it->getYear();
			cout << "\n\n";
		}
	}
}

void nReps(vector<State> &s) {
	cout << "Enter number of representatives: ";
	int reps;
	cin >> reps;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->getReps() == reps) {
			cout << it->getName() << endl;
		}
	}
}
