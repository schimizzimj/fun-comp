#include <iostream>
using namespace std;

int main() {

	int count{0};
	float total{0};
	while (total < 1) {
		cout << setw(5) << count << fixed << setprecision(6) << setw(15) << total << endl;
		total += .01;
		count++;
	}
}
