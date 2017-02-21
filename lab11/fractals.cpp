// fractals.cpp
// provides a menu to the user to draw various fractals
//
// Marcus Schimizzi
// 12/5/16

#include <iostream>
#include <cmath>
using namespace std;
#include "gfxnew.h"

#define PI 3.141592

void menu();
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void shrinkingSquares(float x, float y, float length);
void spiralSquares(int x, int y, int side, int rad, float angle);
void circularLace(int x, int y, float radius);
void snowflake(int x, int y, int length);
void tree(int x, int y, int length, float angle);
void fern(int x, int y, int length, float angle);
// void spirals(int x, int y);
void drawSquare(int x, int y, int side);

int main() {
  char c = ' ';
  int event;
  int win_wd = 800, win_ht = 800;
  bool flag = true;

  gfx_open(win_wd, win_ht, "Fractals");
  menu(); // Display a menu for user to allow user to see which key
  // activates which fractal

  while (flag) {
    if((event = gfx_event_waiting()) != 0) { 
      gfx_color(255,255,255);
      c = gfx_wait();
      if(event == 1) {
        // Checks if a key is pressed
        switch(c) {
          // Displays a fractal based on key pressed
          case '1': gfx_clear();
            sierpinski(20,20,780,20,400,
              (20 + (sqrt(pow(760,2) - pow(380,2)))));
            break;
          case '2': gfx_clear();
            shrinkingSquares(400, 400, 150);
            break;
          case '3': gfx_clear();
            spiralSquares(400, 400, 60, 300, 0);
            break;
          case '4': gfx_clear();
            circularLace(400, 400, 200);
            break;
          case '5': gfx_clear();
            snowflake(400, 400, 150);
            break;
          case '6': gfx_clear();
            tree(400, 750, 200, PI/2);
            break;
          case '7': gfx_clear();
            fern(400, 750, 500, PI/2);
            break;
          case '8': 
            gfx_clear();
            gfx_text(200, 400, "(Should be spirals of spirals or something, but may not have happened.)");
            //spirals(400, 400);
            break;
          case 'q':
            flag = false;
            break;   
        }
      }
    gfx_flush();
    } 
  }
  return 0;
}

void menu() {
  gfx_text(100, 100, "1: Sierpinski Triangle");
  gfx_text(100, 150, "2: Shrinking Squares");
  gfx_text(100, 200, "3: Spiral Squares");
  gfx_text(100, 250, "4: Circular Lace");
  gfx_text(100, 300, "5: Snowflake");
  gfx_text(100, 350, "6: Tree");
  gfx_text(100, 400, "7: Fern");
  gfx_text(100, 450, "8: Spiral of Spirals");
}

void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3) {
  
  // Set color
  gfx_color(255,0,0);
  
  // Base case
  if (abs(x1-x2) < 10) return;

  // Draw triangle 
  gfx_color(41, 242, 242);
  gfx_line(x1, y1, x2, y2);
  gfx_color(35, 23, 209);
  gfx_line(x1, y1, x3, y3);
  gfx_color(24, 145, 206);
  gfx_line(x2, y2, x3, y3);

  // Recursive cases
  sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
  sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
  sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}

void shrinkingSquares(float x, float y, float length) {
  // Set color
  gfx_color(0,255,0);

  //Base case
  if (length < 2) return;
  
  //Draw square
  gfx_line(x+length, y+length, x+length, y-length);
  gfx_line(x+length, y+length, x-length, y+length);
  gfx_line(x-length, y+length, x-length, y-length);
  gfx_line(x-length, y-length, x+length, y-length);

  // Recursive cases
  shrinkingSquares(x+length, y+length, length/2.5);
  shrinkingSquares(x+length, y-length, length/2.5);
  shrinkingSquares(x-length, y+length, length/2.5);
  shrinkingSquares(x-length, y-length, length/2.5);
}

void spiralSquares(int x, int y, int side, int rad, float angle) {
  // Set color
  gfx_color(0,0,255);

  // Base case
  if (side < 1) return;

  // Draw square
  drawSquare(x+(rad*cos(angle)), y+(rad*sin(angle)), side/2);

  // Recursive cases
  spiralSquares(x, y, 0.95*side, 0.92*rad, angle+(PI/6));
}

void circularLace(int x, int y, float rad) {
  // Set color
  gfx_color(0,255,0);

  // Base case
  if (rad < 3) return;

  // Draw circle
  gfx_circle(x, y, rad);

  // Recursive cases
  circularLace(x + (rad*cos(0)), y + (rad*sin(0)), 0.35*rad);
  circularLace(x + (rad*cos(PI/3)), y + (rad*sin(PI/3)), 0.35*rad);
  circularLace(x + (rad*cos(2*PI/3)), y + (rad*sin(2*PI/3)), 0.35*rad);
  circularLace(x + (rad*cos(PI)), y + (rad*sin(PI)), 0.35*rad);
  circularLace(x + (rad*cos(4*PI/3)), y + (rad*sin(4*PI/3)), 0.35*rad);
  circularLace(x + (rad*cos(5*PI/3)), y + (rad*sin(5*PI/3)), 0.35*rad);
}

void snowflake(int x, int y, int length) {
  // Set color
  gfx_color(211, 31, 202);

  // Base case
  if (length < 2) return;

  // Draw initial lines
  gfx_line(x, y, x+(length*cos(PI/2)), y+(length*sin(PI/2)));
  gfx_line(x, y, x+(length*cos(9*PI/10)), y+(length*sin(9*PI/10)));
  gfx_line(x, y, x+(length*cos(13*PI/10)), y+(length*sin(13*PI/10)));
  gfx_line(x, y, x+(length*cos(17*PI/10)), y+(length*sin(17*PI/10)));
  gfx_line(x, y, x+(length*cos(21*PI/10)), y+(length*sin(21*PI/10)));

  // Recursive cases
  snowflake(x+(length*cos(PI/2)), y+(length*sin(PI/2)), 0.4*length);
  snowflake(x+(length*cos(9*PI/10)), y+(length*sin(9*PI/10)), 0.4*length);
  snowflake(x+(length*cos(13*PI/10)), y+(length*sin(13*PI/10)), 0.4*length);
  snowflake(x+(length*cos(17*PI/10)), y+(length*sin(17*PI/10)), 0.4*length);
  snowflake(x+(length*cos(21*PI/10)), y+(length*sin(21*PI/10)), 0.4*length);

}

void tree(int x, int y, int length, float angle) {
  // Set color
  gfx_color(0, 255, 0);
  
  // Base case
  if (length < 1) return;

  // Draw line
  gfx_line(x, y, x-(length*cos(angle)), y-(length*sin(angle)));

  // Recursive cases
  tree(x-(length*cos(angle)), y-(length*sin(angle)), 0.7*length, angle+(PI/6));
  tree(x-(length*cos(angle)), y-(length*sin(angle)), 0.7*length, angle-(PI/6));
}

void fern(int x, int y, int length, float angle) {
  // Set color
  gfx_color(255, 191, 0);
  
  // Base case
  if (length < 5) return;

  // Draw line
  gfx_line(x, y, x-(length*cos(angle)), y-(length*sin(angle)));

  // Recursive cases
  fern(x-(length*cos(angle))/4, y-(length*sin(angle))/4, 0.33*length, angle+(PI/6)); 
  fern(x-(length*cos(angle))/4, y-(length*sin(angle))/4, 0.33*length, angle-(PI/6)); 
  fern(x-(length*cos(angle))/2, y-(length*sin(angle))/2, 0.33*length, angle+(PI/6)); 
  fern(x-(length*cos(angle))/2, y-(length*sin(angle))/2, 0.33*length, angle-(PI/6));  
  fern(x-3*(length*cos(angle))/4, y-3*(length*sin(angle))/4, 0.33*length, angle+(PI/6)); 
  fern(x-3*(length*cos(angle))/4, y-3*(length*sin(angle))/4, 0.33*length, angle-(PI/6));
  fern(x-(length*cos(angle)), y-(length*sin(angle)), 0.33*length, angle+(PI/6));  
  fern(x-(length*cos(angle)), y-(length*sin(angle)), 0.33*length, angle-(PI/6));
}
 
/*void spirals(int x, int y) {
  float theta = 0;
  
  for (float i = 0; theta < 6*PI; i+=0.01, theta+=.01) {
    gfx_point(x+(i*cos(theta)), y+(i*sin(theta)));
  }
}*/

void drawSquare(int x, int y, int side) {
  gfx_line(x+side, y+side, x-side, y+side);
  gfx_line(x+side, y+side, x+side, y-side);
  gfx_line(x+side, y-side, x-side, y-side);
  gfx_line(x-side, y-side, x-side, y+side);
}
