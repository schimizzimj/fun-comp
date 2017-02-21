// life.cpp
// This program runs a version of Conway's game of life
//
// Marcus Schimizzi
// 11/4/16

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "lifeboard.h"

int menu(Lifeboard&);

int main(int argc, char *argv[]) {
	
	Lifeboard myBoard;
		
	if (argc == 1) {
		menu(myBoard);
	}else if (argc > 2) {
		cout << "ERROR: Too many arguments." << endl;
		return 1;
	}else {
		char ch;
		int x, y;
		ifstream ifs;
		string operation;

		ifs.open(argv[1]);
		if (!ifs) {
			cout << "Error opening " << argv[1] << ". Try again.\n";
			return 1;
		}	
		
		ifs >> ch;
		while(!ifs.eof()) {
			switch (ch) {
				case 'a': ifs >> x >> y;
					  cout << x << " " << y << endl;
   					  myBoard.setCell(x + 1, y + 1);
					  break;
				case 'r': ifs >> x >> y;
					  myBoard.killCell(x + 1, y + 1);
					  break; 
				case 'p': myBoard.play();
					  break;
			}
			ifs >> ch;
		}
	}
	
}	

int menu(Lifeboard& myBoard) {
	char choice;
	int flag = 1, x, y;
	while(flag){
		cout << "Main Menu (Interactive Mode): \n";
		cout << "  a: set new live cell. \n";
		cout << "  r: kill living cell. \n";
		cout << "  n: advance to next iteration. \n";
		cout << "  q: quit the program. \n";
		cout << "  p: play continuously (ctrl+c to quit). \n";

		cout << "\n Your choice: ";
		cin >> choice; //Validate user input!!!
		if (choice == 'a' || choice == 'r') cin >> x >> y;

		switch (choice) {
			case 'a': myBoard.setCell(x,y);
				  cout << myBoard << endl;
				  break;
			case 'r': myBoard.killCell(x,y);
				  cout << myBoard << endl;
				  break;
			case 'n': myBoard.update();
				  cout << myBoard << endl;
				  break;
			case 'q': return 0;
				  
			case 'p': myBoard.play();
				  break;
		}		
	}
}
