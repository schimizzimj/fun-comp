// crossword.cpp
// This program creates a crossword anagram puzzle as well as the solution
// for the puzzle
//
// Marcus Schimizzi
// 11/14/16

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

#include "board.h"
void sortWords(vector<string>&);
bool greaterString(const string&, const string&);
string stringToUpper(string&);

int main() {
  vector<string> words;
  string input, upper;

  cin >> input;
  upper = stringToUpper(input);
  while(input != "." && words.size() < 19) {
    //Populates the vector with the inputted words and converts them all to 
    //uppercase
    words.push_back(upper);
    cin >> input;
    upper = stringToUpper(input);
  }
  sortWords(words); 
  Board board;
  int added;
  for (auto iv = words.begin(); iv != words.end(); ++iv) {
    //Iterates through inputted words and places them on the board
    added = board.addWord(*iv);
    if (!(added)) break;
  }
  board.print();
}

void sortWords(vector<string> &a) {
  //Sorts words in descending length
  sort(a.begin(), a.end(), greaterString); 
}

bool greaterString(const string& a, const string& b) {
  //Returns whether one string is longer than another, used for sort() function
  return a.size() > b.size();
}

string stringToUpper(string &s) {
  //Converts string to uppercase
  for (auto it = s.begin(); it != s.end(); ++it) *it = toupper(*it);
  return s;
}
