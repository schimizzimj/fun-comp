//	state.cpp
//	implementation for State class
//
//	Marcus Schimizzi
//	10/28/16

#include <iostream>
#include "state.h"
using namespace std;

State::State() { }

State::State(string ab, string nm, string cap, int p, int yr, int rp)
{ 
  abb = ab; name = nm; capital = cap; 
  pop = p; year = yr; reps = rp; 
}

State::~State() { }

void State::setPop(int p)
{ pop = p; }

void State::setReps(int rp)
{ reps = rp; }

string State::getAbb()
{ return abb; }

string State::getName()
{ return name; }

string State::getCapital()
{ return capital; }

int State::getPop()
{ return pop; }

int State::getYear()
{ return year; }

int State::getReps()
{ return reps; }

void State::print()
{
  cout << name << " (" << abb << ")" << endl;
  cout << "  Capital: " << capital << endl;
  cout << "  Population: " << pop << endl;
  cout << "  Entered Union: " << year << endl;
  cout << "  Representatives: " << reps << "\n\n";
}
