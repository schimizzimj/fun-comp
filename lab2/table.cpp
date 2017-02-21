#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

	// grab the inputs from the user
	int nCol,nRow;
	
	cout << "Please enter the number of columns: ";
	cin >> nCol;
	
	cout << "Please enter the number of rows: ";
	cin >> nRow;

	cout << "*"; 
	for (int k = 1; k <=  nCol; k++) {
	 cout << setw(5) << k;
	 }	
	 cout << endl;
	 // create column headers and return to next line
	
	for (int i = 1; i <=  nRow; i++) {
	
		cout << i; // create row headers
	
		for (int j = 1; j <= nCol; j++) {
			
			cout << setw(5) << (j*i); //create inner multiplication table
	
		}
		
		cout << endl;
	}
	
	
}
