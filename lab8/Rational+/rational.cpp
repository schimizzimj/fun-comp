// rational.cpp
// class implementation for Rational class
// Marcus Schimizzi
// 10/24/16

#include <iostream>
using namespace std;

#include "rational.h"

Rational::Rational()
{ setRational(1,1); } //Set defaults at 1

Rational::Rational(int x, int y)
{ setRational(x,y); } //Set based on inputs

Rational::~Rational()
{}

int Rational::getNumer()
{ return numer; }

int Rational::getDenom()
{ return denom; }

void Rational::setNumer(int x)
{ numer = x; }

void Rational::setDenom(int y)
{ denom = y; }

void Rational::setRational(int num, int den)
{ numer = num; denom = den; }

ostream& operator<<(ostream& os, Rational& a)
{ os << a.numer << "/" << a.denom << endl; return os; }

istream& operator>>(istream& is, Rational& a)
{ 
  int x, y;
   
  cout << "Enter numerator and denominator, in that order: ";
  is >> x >> y;
  a.setRational(x, y);
}

Rational Rational::operator+(Rational x)
{
	Rational s;
	if (denom == x.getDenom()) {
		//Simply add numerators and denominators if denominators 
		//are the same
		s.setDenom(denom);
		s.setNumer(numer + x.getNumer());
	}else {
		int temp = denom;
		while ( temp % x.getDenom() != 0) {
			//Find a common multiple for the denominators
			temp += denom;
		}
		s.setDenom(temp);
		int newNumer = ((numer * (temp/denom)) + (x.getNumer() * (temp/x.getDenom()))); //Multiply numerators by necessary numbers and add together
		s.setNumer(newNumer);
	}
	return s;
}

Rational Rational::operator-(Rational x)
{
	//Same process as for add, except for subtracting instead
	Rational d;
	if (denom == x.getDenom()) {
		d.setDenom(denom);
		d.setNumer(numer - x.getNumer());
	}else {
		int temp = denom;
		while ( temp % x.getDenom() != 0) {
			temp += denom;
		}
		d.setDenom(temp);
		int newNumer = ((numer * (temp/denom)) - (x.getNumer() * (temp/x.getDenom())));
		d.setNumer(newNumer);
	}
	return d;
}

Rational Rational::operator*(Rational x)
{
	Rational p;
	p.setNumer(numer * x.getNumer()); //Multiply the numerators
	p.setDenom(denom * x.getDenom()); //Multiply the denominators
	return p;
}

Rational Rational::operator/(Rational x)
{
	Rational q;
	q.setNumer(numer * x.getDenom()); //Multiply the numerators
	q.setDenom(denom * x.getNumer()); //Multiply the denominators
	return q;
}


