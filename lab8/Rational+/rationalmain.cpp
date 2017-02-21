// rationalmain.cpp
// Tests functionality of the Rational class
//
// Marcus Schimizzi
// 10/27/16 
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(7,9), b(16,7), c, s, d, p, q;
  cin >> c;

  cout << "----- display a and b -----\n";
  cout << a << endl;
  cout << b << endl;
 
  cout << "----- display c -----\n";
  cout << c << endl;

  // 'mathematically' add a and b
  cout << "----- compute s as the math sum of a and b, and display s -----\n";
  s = a + b;
  cout << s << endl;

  // subtract b from a
  cout << "----- compute d as the difference between a and b-----\n";
  d = a - b;
  cout << d << endl;

  // multiply a and b
  cout << "----- compute p as the product of a and b -----\n";
  p = a * b;
  cout << p << endl;

  // divide a by b
  cout << "----- compute q as the quotient of a divided by b -----\n";
  q = a / b;
  cout << q << endl;

  return 0;
}

