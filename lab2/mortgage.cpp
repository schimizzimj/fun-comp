#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	//take inputs from the user
	double prin, intRate, mPay;
	
	cout << "Please input the principal amount (US dollars): ";
	cin >> prin;
	
	cout << "Please input the interest rate as a decimal (i.e. 5% = 0.05): ";
	cin >> intRate;
	
	//make sure interest rate is valid
	int y = 1;
	while (y) {
		if (intRate <= 0 ){
			cout << "This is not a valid interest rate. Please enter another: ";
			cin >> intRate;
		}else{
			y = 0;
		}
	}
	
	cout << "Please input your desired monthly payment: ";
	cin >> mPay;
	
	//check to make sure payment is large enough
	int x = 1;
	while (x) {
		if (((intRate * prin)/12) >= mPay){
			cout << "Your monthly payment is not high enough! Please enter another: ";
			cin >> mPay;
		}
		else {
			x = 0;
		}
	}
	
	//create amortization table
	
	bool stop = true; int nMonth = 1; double totPaid = prin; //initialize and define variables
	
	cout << "Month" << setw(12) << "Payment" << setw(12) << 
	"Interest" << setw(12) << "Balance" << endl;
	
	while (stop) {
		
		double interest = (intRate * prin)/12; //calculate interest rate
		
		prin = prin + interest;
		totPaid += interest;   //tracker for total amount paid
		
		if (prin < mPay) {
			mPay = prin;
			stop = false;
		} //stop condition and makes sure balance never goes below zero
		prin = prin - mPay; //calculate end-of-month balance
		
		cout << setw(3) << nMonth << setw(6)<< "$" << setw(6) << fixed << setprecision(2) << setw(6) << mPay << setw(6) << "$" << setw(8) << 
		interest << setw(6) << "$" << setw(10) << prin << endl; //display table
		
		if (prin > 0){	
			nMonth++; //increase month counter
		}
	}
	
	int months = nMonth%12;			
	int years = (nMonth-months)/12;			//calculate years and months to pay off 

	cout << "\nYou paid a total of $" << fixed << setprecision(2) << totPaid << " over " << years << " years and " << months << " months." << 
	endl;

}
