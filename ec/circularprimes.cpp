/*	circularprimes.cpp
 *	This program is used to find the circular primes (numbers
 *	where all rotations of the digits are also prime) below
 *	one million. 
 *
 *	Marcus Schimizzi
 *	9/22/16
 */

#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int);
int rotate(int);
int getDigits(int);
int checkRotate(int);

int main() {
	int count = 0; //Counts number of circular primes
	int max = 1000000;
	for (int i = 1; i <= max; i++) {
		//Loops through all values from 1 through to the max
		if (isPrime(i)) {
			//Checks to make sure the number itself is prime
			if (checkRotate(i)){
				//Checks to see if rotations are prime,
				//if so, it adds to count
				count++;
			}			
		}
	}

	cout << "There are " << count << " primes below " << max << "." << endl;}

int isPrime(int a) {
	//Checks to see if the inputted number is prime
	if (a == 1) {
		return 0;	
	}else if(a <= 3) {
		return 1;
	}else if((a % 2) == 0 || (a % 3) == 0) {
		return 0;
	} 
	int i = 5;
	while (i*i <= a) {
		if ((a % i) == 0 || (a % (i + 2) == 0)) {
			return 0;
		}
		i += 6;
	}
	return 1;
}

int rotate(int a) {
	//Rotates input number, changes ones digit to highest digit and shifts
	//everything else to the right; i.e. 765 converts to 576
	int ones = a % 10; 
	int newA = a / 10;
	int digits = getDigits(a);
	for (int i = 1; i < digits; i++) {
		ones *= 10;
	}
	newA += ones;
	return newA;
}

int getDigits (int a) {
	//Returns the number of digits in an inputted number
	return a > 0 ? log10 ((double) a) + 1 : 1;
}

int checkRotate(int a) {
	//Checks all of the rotations of a number to see if they are prime
	int digits = getDigits(a);
	int rotate_a = a;
	for (int i = 1; i < digits; i++) {
		rotate_a = rotate(rotate_a);
		if (!(isPrime(rotate_a))) {
			return 0;
		}
	}
	return 1;		
}
