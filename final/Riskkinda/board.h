// hexagon.h
// Class interface for the Hexagon class
//
// Marcus Schimizzi
// 12/14/16

class Hexagon {
  private:
    Hexagon();
    Hexagon(int x, int y, int I, int J);
    ~Hexagon();
    int getX();
    int getY();
    void findVertices();
    void drawHex();
  public:
    int x;
    int y;
    int I;
    int J;
    float side;
    float height; // really half the height
    vector<float> vert_x;
    vector<float> vert_y;
};
