// animate.cpp
// creates a wheel with a number of user decided sections to spin and land
// on a random section 
//  
// Marcus Schimizzi
// 12/4/16

#define PI 3.141592

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include "gfx.h"
using namespace std;

void drawCircle(int xc, int yc, int rad, int choice);

int main() {
  int win_wd = 800, win_ht = 800;  // window width and height
  float xc = 400, yc = 400;        // center of the circle
  float angle = 0;
  int rad_circle = 300;
  float x = xc + cos(angle)*rad_circle;
  float y = yc + sin(angle)*rad_circle;
  int rad = 20;                    // ball radius
  char c = ' ';
  int choice;
  float spin_length;
  
  cout << "Welcome to the (psuedo)Random Choice Wheel! \n";
  cout << "Please enter a number of choices (2-10): ";
  cin >> choice;
  cout << "Enjoy!";

  gfx_open(win_wd, win_ht, "WHEEL OF CHOICE");
  
  gfx_color(255,0,0);
  drawCircle(xc, yc, rad_circle, choice);
    
  srand(time(NULL));
  spin_length = rand()%300 * 3; //Causes random length of circle rotation

  while(angle*100 <= spin_length) {
    gfx_clear();
    gfx_color(255,0,0);

    drawCircle(xc, yc, rad_circle, choice); 
    gfx_color(0,255,0);
    gfx_circle(x, y, rad); 
    gfx_flush();
    angle += 0.02; //These three lines move inner circle in rotation
    x = xc + cos(angle)*(rad_circle/2);
    y = yc + sin(angle)*(rad_circle/2);

    gfx_flush();
    usleep(10000);
  }
  
  while(c != 'q') {
    //Quits program if 'q' is pressed
    c = gfx_wait();
    return 0;
  }
}

void drawCircle(int xc, int yc, int rad, int choice) {
  //Draws circle of chance
  gfx_color(255,0,0);
  gfx_circle(xc, yc, rad);
  char count = '1';
  for (float i = 0; i < 2*PI; i += ((2*PI)/choice), count++) {
    //Draws line to make circle into sections
    gfx_color(0,0,255); 
    gfx_line(xc, yc, xc + (cos(i)*rad), yc + (sin(i)*rad));
  }
}
