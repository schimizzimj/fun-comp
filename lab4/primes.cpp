/*	primes.cpp
 *	This program uses the sieve of Eratosthenes algorithm to find
 *	the prime numbers between 1-1,000, then display them to the
 *	user in an orderly fashion.
 *
 *	Marcus Schimizzi
 *	9/19/16
 */

#include <iostream>
#include <iomanip>
using namespace std;

int isPrime(int);

int main() {
	//Create initial array of all 1s
	int primes[1000], mult;

	for (int i = 0; i <= 999; i++) {
		primes[i] = 1;
	}

	for (int j = 2; j <= 999; j++) {
		//Uses Sieve of Eratosthenes to mark where all primes are
		int x = 2;
		if (primes[j] == 1) {
			//Checks for numbers labeled primes
			//and then finds all of the multiples
			mult = j;
			while (mult * x <= 999) {
				primes[mult*x] = 0;
				x++;
			}		
		}		
	}

	int myPrimes[300], count = 0;
	for (int k = 2; k <= 999; k++) {
		//This loop puts all primes in an array
		if (primes[k] == 1) {
			myPrimes[count] = k;
			count++;
		}
	}
	
	int nEntry = 0, m = 0;
	while (myPrimes[m]) {
		//Displays the primes in a tidy format
		cout << setw(5) << myPrimes[m];
		m++;
		nEntry++;
		if (nEntry == 10) {
			//Ends the line at ten entries
			nEntry = 0;
			cout << endl;
		}
	}
	cout << endl;
}
