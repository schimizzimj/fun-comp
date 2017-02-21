// rationalmain.cpp
// Tests functionality of the Rational class
//
// Marcus Schimizzi
// 10/27/16 
include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(7,9), b(16,7), c, s, d, p, q;

  cout << "----- display a and b -----\n";
  a.print();
  b.print();
  cout << "----- display c -----\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "----- compute s as the math sum of a and b, and display s -----\n";
  s = a.add(b);
  s.print();

  // subtract b from a
  cout << "----- compute d as the difference between a and b-----\n";
  d = a.subtract(b);
  d.print();

  // multiply a and b
  cout << "----- compute p as the product of a and b -----\n";
  p = a.multiply(b);
  p.print();

  // divide a by b
  cout << "----- compute q as the quotient of a divided by b -----\n";
  q = a.divide(b);
  q.print();

  return 0;
}

