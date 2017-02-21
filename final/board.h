// board.h
// Class interface for the Board class
//
// Marcus Schimizzi
// 12/14/16

#include <unistd.h>
#include <vector>
#include <iostream>
using namespace std;
#include "gfxnew.h"

class Board {
  public:
    Board();
    Board(int);
    ~Board();
    int getLives();
    void background();
    void drawFrog(char orient);
    void drawFrog(int x, int y, char orient);
    void drawLog();
    void drawCar();
    void drawBus();
    void step();
    void stepFrog(char c);
    void update();
    int getY();
    void drawFinish();
    bool getAlltrue();
    void drawDead();

  private:
    int win;
    int lives;
    char grid[15][15];
    int x, y; // X and Y coordinates for the frog
    int car_x[12];
    int car_y[12];
    int bus_x[4];
    int bus_y[4];
    int log_x[8];
    int log_y[8];
    int dt;
    bool finish[5];
    bool alltrue;
    int score;
};
