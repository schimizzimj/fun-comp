#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double findAngle(double, double);
double findRadius(double, double);
int findQuad(double, double); //Include prototype functions

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

double findRadius(double a, double b) {
	//Finds the radius given the x and y coordinates

	double radius;
	radius = sqrt (pow(a,2.) + pow(b,2.));
	return radius;

}

double findAngle(double a, double b) {
	//Finds the angle in radians given the x and y coordinates

	double theta;
	theta = atan2(b,a);
	return theta; 

}

int findQuad(double x, double y) {
	//Returns the quadrant of the point based on x and y coordinates

	if(x==0 && y==0){
		cout << "The point is at the origin.";
	}else if(x==0 && y!=0){
		cout << "The point is on the x-axis.";
	}else if(x!=0 && y==0){
		cout << "The point is on the y-axis.";
	}else if(x>0 && y>0){
		cout << "The point is in the first quadrant.";
	}else if(x<0 && y>0){
		cout << "The point is in the second quadrant.";
	}else if(x<0 && y<0){
		cout << "The point is in the third quadrant.";
	}else if(x>0 && y<0){
		cout << " The point is in the fourth quadrant.";
	}else{
		cout << "ERROR: This point does not exist.";
	} //Use IF and ELSE IF to return the proper quadrant
	cout << endl;
	return 0;
}
