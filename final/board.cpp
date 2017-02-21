// board.cpp
// Class implementation for the Board class
//
// Marcus Schimizzi
// 12/14/16

#include "board.h"

Board::Board()
{ lives = 3; win = 600; dt = 3; score = 0;
  x = 300; y = win - win/15; alltrue = false; 
  for(int b = 0; b < 5; b++) finish[b] = false; //Initialize completion array
    // to all false values
  for(int c = 0; c < 12; c++){
    //Initialize positions of cars
    if ((c+1)%6 == 0){
      car_x[c] = 2.5*win/15;
      (c == 5) ? car_y[c] = 7*win/15 : car_y[c] = 11*win/15;
    }else if ((c+2)%6 == 0) {
      car_x[c] = 4.5*win/15;
      (c == 4) ? car_y[c] = 9*win/15 : car_y[c] = 13*win/15;
    }else if ((c+3)%6 == 0) {
      car_x[c] = win/2;
      (c == 3) ? car_y[c] = 7*win/15 : car_y[c] = 11*win/15;
    }else if ((c+4)%6 == 0) {
      car_x[c] = 9.5*win/15;
      (c == 2) ? car_y[c] = 9*win/15 : car_y[c] = 13*win/15;
    }else if ((c+5)%6 == 0) {
      car_x[c] = 14.5*win/15;
      (c == 1) ? car_y[c] = 7*win/15 : car_y[c] = 11*win/15;
    }else {
      car_x[c] = 12.5*win/15;
      (c == 0) ? car_y[c] = 9*win/15 : car_y[c] = 13*win/15;
    }
  }
  for (int l = 0; l < 8; l++) {
    //Initialize positions of logs
    if((l+3)%4 == 0){
      log_y[l] = 2*win/15;
      (l == 1) ? log_x[l] = 3.5*win/15 : log_x[l] = 8.5*win/15;
    }else if((l+1)%4 == 0) {
      log_y[l] = 3*win/15;
      (l == 3) ? log_x[l] = 5.5*win/15 : log_x[l] = 10.5*win/15;
    }else if((l+2)%4 == 0) {
      log_y[l] = 4*win/15;
      (l == 2) ? log_x[l] = 3.5*win/15 : log_x[l] = 8.5*win/15;
    }else{
      log_y[l] = 5*win/15;
       (l == 4) ? log_x[l] = 5.5*win/15 : log_x[l] = 10.5*win/15; 
    }
  }
  
  //Initialze positions of buses (FOR loop not really necessary here)
  bus_x[0] = 3.5*win/15; bus_y[0] = 8*win/15;
  bus_x[1] = 8.5*win/15; bus_y[1] = 8*win/15;
  bus_x[2] = 3.5*win/15; bus_y[2] = 12*win/15;
  bus_x[3] = 8.5*win/15; bus_y[3] = 12*win/15;

  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++) grid[j][i] = ' ';
  }
}

Board::Board(int stuff)
{ }

Board::~Board()
{ }

int Board::getLives()
{ return lives; }

void Board::background()
{
  // Draw background
  gfx_color(0,0,71);
  gfx_fill_rectangle(0, 0, win, 11*win/30);
  gfx_color(158,20,20);
  gfx_fill_rectangle(0, 11*win/30, win, win/15);
  gfx_color(84,75,75);
  gfx_fill_rectangle(0, 13*win/30, win, 7*win/15);
  gfx_color(33,222,0);
  gfx_fill_rectangle(0, 27*win/30, win, 3*win/30);
  gfx_fill_rectangle(0,0,win,win/30);
  bool draw = true;
  for(int i = 0; i < 15; i++) {
    if((i+2)%3 == 0) { 
      gfx_color(0,90,9);
      gfx_fill_rectangle((i*win/15)+10,(win/30)+10,win/30,win/30);
    }else {
      gfx_color(33,222,0);
      gfx_fill_rectangle(i*win/15,win/30,win/15,win/15);
      gfx_color(239,229,35);
      gfx_fill_rectangle(i*win/15,39*win/60,win/15,win/30);
    }
  }
  gfx_color(0,0,0);
  gfx_line(0,29*win/30,win,29*win/30);
  char font[] = "6x13bold";
  char helptext[] = "Use WASD keys to move. Watch out for cars!";
  int width = gfx_textpixelwidth(helptext, font);
  gfx_changefont(font);
  gfx_text((win/2) - (width/2),win - 5, helptext);
  gfx_text(5, win - 5, "Lives: ");
  for (int i = 1; i <= lives; i++){
    gfx_circle(50+(i*20), win - 10, 8); 
  }
  gfx_text(win/2 + width/2 + 20, win - 5, "Your score: ");
  
}

void Board::drawFrog(char orient)
{
  int side = win/15;
  XPoint vert_leg1[] = { {x-(side/2),y-(side/2)},{x-(side/2),y+(side/10)},
    {x+(side/2),y+(side/10)},{x+(side/2),y+(side/2)},
    {x+(2*side/5),y+(side/2)},{x+(2*side/5),y+(side/10)},
    {x-(2*side/5),y+(side/10)},{x-(2*side/5),y+(side/2)},
    {x-(side/2),y+(side/2)} };
  XPoint vert_leg2[] = { {x-(side/2),y-(side/2)},{x-(side/2),y-(side/10)},
    {x+(side/2),y-(side/10)},{x+(side/2),y-(side/2)},
    {x+(2*side/5),y-(side/2)},{x+(2*side/5),y-(side/10)},
    {x-(2*side/5),y-(side/10)},{x-(2*side/5),y-(side/2)},
    {x-(side/2),y-(side/2)} };
 XPoint horz_leg1[] = { {x-(side/2),y-(side/2)},{x-(side/10),y-(side/2)},
    {x-(side/10),y+(side/2)},{x-(side/2),y+(side/2)},
    {x-(side/2),y+(2*side/5)},{x-(side/10),y+(2*side/5)},
    {x-(side/10),y-(2*side/5)},{x-(side/2),y-(2*side/5)},
    {x-(side/2),y-(side/2)} };
  XPoint horz_leg2[] = { {x+(side/2),y-(side/2)},{x+(side/10),y-(side/2)},
    {x+(side/10),y+(side/2)},{x+(side/2),y+(side/2)},
    {x+(side/2),y+(2*side/5)},{x+(side/10),y+(2*side/5)},
    {x+(side/10),y-(2*side/5)},{x+(side/2),y-(2*side/5)},
    {x+(side/2),y-(side/2)} };

  gfx_color(0,70,0);
  
  switch(orient) {
    case 'w': gfx_fill_arc(x-(0.4*side), y-(side/2), 0.8*side, side, 0, 360);
              gfx_fill_polygon(vert_leg1,9);
              gfx_fill_polygon(vert_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.2*side,y-0.3*side,side/8);
              gfx_fill_circle(x+0.2*side,y-0.3*side,side/8);
              break;

    case 's': gfx_fill_arc(x-(0.4*side), y-(side/2), 0.8*side, side, 0, 360);
              gfx_fill_polygon(vert_leg1,9);
              gfx_fill_polygon(vert_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.2*side,y+0.3*side,side/8);
              gfx_fill_circle(x+0.2*side,y+0.3*side,side/8);
              break;
  
    case 'a': gfx_fill_arc(x-(side/2), y-(0.4*side), side, 0.8*side, 0, 360);
              gfx_fill_polygon(horz_leg1,9);
              gfx_fill_polygon(horz_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.3*side,y-0.2*side,side/8);
              gfx_fill_circle(x-0.3*side,y+0.2*side,side/8);
              break;
              
    case 'd': gfx_fill_arc(x-(side/2), y-(0.4*side), side, 0.8*side, 0, 360);
              gfx_fill_polygon(horz_leg1,9);
              gfx_fill_polygon(horz_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x+0.2*side,y-0.2*side,side/8);
              gfx_fill_circle(x+0.2*side,y+0.2*side,side/8);
              break;
  }
}

void Board::drawFrog(int x, int y, char orient)
{
  int side = win/15;
  XPoint vert_leg1[] = { {x-(side/2),y-(side/2)},{x-(side/2),y+(side/10)},
    {x+(side/2),y+(side/10)},{x+(side/2),y+(side/2)},
    {x+(2*side/5),y+(side/2)},{x+(2*side/5),y+(side/10)},
    {x-(2*side/5),y+(side/10)},{x-(2*side/5),y+(side/2)},
    {x-(side/2),y+(side/2)} };
  XPoint vert_leg2[] = { {x-(side/2),y-(side/2)},{x-(side/2),y-(side/10)},
    {x+(side/2),y-(side/10)},{x+(side/2),y-(side/2)},
    {x+(2*side/5),y-(side/2)},{x+(2*side/5),y-(side/10)},
    {x-(2*side/5),y-(side/10)},{x-(2*side/5),y-(side/2)},
    {x-(side/2),y-(side/2)} };
 XPoint horz_leg1[] = { {x-(side/2),y-(side/2)},{x-(side/10),y-(side/2)},
    {x-(side/10),y+(side/2)},{x-(side/2),y+(side/2)},
    {x-(side/2),y+(2*side/5)},{x-(side/10),y+(2*side/5)},
    {x-(side/10),y-(2*side/5)},{x-(side/2),y-(2*side/5)},
    {x-(side/2),y-(side/2)} };
  XPoint horz_leg2[] = { {x+(side/2),y-(side/2)},{x+(side/10),y-(side/2)},
    {x+(side/10),y+(side/2)},{x+(side/2),y+(side/2)},
    {x+(side/2),y+(2*side/5)},{x+(side/10),y+(2*side/5)},
    {x+(side/10),y-(2*side/5)},{x+(side/2),y-(2*side/5)},
    {x+(side/2),y-(side/2)} };

  gfx_color(0,70,0);
  
  switch(orient) {
    case 'w': gfx_fill_arc(x-(0.4*side), y-(side/2), 0.8*side, side, 0, 360);
              gfx_fill_polygon(vert_leg1,9);
              gfx_fill_polygon(vert_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.2*side,y-0.3*side,side/8);
              gfx_fill_circle(x+0.2*side,y-0.3*side,side/8);
              break;

    case 's': gfx_fill_arc(x-(0.4*side), y-(side/2), 0.8*side, side, 0, 360);
              gfx_fill_polygon(vert_leg1,9);
              gfx_fill_polygon(vert_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.2*side,y+0.3*side,side/8);
              gfx_fill_circle(x+0.2*side,y+0.3*side,side/8);
              break;
  
    case 'a': gfx_fill_arc(x-(side/2), y-(0.4*side), side, 0.8*side, 0, 360);
              gfx_fill_polygon(horz_leg1,9);
              gfx_fill_polygon(horz_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x-0.3*side,y-0.2*side,side/8);
              gfx_fill_circle(x-0.3*side,y+0.2*side,side/8);
              break;
              
    case 'd': gfx_fill_arc(x-(side/2), y-(0.4*side), side, 0.8*side, 0, 360);
              gfx_fill_polygon(horz_leg1,9);
              gfx_fill_polygon(horz_leg2,9);
              gfx_color(255,55,0);
              gfx_fill_circle(x+0.2*side,y-0.2*side,side/8);
              gfx_fill_circle(x+0.2*side,y+0.2*side,side/8);
              break;
  }
}


void Board::drawLog() {
  gfx_color(99,57,6);
  int side = win/15;
  for(int i = 0; i < 8; i++) {
    gfx_fill_rectangle(log_x[i]-1.5*side,log_y[i]-side/4,3*side,side/2);
  }
}

void Board::drawCar() {
  gfx_color(0,0,200);
  int side = win/15;
  for(int i = 0; i < 12; i++) {
    gfx_fill_rectangle(car_x[i]-side/2,car_y[i]-0.4*side,side,0.8*side);
  }
}

void Board::drawBus() {
  gfx_color(239,232,19);
  int side = win/15;
  for(int i = 0; i < 4; i++) {
    gfx_fill_rectangle(bus_x[i]-1.5*side,bus_y[i]-side/2,3*side,side);
  }
}

void Board::step(){
  for(int i = 0; i < 8; i++) {
    if(log_y[i] == 2*win/15 || log_y[i] == 4*win/15)
      log_x[i] = log_x[i] - dt*1;
    else log_x[i] = log_x[i] + dt*2;
  
    //Detect window collisions
    if(log_x[i] < 0) log_x[i] = win;
    else if(log_x[i] > win) log_x[i] = 0;
  }
  for(int j = 0; j < 4; j++) {
    bus_x[j] = bus_x[j] + dt*1;
    
     //Detect window collisions
    if(bus_x[j] < 0) bus_x[j] = win;
    else if(bus_x[j] > win) bus_x[j] = 0;
  }
  for(int k = 0; k < 12; k++) {
    if((k+1)%2 == 0) car_x[k] = car_x[k] - dt*5;
    else car_x[k] = car_x[k] + dt*2;

    //Detect window collisions
    if(car_x[k] < 0) car_x[k] = win;
    else if(car_x[k] > win) car_x[k] = 0;
  }
}

void Board::stepFrog(char c)
{
    switch(c){
     case 'w':  y = y - 40;
                score += 10;
                break;
     case 'a':  x = x - 40;
                break;
     case 's':  if(y != win - win/15) y = y + 40;
                score -= 10;
                break;
     case 'd':  x = x + 40;
                break;
    }
  
}

void Board::update()
{
  for (int m = 0; m < 15; m++){
    for (int n = 0; n < 15; n++) grid[m][n] = ' ';
  } // Clear grid

  for (int i = 0; i < 12; i++) {
    grid[(car_y[i]-20)/40][car_x[i]/40] = 'f';
  }// Check to see where cars are
  for (int j = 0; j < 8; j++) {
    int ylog = (log_y[j]-20)/40; int xlog = log_x[j]/40;
    if(ylog == 1 || ylog == 3){  
      grid[ylog][xlog] = 'l';
      grid[ylog][xlog - 1] = 'l';
      grid[ylog][xlog + 1] = 'l';
    }else{ 
      grid[ylog][xlog] = 'o';
      grid[ylog][xlog - 1] = 'o';
      grid[ylog][xlog + 1] = 'o';
    }
  }// Check to see where logs are
  for (int k = 0; k < 4; k++) {
    int ybus = (bus_y[k]-20)/40; int xbus = bus_x[k]/40;
    grid[ybus][xbus] = 'f';
    grid[ybus][xbus - 1] = 'f';
    grid[ybus][xbus + 1] = 'f';
  } // Check to see where buses are
  if (grid[(y-20)/40][x/40] == 'f' || x < 0 || x > win || y < 0 || y > win || (y == 40 && ((x < 40) || (x > 80 && x < 160 ) || (x > 200 && x < 280) || (x > 320 && x < 400) || (x > 440 && x < 520) || (x > 560))) || ((y > 60 && y < 220) && (grid[(y-20)/40][x/40] != 'l' && grid[(y-20)/40][x/40] != 'o'))){
    // Determine if collision is occuring
    drawDead();
    score -= 200;
    lives = lives - 1; 
    x = 300; y = win - win/15;
  }else if(grid[(y-20)/40][x/40] == 'l') {
    x = x - dt*1; 
  }else if(grid[(y-20)/40][x/40] == 'o') {
    x = x + dt*2;
  }else if(y == 40){
    int which = x/120;
    if(finish[which] == true) {
      drawDead();
      score -= 200;
      lives = lives - 1;
    }else{
      finish[which] = true;
      score += 500;
    } 
    x = 300; y = win - win/15;
  }
} 


int Board::getY()
{ return y; }

void Board::drawFinish()
{
  alltrue = true;
  for(int i = 0; i < 5; i++) {
    if (finish[i] == true){
      drawFrog((60+(i*120)),40,'s');
    }else alltrue = false;
  }
}

bool Board::getAlltrue()
{ return alltrue; }

void Board::drawDead()
{
  int side = win/30;
  XPoint xspot[] = { {x-side,y-side},{x-side/2,y-side},{x,y-side/2},
    {x+side/2,y-side},{x+side,y-side},{x+side/2,y},{x+side,y+side},
    {x+side/2,y+side},{x,y+side/2},{x-side/2,y+side},{x-side,y+side},
    {x-side/2,y},{x-side,y-side} };
  int count = 0;
  while(count < 100){
    gfx_color(200,0,0);
    gfx_fill_polygon(xspot,13);
    usleep(10000);
    count++;
  }
}
