/*	checkcheck.cpp
 *	This program reads in the configurations of chess boards and returns
 *	whether or not a king (and which king) is in check.
 *
 *	Marcus Schimizzi
 *	9/26/16
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	char chess[8][8];
	int count = 0;
	while(true) {
		bool empty = true;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> chess[i][j];
				if (chess[i][j] != '.') {
					empty = false;
				}
				if (chess[i][j] == 'k') {
					int whiteKing_x = j;
					int whiteKing_y = i;
				}else if(chess[i][j] == 'K') {
					int blackKing_x = j;
					int blackKing_y = i;
				}
			}
		}
		if (empty) break;
	} 
}

int checkKnightBlack(int king_x, king_y) {
	
}
