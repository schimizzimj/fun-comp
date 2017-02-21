/* 	menucalc

	This program acts as a simple text-based four-function calculator.
	
	Marcus Schimizzi
	9/12/16
*/

#include <iostream>
#include <iomanip>
using namespace std;

double addition(double,double);
double subtraction(double,double);
double multiplication(double,double);
double division(double,double); //Include prototype functions

int main(){
	
	int cond = 1;
	cout << "Hello!" << endl;
	while (cond){
	
		int op; //Initialize variable for user-chosen operation
		
		cout << "What would you like to do?" << endl;
		cout << " " << setw(5) << "1. Addition" << endl;
		cout << " " << setw(5) << "2. Subtraction" << endl;
		cout << " " << setw(5) << "3. Multiplication" << endl;
		cout << " " << setw(5) << "4. Division" << endl;
		cout << " " << setw(5) << "5. Quit Program" << endl;
		cout << "Enter your choice: ";
		cin >> op; //Display choices to user and take input
		
		double x, y;
		cout << "Please enter two numbers: ";
		cin >> x >> y; //Take two numbers as input from user
		
		cout << "Inputs: " << x << ", " << y << endl; 
		switch (op) {
			//Use SWITCH statement to run user-chosen operation
			case 1 : 
				cout << "(" << x << ") + (" << y << ") = " << 
				addition(x,y) << endl;
				break;
			case 2 :
			 	cout << "(" << x << ") - (" << y << ") = " << 
			 	subtraction(x,y) << endl;
			 	break;
			case 3 :
				cout << "(" << x << ") * (" << y << ") = " <<
				multiplication(x,y) << endl;
				break;
			case 4 :
				cout << "(" << x << ") / (" << y << ") = " <<
				division(x,y) << endl;
				break;
			case 5 :
				cout << "Thank you! Goodbye!" << endl;
				cond = 0;
		
		}
	}
	return 0;
}
		
double addition(double a, double b) {
	//Finds the sum of two numbers
		double c = a + b;
		return c;
}
	
double subtraction(double a, double b) {
	//Finds the difference between two numbers
		double c = a - b;
		return c;
}
	
double multiplication(double a, double b) {
	//Finds the product of two numbers
		double c = a * b;
		return c;
}
	
double division(double a, double b) {
	//Find the quotient of two numbers
		double c = a/b;
		return c;
}


