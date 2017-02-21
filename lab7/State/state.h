// state.h
// Interface for the State class
//
// Marcus Schimizzi
// 10/28/16

#include <string>
using namespace std;

class State {
	public:
		State();
		State(string, string, string, int, int, int);
		~State();
		void setPop(int);
		void setReps(int);
		string getAbb();
		string getName();
		string getCapital();
		int getPop();
		int getYear();
		int getReps();
		void print();
	private:
		string abb;
		string name;
		string capital;
		int pop;
		int year;
		int reps;
};
