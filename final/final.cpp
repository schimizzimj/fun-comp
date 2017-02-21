// final.cpp
// This program acts as a clone for the classic game of frogger
//
// Marcus Schimizzi
// 12/14/16

#include <iostream>
#include <cmath>
using namespace std;

#include "board.h"

void menu();
void drawFrog(int x, int y, int side, char orient);

int main() {
  char c = ' ',d,e;
  int event, win_dem = 600, count = 0;;
  bool victory = false;
 
  gfx_open(win_dem, win_dem, "Frogger");
  while(c != 'q'){
    gfx_color(0,0,71);  
    gfx_fill_rectangle(50, 50, 500, 500);
    gfx_color(33, 222, 0);
    menu();
    if (count != 0) {
      char over[] = "GAME OVER. BETTER LUCK NEXT TIME!";
      char success[] = "YOU WIN!!! CONGRATULATIONS!!!";
      char font[] = "12x24";
      int over_width = gfx_textpixelwidth(over,font);
      int success_width = gfx_textpixelwidth(success,font); 
      gfx_changefont(font);
      if(victory == true) gfx_text((win_dem/2)-(success_width/2),450,success);
      else gfx_text((win_dem/2)-(over_width/2),450,over);
    }
    if((event = gfx_event_waiting()) != 1) {
      Board frog;
      c = gfx_wait();
      if(c == 'p'){
        while(frog.getLives() > 0 && victory == false) {
          if((event = gfx_event_waiting()) != 0){
            if(event == 1) d = gfx_wait();
            else gfx_wait();
          }
          frog.background();
          frog.drawCar();
          frog.drawLog();
          frog.drawBus();
          frog.drawFinish();
          frog.drawFrog('w');
          frog.step();
          frog.stepFrog(d);
          frog.update();
          usleep(10000);
          d = ' ';
          if(frog.getAlltrue()) victory = true;
        }
        count++;
      }else if (c == 'q') return 0;  
    }else gfx_wait();  
  }
}

void menu() {
  // Set up arrays of points for each letter in the title
  XPoint f[] = { {110,150},{160,150},{160,165},{135,165},{135,180},{160,180}   ,{160,195},{135,195},{135,250},{110,250},{110,150} };
  XPoint r1[] = { {165,150},{215,150},{215,200},{200,200},{215,250},{200,250   },{185,200},{185,250},{165,250},{165,150} };
  XPoint o[] = { {220,150},{270,150},{270,250},{250,230},{250,170},{240,170}   ,{240,230},{250,230},{270,250},{220,250},{220,150} };
  XPoint g1[] = { {275,150},{325,150},{325,170},{295,170},{295,230},{305,230   },{305,200},{325,200},{325,250},{275,250},{275,150} };
  XPoint g2[] = { {330,150},{380,150},{380,170},{350,170},{350,230},{360,230   },{360,200},{380,200},{380,250},{330,250},{330,150} };
  XPoint e[] = { {385,150},{435,150},{435,170},{405,170},{405,190},{435,190}   ,{435,210},{405,210},{405,230},{435,230},{435,250},{385,250},{385,150} };
  XPoint r2[] = { {440,150},{490,150},{490,200},{475,200},{490,250},{475,250    },{460,200},{460,250},{440,250},{440,150} };

  gfx_fill_polygon(f,11); 
  gfx_fill_polygon(r1,10);
  gfx_fill_polygon(o,11);
  gfx_fill_polygon(g1,11);
  gfx_fill_polygon(g2,11);
  gfx_fill_polygon(e,13);
  gfx_fill_polygon(r2,10); // Draw "FROGGER" as polygons

  char myfont[] = "12x24";
  char play[] = "Press 'p' to play";
  char quit[] = "Press 'q' to quit the game";
  int play_width = gfx_textpixelwidth(play, myfont);
  int quit_width = gfx_textpixelwidth(quit, myfont);
  
  int play_x = 300 - play_width/2;
  int quit_x = 300 - quit_width/2;
  
  gfx_changefont(myfont);
  gfx_text(play_x, 300, play); 
  gfx_text(quit_x, 350, quit);
}

