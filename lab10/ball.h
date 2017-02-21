// ball.h
// The class interface for the Ball class
//
// Marcus Schimizzi
// 11/30/16

#include "gfx.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Ball {
  public:
    Ball();
    Ball(int r, float x, float y, float vx, float vy, float dt);
    ~Ball();
    void randomize();
    void step(int width, int height);
    void setXY(int x, int y);
  private:
    int r;
    float x;
    float y;
    float vx;
    float vy;
    float dt;
};
