// mysayings.cpp
// This prgram stores and manages sayings
// Initially requires a startup data file
// Has a menu of options including:
// 	-displaying all sayings currently in the database
// 	-entering a new saying
// 	-listing all sayings that contain a given word
// 	-save all sayings into a new text file
// 	-quitting the program
//
// Marcus Schimizzi
// 10/03/16

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void displaySayings(vector<string>&);
void newSaying(vector<string>&);
void findSayings(vector<string>&);
void saveSayings(vector<string>&);
//Include the prototype functions

int main() {
	vector<string> sayings; //Create a vector of strings
	string filename;
	string saying;
	fstream ifs; //Declare fstream object
	int userChoice;
	
	cout << "Hello! Welcome to your own personal sayings manager!\n";
	cout << "Enter the name of the startup file: ";
	cin >> filename;
	ifs.open(filename);
	//Prompt user for a startup filename and open that file

	if(!ifs) {
		//Check to verify that the file exists, return error if not
		cout << "error opening file " << filename << endl;
		return 1;
	}

	getline(ifs, saying);
	while(!ifs.eof()) {
		//Populates the vector with strings from the file
		sayings.push_back(saying);
		getline(ifs, saying);
	}
	sayings.pop_back(); //Deletes extra space at the end

	bool flag = true;
	while(flag) {
		//Loop through the menu options until user selects quit
		cout << "Here are the tasks you can perform: \n";
		cout << "1: Display all sayings.\n";
		cout << "2: Enter a new saying.\n";
		cout << "3: List sayings that contain a given word.\n";
		cout << "4: Save all sayings in a new text file.\n";
		cout << "5: Quit.\n";
		cout << "Your choice: ";

		cin >> userChoice;
		cout << endl;

		switch(userChoice) {
			//Take user's choice and use SWITCH to select it
			case 1: displaySayings(sayings);
				break;
			case 2: newSaying(sayings);
				break;
			case 3: findSayings(sayings);
				break;
			case 4: saveSayings(sayings);
				break;
			case 5: flag = false; //Change flag and end loop
				cout << "Goodbye!" << endl;		
				break;
		}
	}
	
}

void displaySayings(vector<string>& sayings) {
	//Displays the contents of the vectors
	for (auto it = sayings.begin(); it < sayings.end(); it++) 
		cout << *it << endl; //Use iterator to display each string
	cout << endl;
}

void newSaying(vector<string>& sayings) {
	//Appends the vector with a new saying
	string newSaying;
	cout << "Enter your new saying: ";
	cin.ignore(); //Ignores new line character from user choice selection
	getline(cin, newSaying);
	sayings.push_back(newSaying);
}

void findSayings(vector<string>& sayings) {
	//Searches for strings in the vector that have a user-selected word
	string userWord;
	cout << "Enter the word you would like to find: ";
	cin >> userWord;

	for (auto it = sayings.begin(); it < sayings.end(); it++) {
		//Runs through every string in the vector
		if ((*it).find(userWord) != string::npos) 
			//Checks to see if .find() can find the word
			//If so, it displays the string
			cout << *it << endl;
	}
	cout << endl;
}

void saveSayings(vector<string>& sayings) {
	//Saves sayings into a new file with a name prompted by the user
	cout << "Name for new file: ";
	string filename;
	cin >> filename;

	ofstream ifs(filename); //Creates ofstream object as user filename
	for (auto it = sayings.begin(); it < sayings.end(); it++) {
		//Saves each saying to a new line in the new file
		ifs << *it << '\n';
	}	
}
