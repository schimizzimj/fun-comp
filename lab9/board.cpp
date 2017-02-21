// board.cpp
// The class implementation for the Board class
//
// Marcus Schimizzi
// 11/16/16

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

#include "board.h"

Board::Board()
{ 
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
  cout << endl;
}

int Board::addWord(string& a)
{
  int length = a.size()/sizeof(char);
  if (words == 0) {
    int shift = (15 - length)/2;
    for (auto it = a.begin(); it != a.end(); ++it) {
      puzzle[7][shift] = ' ';
      solution[7][shift] = *it;
      shift++;
    }
  words++;
  }else{
    for (int i = 1; i <= length; i++) {
      for (int j = 0; j < 15; j++) {
        for(int k = 0; k < 15; k++) {
          if (a[i] == solution[j][k]) {
            if (solution[j+1][k] == '.' && solution[j-1][k] == '.') {
              if (k - i >= 0 && k + (length - i) < 15) {
                bool valid = true;
                int row = j - i;
                if (solution[row - 1][k] != '.' || solution[row + length][k] != '.') {
                  valid = false;
                }
                for (int m = 0; m < length; m++, row++) {
                  if (solution[row][k+1] != '.' || solution[row][k-1] != '.') {
                    valid = false;
                  }
                }
                if (valid) {
                  row = j - i;
                  for (int m = 0; m < length; m++, row++) {
                    solution[row][k] = a[m];
                    puzzle[row][k] = ' ';
                  }
                }
              }
                return 0;
            }else if (solution[j][k+1] == '.' && solution[j][k-1] == '.') {
              if (j - i >= 0 && j + (length - i) < 15) {
                bool valid = true;
                int column = k - i;
                if (solution[j][column - 1] != '.' || solution[j][column + length] != '.') {
                  valid = false;
                }
                for (int m = 0; m < length; m++, column++) {
                  if (solution[j+1][column] != '.' || solution[j-1][column] != '.') {
                    valid = false;
                  }
                }
                if (valid) {
                  column = k - i;
                  for (int m = 0; m < length; m++, column++) {
                    solution[j][column] = a[m];
                    puzzle[j][column] = ' ';
                  }
                }
 
              }
              return 0;
            }   
          }
        }
      }
    }
  }
}

