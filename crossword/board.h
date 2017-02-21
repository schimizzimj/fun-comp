// board.h
// The class interface for the Board class
//
// Marcus Schimizzi 
// 11/16/16

class Board {
  public:
    Board();
    ~Board();
    void print();
    int addWord(string&);
  private:
    char solution[15][15];
    char puzzle[15][15];
    int words;
    vector<vector<string>> clues;
};
