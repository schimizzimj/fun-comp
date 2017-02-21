// lifeboard.h
// Class interface for the Lifeboard class
//
// Marcus Schimizzi
// 11/4/16

class Lifeboard {

	public:
		Lifeboard();
		~Lifeboard();
		char getCell(int, int);
		int checkNeighbors(int, int);
		void setCell(int, int);
		void killCell(int, int);
		void update();
		void play();
		friend ostream& operator<<(ostream&, Lifeboard&);

	private:
		
		char board[40][40];

};
