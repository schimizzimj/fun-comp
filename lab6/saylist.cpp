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
#include <list>
#include <fstream>
using namespace std;

void displaySayings(list<string>&);
void newSaying(list<string>&);
void deleteSaying(list<string>&);
void findSayings(list<string>&);
void saveSayings(list<string>&);
//Include the prototype functions

int main() {
	list<string> sayings; //Create a vector of strings
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
		//Populates the list with strings from the file
		auto it = sayings.begin();
		while (saying.compare(*it) > 0 && it != sayings.end()) ++it;
			//Moves iterator to the correct position
		if (it == sayings.end()) {
			//Handles case of string being the last alphabetically
			sayings.push_back(saying);
		}
		else{
			sayings.insert(it, saying);
		}
		getline(ifs, saying);
	}
	sayings.pop_front(); //Deletes extra space at the front

	bool flag = true;
	while(flag) {
		//Loop through the menu options until user selects quit
		cout << "Here are the tasks you can perform: \n";
		cout << "1: Display all sayings.\n";
		cout << "2: Enter a new saying.\n";
		cout << "3: Delete a saying. \n";
		cout << "4: List sayings that contain a given word.\n";
		cout << "5: Save all sayings in a new text file.\n";
		cout << "6: Quit.\n";
		cout << "Your choice: ";

		cin >> userChoice;
		cout << endl;

		switch(userChoice) {
			//Take user's choice and use SWITCH to select it
			case 1: displaySayings(sayings);
				break;
			case 2: newSaying(sayings);
				break;
			case 3: deleteSaying(sayings);
				break;
			case 4: findSayings(sayings);
				break;
			case 5: saveSayings(sayings);
				break;
			case 6: flag = false; //Change flag and end loop
				cout << "Goodbye!" << endl;		
				break;
		}
	}
	
}

void displaySayings(list<string>& sayings) {
	//Displays the contents of the lists
	int i = 1;
	for (auto it = sayings.begin(); it != sayings.end(); ++it, i++) 
		
		cout << i << ": "  << *it << endl; 
		//Use iterator to display each string
	cout << endl;
}

void newSaying(list<string>& sayings) {
	//Appends the list with a new saying
	string newSaying;
	cout << "Enter your new saying: ";
	cin.ignore(); //Ignores new line character from user choice selection
	getline(cin, newSaying);
	auto it = sayings.begin();
	while (newSaying.compare(*it) > 0 && it != sayings.end()) ++it;
		//Moves iterator to correct position for new string
	if (it == sayings.end()) {
		//Handles the case of the string being the last a
		//alphabetically
		 sayings.push_back(newSaying);
	}else {
		sayings.insert(it, newSaying);
	}
}

void findSayings(list<string>& sayings) {
	//Searches for strings in the list that have a user-selected word
	string userWord;
	cout << "Enter the word you would like to find: ";
	cin >> userWord;

	for (auto it = sayings.begin(); it != sayings.end(); ++it) {
		//Runs through every string in the list
		if ((*it).find(userWord) != string::npos) 
			//Checks to see if .find() can find the word
			//If so, it displays the string
			cout << *it << endl;
	}
	cout << endl;
}

void saveSayings(list<string>& sayings) {
	//Saves sayings into a new file with a name prompted by the user
	cout << "Name for new file: ";
	string filename;
	cin >> filename;

	ofstream ifs(filename); //Creates ofstream object as user filename
	for (auto it = sayings.begin(); it != sayings.end(); ++it) {
		//Saves each saying to a new line in the new file
		ifs << *it << '\n';
	}	
}

void deleteSaying(list<string>& sayings) {
	//Displays sayings to the user, and then lets them select a string to 
	//delete
	displaySayings(sayings);
	cout << "Enter the number of the saying to erase: ";
	int choice;
	cin >> choice;
	auto it = sayings.begin();
	for (int i = 1; i < choice; i++) it++; 
		//Moves iterator to correct position
	sayings.erase(it);
}
