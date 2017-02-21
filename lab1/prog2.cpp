//Football score calculator

#include <iostream>
using namespace std;

int main() {
	
	int nTD; int nXP; int nFG; int nSafe; int totScore; /*initializing 
	necessary variables*/
	
	cout << "How many touchdowns did the Irish score? ";
	cin >> nTD; //input TDs
	
	cout << "How many extra points did they score? ";
	cin >> nXP; //input extra points
	
	cout << "How many field goals did they score? ";
	cin >> nFG; //input field goals
	
	cout << "How many safeties did they score? ";
	cin >> nSafe; //input safeties
	
	totScore = 6*nTD + nXP  + 3*nFG	+ 2*nSafe; //calculate total score
	
	cout << "The Irish scored " << totScore << " points. G'Irish!" << 
	endl; //outputs the total score 
	



	return 0;
}
