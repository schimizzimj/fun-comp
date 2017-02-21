// lifeboard.cpp
// Class implementation for the Lifeboard class
//
// Marcus Schimizzi
// 11/4/16

#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

#include "lifeboard.h"

Lifeboard::Lifeboard()
{
 char mainboard[40][40];
 for (int i = 0; i < 40; i++) {
	for (int j = 0; j < 40; j++) board[i][j] = ' ';
 }	
}

Lifeboard::~Lifeboard()
{ }

char Lifeboard::getCell(int x, int y)
{ return board[x][y]; }

int Lifeboard::checkNeighbors(int x, int y)
{
	int count = 0;
	if ((x+1) < 40 && board[x+1][y] == 'X') count++;
	if ((x+1) < 40 && (y+1) < 40 && board[x+1][y+1] == 'X') count++;
	if ((x+1) < 40 && (y-1) >= 0 && board[x+1][y-1] == 'X') count++;
	if ((x-1) >= 0 && board[x-1][y] == 'X') count++;
	if ((x-1) >= 0 && (y+1) < 40 && board[x-1][y+1] == 'X') count++;
	if ((x-1) >= 0 && (y-1) >= 0 && board[x-1][y-1] == 'X') count++;
	if ((y+1) < 40 && board[x][y+1] == 'X') count++;
	if ((y-1) >= 0 && board[x][y-1] == 'X') count++;
	return count;	
}

void Lifeboard::setCell(int cellX, int cellY)
{ board[cellY - 1][cellX - 1] = 'X'; }

void Lifeboard::killCell(int cellX, int cellY)
{ board[cellY - 1][cellX - 1] = ' '; }

void Lifeboard::update()
{
  Lifeboard temp;
  for (int i = 0; i < 40; i++) {
  	for (int j = 0; j < 40; j++) {
  		int state = this->checkNeighbors(j,i);
  		if (state < 2 || state > 3) {
			temp.killCell(j + 1,i + 1);
		}else if (state == 3) {
			temp.setCell(j + 1,i + 1);
		}else if (state ==2) {
			if (board[j][i] == 'X') temp.setCell(j + 1, i + 1);
			if (board[j][i] == ' ') temp.killCell(j + 1, i + 1);
		}
	}
  }
  for(int m = 0; m < 40; m++) {
  	for (int n = 0; n < 40; n++) { 
		board[m][n] = temp.getCell(n,m);
	}
  }
}

ostream& operator<<(ostream& os, Lifeboard& x)
{
  for (int i = 0; i < 42; i++) os << "_";
  cout << endl;
  for (int j = 0; j < 40; j++) { 
	os << "|";
  	for (int k = 0; k < 40; k++) {
  		os << x.board[j][k];
	}
	os << "|" << endl;
  }
  cout << "|";
  for (int m = 0; m < 40; m++) os << "-";
  os << "|" << endl;
}

void Lifeboard::play()
{
  while(true) {
	system("clear");
	this->update();
	cout << *this;
	usleep(100000);  	
  }
}
