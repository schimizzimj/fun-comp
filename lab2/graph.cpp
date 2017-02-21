#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;

int main() {

	cout << "A plot of y=|x^7-14x^5+49x^3-36x| from x=-3 to 3" << endl;
	cout << setw(7) << "X" << setw(7) << "Y" << endl;
	
	double iChar = 1.5; //character increment, each character corresponds to another of this number
	
	double max=0.,min=300.,locMin,locMax;
	for (double i = -3.; i <= 3.; i+=0.05) {
	
		double y = abs(pow(i,7.)-(14*pow(i,5.))+(49*pow(i,3.))-(36*i));
		
			if (y > max){
				max = y;
				locMax = i;
			} //find the max and its location
			if (y < min){
				min = y;
				locMin = i;
			} //find the min and its location
		
		cout << fixed << setprecision(2) << setw(7) << i << setw(7) << y << setw(4);
		
			int nChar = y/iChar;
			for (int j = 1; j <= nChar; j++) {
		
				cout << "#";
		
			}
		cout << endl;
	}
	cout << "The maximum of " << fixed << setprecision(2) << max << " was found at x=" << locMax << "."<< endl;
	cout << "The minimum of " << fixed << setprecision(2) << min << " was found at x=" << locMin << "."<< endl;
	return 0;
}
