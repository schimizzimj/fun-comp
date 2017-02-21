#include <iostream>
#include <cmath>
#include <math.h>
#include "polarfn.h"
using namespace std;

int main() {

	double x, y;
	cout << "Please enter x and y (in that order): ";
	cin >> x >> y; //Get the x and y coordinates from user
	
	cout << "The radius of these coordinates is: " << findRadius(x,y) << 
	endl;
	
	cout << "The angle of these coordinates is: " << findAngle(x,y) << 
	" radians" << endl;
	
	findQuad(x,y); //Output all of the results to user
	return 0;

}

