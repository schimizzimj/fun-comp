// ball.cpp
// The class implementation for the Ball class
//
// Marcus Schimizzi
// 11/30/16

#include "ball.h"

Ball::Ball()
{
  //Initialize private members to defaults
  r = 10; x = 150; y = 150; vx = 2; vy = 2; dt = 3;
}

Ball::Ball(int r, float x, float y, float vx, float vy, float dt)
{
  //Set private members to user variables
  this->r = r; this->x = x; this->y = y; this->vx = vx; this->vy = vy;
  this->dt = dt;
}

Ball::~Ball()
{ }

void Ball::setXY(int x, int y)
{ 
  //Set x and y coordinates to entered integers
  this->x = x; this->y = y;
}

void Ball::randomize()
{
  //Randomize the x and y components of the velocity
  srand(time(NULL));
  vx = (rand() % 21) + (-10);
  vy = (rand() % 21) + (-10);
}

void Ball::step(int width, int height)
{
  //Advance the circle to the next step
  gfx_circle(x, y, r);
  gfx_flush();
  x = x + vx*dt;
  y = y + vy*dt;

  //Check to make the circle is within the borders
  if (x >= width-r) {
    vx = -vx;
    x = x - 1;
  }else if(x <= r) {
    vx = -vx;
    x = x + 1;
  }else if (y >= height-r) {
    vy = -vy;
    y = y - 1;
  }else if (y <= r) {
    vy = -vy;
    y = y + 1;
  }
  gfx_flush();
}
