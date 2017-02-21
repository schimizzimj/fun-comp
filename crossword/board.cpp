// board.cpp
// The class implementation for the Board class
//
// Marcus Schimizzi
// 11/16/16

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std; 

#include "board.h"

Board::Board()
{
  //Initializes the boards with the correct characters 
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++) {
      puzzle[i][j] = '#';
      solution[i][j] = '.';
    }
  words = 0; 
  }
}

Board::~Board()
{ }

void Board::print()
{
  //Formats and prints out the solution, puzzle, and clues for the board 
  cout << "Solution: \n";
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++) {
      cout << solution[i][j];
    }
  cout << endl;
  }

  cout << "\n\nPuzzle: \n";
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++) {
      cout << puzzle[i][j];
    }
  cout << endl;
  }
  
  cout << "\n\nClues: \n";
  for (auto it = clues.begin(); it != clues.end(); ++it) {
    cout << setw(2) << it->at(1) << ", " << setw(0) << it->at(1) << " ";
    cout << setw(6) << it->at(2) << " ";
    string s = it->at(3);
    for(auto is = s.begin(); is != s.end(); ++is) {
      //Creates a random anagram for a clue (random_shuffle caused my code not to 
      //work, so I used this instead)
      int x = rand() % (s.length()/sizeof(char));
      int y = rand() % (s.length()/sizeof(char));
      swap(s[x], s[y]);
    }
    cout << s << endl;
  }
}

int Board::addWord(string& a)
{
  int length = a.size()/sizeof(char);
  if (words == 0) {
    //Places the first word onto the board
    int shift = (15 - length)/2;
    for (auto it = a.begin(); it != a.end(); ++it) {
      puzzle[7][shift] = ' ';
      solution[7][shift] = *it;
      shift++;
    }
  words++;
  return 1;
  }else{
    //Places every word after the first
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < 15; j++) {
        for(int k = 0; k < 15; k++) {
          //Cycles through all letter in the string and tries to match them with 
          //letters on the board
          if (a[i] == solution[j][k]) {
            if (solution[j+1][k] == '.' && solution[j-1][k] == '.') {
              //Checks to see if the matching word is horizontal or vertical
              if (j - i >= 0 && j + (length - i - 1) < 15) {
                //Checks to see if word would fit within the bounds of the puzzle
                bool valid = true;
                int row = j - i;
                if (isalpha(solution[row - 1][k]) || isalpha(solution[row + length][k])) {
                  valid = false;
                }
                for (int m = 0; m < length; m++, row++) {
                  if (row != j && (isalpha(solution[row][k+1]) || isalpha(solution[row][k-1]))) {
                    valid = false;
                  }
                }
                //Makes sure there are no other words in the way
                if (valid) {
                  //Places the word if the shared letter satisfies all conditions
                  row = j - i;
                  for (int m = 0; m < length; m++, row++) {
                    solution[row][k] = a[m];
                    puzzle[row][k] = ' ';
                  }
                  words++;
                  vector<string> newClue;
                  newClue.push_back(to_string(j));
                  newClue.push_back(to_string(k));
                  newClue.push_back("Down");
                  newClue.push_back(a);
                  clues.push_back(newClue);
                  return 1;
                }
              }
            }else if (solution[j][k+1] == '.' && solution[j][k-1] == '.') {
              //Does the same as the IF, but instead for placing words horizontally
              if (k - i >= 0 && k + (length - i - 1) < 15) {
                bool valid = true;
                int column = k - i;
                if (isalpha(solution[j][column - 1]) || isalpha(solution[j][column + length])) {
                  valid = false;
                }
                for (int m = 0; m < length; m++, column++) {
                  if (column != k && (isalpha(solution[j+1][column]) || isalpha(solution[j-1][column]))) {
                    valid = false;
                  }
                }
                if (valid) {
                  column = k - i;
                  for (int m = 0; m < length; m++, column++) {
                    solution[j][column] = a[m];
                    puzzle[j][column] = ' ';
                  }
                  words++;
                  vector<string> newClue;
                  newClue.push_back(to_string(j));
                  newClue.push_back(to_string(k));
                  newClue.push_back("Across");
                  newClue.push_back(a);
                  clues.push_back(newClue);
                  return 1;
                }
              }
            }   
          }
        }
      }
    }
    return 0;
  }
}

