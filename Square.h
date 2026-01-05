#include "Rectangle.h"
#include <stdexcept>
#include <iostream>

class Square : public Rectangle {
private:
    static bool check(Point2D* v);

public:
    Square();
    Square(const std::string& color, Point2D* vertices);
    void set_vertices(Point2D* vertices) override;
    void print() override;
    friend std::ostream& operator<<(std::ostream& out, const Square& s);
};

