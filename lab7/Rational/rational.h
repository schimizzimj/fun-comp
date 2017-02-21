// rational.h
// class interface for Rational class
// Marcus Schimizzi
// 10/24/16
class Rational {
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    Rational add(Rational);
    Rational subtract(Rational);
    Rational multiply(Rational);
    Rational divide(Rational);
  private:
    int numer;
    int denom;
};

