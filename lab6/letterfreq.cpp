//	letterfreq.cpp
//	This program counts the frequency of each letter of the alphabet as
//	they occur in the text contained in a text file. 
//
//	Marcus Schimizzi
//	10/13/16

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctype.h>
#include <iomanip>
using namespace std;

int main() {
	int letters[26];
	string filename;
	fstream ifs;
	char ch;
	int whiteCount = 0, letterCount = 0, charCount = 0;
	
	cout << "Enter the name of your input text file: ";
	cin >> filename;
	ifs.open(filename);
	//Prompt user for startup filename and open that file
	
	if(!ifs) {
		//Check to verify that the file exists, return error if not
		cout << "error opening file " << filename << endl;
		return 1;	
	}

	for (int k = 0; k < 26; k++) {
		letters[k] = 0;
	}

	ifs >> noskipws >> ch; //Uses noskipws to read in all characters
	while(!ifs.eof()) {
		charCount++; //Increments number of characters for all input
		if (isalpha(ch)) {
			letterCount++; //Increments if input is alphabetic
			ch = tolower(ch); //Sets all input letters to lowercase
			letters[ch - 97]++; 
				//Shifts char index into index of array
		}else if (isspace(ch)) {
			whiteCount++; //Increments if input is a whitespace
		}
		ifs >> noskipws >> ch;	
	}

	float whitePerc = ((float)whiteCount/charCount) * 100;
		//Calculates percentage of whitespace to total characters

	char x = 'a';
	int newLine = 0;
	for (int i = 0; i < 26; i++, x++) {
		//Outputs and formats counts for all letters
		cout << setw(3) << x << ":" << setw(8) <<  letters[i];
		newLine++;
		if (newLine % 6 == 0) cout << endl;
	}
	cout << "\n";
	cout << "There were " << letterCount << " letters.\n";
	cout << "There were " << charCount << " total characters.\n";	
	cout << "There were " << whiteCount << " white space characters.\n";
	cout << "White space percentage: " << setprecision(4) 
	<< whitePerc << "% \n";
}


