/*	grades.cpp
 *	This program reads in a list of grade values from a data file, then 
 *	computes their average and standard deviation. 
 *
 *	Marcus Schimizzi
 *	9/19/16
 */

#include <iostream>
#include <math.h>
using namespace std;

double average(int a[], int);
double deviation(int a[], int); //Declare prototypes

int main() {
	int grades[50];
	int x;
	int count = 0;
	
	while (x != -1) {
		cin >> x;
		grades[count] = x;
		count++; 
	} //Use inputs to form grades array
	count -= 1;
	double mean = average(grades, count); //Call average function
	double stdev = deviation(grades, count); //Call deviation function

	cout << "The average of the data is: " << mean << endl;
	cout << "The standard deviation is: " << stdev << endl;
}

double average(int a[], int count) {
	//Calculates the average of a data set
	
	int sum;
	for (int i = 0; i < count; i++) {
		sum += a[i];
	}
	double mean = (double)sum/count;
	return mean;
}

double deviation(int a[], int count) {
	//Calculate standard deviation for a data set

	double mean = average(a, count);
	double diff, variance = 0;

	for (int i = 0; i < count; i++) {
		diff = a[i] - mean;
		variance += diff * diff;
	}
	double dev = sqrt(variance/count);
	return dev;
}
