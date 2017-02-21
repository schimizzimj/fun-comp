// circle.h
class Circle {
  public:
    Circle();
    Circle(float r);
    ~Circle();
    float getRadius();
    void setRadius(float r);
    float circumference();
    float area();
  private:
    float radius;
};

