// symbol.cpp
// This program acts as a symbolic typewriter that has graphical responses
// to the user's keystrokes and clicks
//
// Marcus Schimizzi
// 11/28/16

#include <cctype>
#include <cmath>
#include "gfx.h"
using namespace std;

#define PI 3.14159265

int main() {
  const int xsize = 700, ysize = 500;
  int x, y, r = 30, half_h = (sqrt(pow(2*r,2) - pow(r, 2))/2);

  //Open a window for drawing
  gfx_open(xsize, ysize, "Symbolic Typewriter");

  //Loop to process user's actions
  while(true) {
    
    //Wait for an action from the user
    char c = gfx_wait();

    //Grab coordinates of cursor during click/keystroke
    x = gfx_xpos();
    y = gfx_ypos();

    //Wait for the user to click or press a key
    if (!(isalnum(c))) {
      gfx_color(0, 0, 255);
      gfx_line(x - r, y + r, x + r, y + r);
      gfx_line(x - r, y - r, x + r, y - r);
      gfx_line(x - r, y + r, x - r, y - r);
      gfx_line(x + r, y + r, x + r, y - r);
    }
    
    //Perform action based on what user selects
    switch(c) {
      case 'q': return 0;
      case 't': gfx_color(0,255,0);
                gfx_line(x, y - half_h, x + r, y + half_h);
                gfx_line(x, y - half_h, x - r, y + half_h);
                gfx_line(x - r, y + half_h, x + r, y + half_h);
                break;
      case 'c': gfx_color(255,255,255);
                gfx_circle(x, y, r);
                break;
      default:  break;
    }
    
    gfx_color(255,0,255);
    double sides = (360/(c - '0'))*(PI/180);
    if (c > 50 && c < 58) {
      for (int i = 0; i < c - '0'; i++ ) {
        gfx_line((x+(r*cos(sides*i))), (y+(r*sin(sides*i))), (x+(r*cos(sides*(i+1)))), (y+(r*sin(sides*(i+1))))); 
      }
    }
  }
}
