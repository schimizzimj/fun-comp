/*	ndfootball.cpp
 *	This program has the wins and losses for ND football stored since
 *	1900, and gives a menu to the user for them to select various 
 *	operations of things to do with the data.
 *
 *	Marcus Schimizzi
 *	9/23/16
 */

#include <iostream>
#include <iomanip>
#include "nd_data.h"
using namespace std;

void dispRecord(int a[], int b[]);
void nWins(int a[], int);
void nLosses(int a[], int);
void winPerc(int a[], int b[]);
void moreWins(int a[], int);
void moreLosses(int a[], int); //Include prototype functions

int main() {
	//Display menu and take in user choice
	int choice;
	int cond = 1;
	while(cond) {	
		//Loop through menu and operations until user exits
		cout << "1: Display the record for a given year." << endl;
		cout << "2: List years with 'n' wins." << endl;
		cout << "3: List years with 'n' losses." << endl;
		cout << "4: Display winning percentage for a given year."
		<< endl;
		cout << "5: Display years with at least 'n' wins." << endl;
		cout << "6: Display years with at least 'n' losses." << 
		endl;
		cout << "7: Exit." << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		int length = sizeof(wins)/sizeof(int); //Finds length of arrays
		
		switch(choice) {
			//Chooses case based on user input
			case 1 : dispRecord(wins, losses);
				cout << endl;
				break;
			case 2 : nWins(wins, length);
				cout << endl;
				break;
			case 3 : nLosses(losses, length);
				cout << endl;
				break;
			case 4 : winPerc(wins, losses);
				cout << endl;
				break;
			case 5 : moreWins(wins, length);
				cout << endl;
				break;
			case 6 : moreLosses(losses, length);
				cout << endl;
				break;
			case 7 : return 0;
		} 
	}	
}

void dispRecord(int wins[],int losses[]) {
	//Displays the record for a user given year
	cout << "Enter the year: ";
	int year;
	cin >> year;
	int aYear = year - 1900;
	cout << year << ":  Wins: " << wins[aYear] << " ; Losses: " <<
	losses[aYear] << endl;
	
}

void nWins(int wins[],int length) {
	//Displays years with an exact number of wins
	cout << "Enter number of wins: ";
	int nWins;
	cin >> nWins;
	cout << "Years with " << nWins << " wins: " << endl;
	for (int i = 0; i < length; i++) {
		if (wins[i] == nWins) {
		cout << (1900 + i) << " ";		
		}
	}
	cout << endl;
}

void nLosses(int losses[], int length) {
	//Displays years with an exact number of losses
	cout << "Enter number of losses: ";
	int nLosses;
	cin >> nLosses;
	cout << "Years with " << nLosses << " losses: " << endl;
	for (int i = 0; i < length; i++) {
		if (losses[i] == nLosses) {
			cout << (1900 + i) << " ";
		}
	}
	cout << endl;
}

void winPerc(int wins[],int losses[]) {
	//Calculates winning percentage for a given year
	cout << "Enter the year: ";
	int year;
	cin >> year;
	int aYear = year - 1900;
	double perc = (double)wins[aYear]/(wins[aYear] + losses[aYear]);
	cout << "The Irish winning percentage for " << year << " was: " <<
	perc << endl;
}

void moreWins(int wins[],int length) {
	//Displays years with at least a given number of wins
	cout << "Enter number of wins: ";
	int nWins;
	cin >> nWins;
	cout << "Years with more than " << nWins << " wins: " << endl;
	for (int i = 0; i < length; i++) {
		if (wins[i] >= nWins) {
			cout << (1900 + i) << " ";
		}
	}
	cout << endl; 	
}

void moreLosses(int losses[], int length) {
	//Displays years with at least a given number of losses
	cout << "Enter the number of losses: ";
	int nLosses;
	cin >> nLosses;
	cout << "Years with more than " << nLosses << " losses: " << endl;
	for (int i = 0; i < length; i++) {
		if (losses[i] >= nLosses) {
			cout << (1900 + i) << " ";
		}
	}
	cout << endl; 
}
