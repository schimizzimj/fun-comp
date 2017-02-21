

using namespace std;

int main() {
	fstream ifs("startup.txt");
	string strObject;
	getline(ifs, strObject); //getline() replaces content of the string
	while(!ifs.eof()) {
		cout << strObject << endl;
		getline(ifs, strObject);
	} //Most flexible method, use this one on the homework

	fstream ifs2("startup.txt");
	char strArray[256];
	ifs2.getline(strArray, 255);
	while (!ifs2.eof()) {
		cout << strArray << endl;
		ifs2.getline(strArray, 256);
	} //Potentially more flexible, but less flexible for our applications
}
