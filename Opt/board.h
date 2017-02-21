// board.h
// The class interface for the Board class (serves as the board for an 
// Othello game)
//
// Marcus Schimizzi

#include <vector>

class Board {
  public:
    Board();
    Board(int);
    ~Board();
    void print();
  private:
  vector<vector<char>> board;
};
