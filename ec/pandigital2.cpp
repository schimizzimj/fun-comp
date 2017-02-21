/*	Pandigital
	This program is used to find the largest pandigital prime number.
	
	Marcus Schimizzi
	9/14/16
*/

#include <iostream>
using namespace std;

int isPandigital(int);
int isPrime(int);
int countDigits(int);

int main() {
	int largest;
	for (int k = 1; k < 1000000000; k++) {
		if (isPandigital(k) && isPrime(k)) {
			largest = k;
		}
	}
	cout << "The largest pandigital and prime number is: " << largest << 
	endl;
	return 0;
}

int isPandigital(int x) {
	int nDigits = countDigits(x);
	for (int i = 1; i <= nDigits; i++) {
		int flag = 0;
		int y = x;
		
		while(y > 0) {
			int digit = y % 10;
			y /= 10;
			if (digit == i) {
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "This number is not pandigital." << endl;
			return 0;
		}
	}
	return 1;
}

int isPrime(int x) {
	int prime = 1;
	for (int i = 2; i <= x/2; i++) {
		int remainder = x % i;
		if (remainder == 0) {
			prime = 0;
		}
	}
	return prime;
}

int countDigits(int x) {
	int count = 0;
	while (x > 0) {
		count++;
		x /= 10;
	}
	return count;
}
