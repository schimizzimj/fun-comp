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
    void setRational(int, int);
    
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    friend ostream& operator<<(ostream&, Rational &);
    friend istream& operator>>(istream&, Rational &);


  private:
    int numer;
    int denom;
};
