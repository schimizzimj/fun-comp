// board.cpp
// The class implementation for the Board class
//
// Marcus Schimizzi
// 11/24/16

#include <iostream>
#include <vector>
using namespace std;

#include "board.h"

Board::Board()
{
  for (auto it = board.begin(); it != board.end(); ++it) {
    for ( j = 0; j < 4; j++) board[i][j] = '.';
  }
  board[1][1] = 'X'; board[2][2] = 'X';
  board[1][2] = 'O'; board[2][1] = 'O';
}

Board::Board(int a)
{
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) board[i][j] = '.';
  }
  int half = a/2;
  board[half][half] = 'X'; board[half+1][half+1] = 'X';
  board[half][half+1] = 'O'; board[half+1][half] = 'O';

}

Board::~Board()
{ }

void Board::print()
{

}

