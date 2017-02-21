/*This program uses Coulomb's law to compute the electric force between 
two particles */
#include <iostream>
using namespace std;

int main()
{
	float k; float q1; float q2; float r;
	
	k = 8.99 * 1000000000; //Coulomb's Law Constant (Nm^2/C^2)
	
	cout << "Please enter the charge on object 1 in Coulombs: ";
	cin >> q1; //input charge of q1
	
	cout << "Please enter the charge on object 2 also in Coulombs: ";
	cin >> q2; //input charge of q2
	
	cout << "Please enter the distance between the two particles in meters: ";
	cin >> r; //input distance between two particles
	
		if (r <= 0) {
			return 0;
		}; /*checks if distance is input as positive value; if not, 
		exits program*/
	
	float F = (k * q1 * q2)/(r*r); //use coulomb's law formula
	
	cout << "The electric force between particles is: " << F << " N" << 
	endl; //output force
	
	
	return 0;
}
