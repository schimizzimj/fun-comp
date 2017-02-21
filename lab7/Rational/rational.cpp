// rational.cpp
// class implementation for Rational class
// Marcus Schimizzi
// 10/24/16

#include "rational.h"
#include <iostream>
using namespace std;

Rational::Rational()
{ numer = 1; denom = 1; } //Set defaults at 1

Rational::Rational(int x, int y)
{ numer = x; denom = y; } //Set based on inputs

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

void Rational::print()
{ cout << numer << "/" << denom << endl; } //Prints number in " x/y" format

Rational Rational::add(Rational x)
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

Rational Rational::subtract(Rational x)
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

Rational Rational::multiply(Rational x)
{
	Rational p;
	p.setNumer(numer * x.getNumer()); //Multiply the numerators
	p.setDenom(denom * x.getDenom()); //Multiply the denominators
	return p;
}

Rational Rational::divide(Rational x)
{
	Rational q;
	q.setNumer(numer * x.getDenom()); //Multiply the numerators
	q.setDenom(denom * x.getNumer()); //Multiply the denominators
	return q;
}


