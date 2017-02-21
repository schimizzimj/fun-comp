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
    words.push_back(upper);
    cin >> input;
    upper = stringToUpper(input);
  }
  sortWords(words); 
  Board board;
  for (auto iv = words.begin(); iv != words.end(); ++iv) board.addWord(*iv);
  board.print();
}

void sortWords(vector<string> &a) {
 sort(a.begin(), a.end(), greaterString); 
}

bool greaterString(const string& a, const string& b) {
  return a.size() > b.size();
}

string stringToUpper(string &s) {
  for (auto it = s.begin(); it != s.end(); ++it) *it = toupper(*it);
  return s;
}
