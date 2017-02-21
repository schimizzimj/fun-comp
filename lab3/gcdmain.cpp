/* 	gcdmain
	This program takes an input of two numbers from the user and outputs 
	their greatest common divisor. 
	
	Marcus Schimizzi
	9/12/16
*/

#include <iostream>
using namespace std;

int gcd(int a,int b); //Include function prototype

int main(){
	
	int x, y;
	cout << "Please enter two numbers for their GCD: ";
	cin >> x >> y; //Receive two numbers from the user
	
	int z = getgcd(x,y); //Call getgcd() function
	
	cout << "The GCD of these two numbers is: " << z << endl; 
	//Output to user
}

int getgcd(int a, int b) {
	//This function finds the greatest common divisor given two numbers
	
	int c;
	while (a != 0) {
		c = a; a = b%a; b = c;
	}
	return b;
} 
