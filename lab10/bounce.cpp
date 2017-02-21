// bounce.cpp
// This program models the animation of a circle moving around the screen
// with constant velocity
//
// Marcus Schimizzi
// 11/30/16

#include "ball.h"

int main() {
  char c = ' ';
  int win_ht = 500, win_wd = 500;
  Ball ball;

  gfx_open(win_wd, win_ht, "Bounce");

  while(c != 'q') {
    //Run animation until user hits the 'q' to quit
    gfx_clear();
    gfx_color(255, 255, 255);
    ball.step(win_wd, win_ht);
    usleep(10000);
    if (gfx_event_waiting()) {
      //Check for the user to press a key or click
      c = gfx_wait();
      ball.setXY(gfx_xpos(), gfx_ypos());
      ball.randomize();
    }
  }  
  return 0;
};
