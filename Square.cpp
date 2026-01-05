#include "Square.h"

bool Square::check(Point2D* v) {
  double d01 = Point2D::distance(v[0], v[1]);
  double d12 = Point2D::distance(v[1], v[2]);
  double d23 = Point2D::distance(v[2], v[3]);
  double d30 = Point2D::distance(v[3], v[0]);

  return (d01 == d12 && d12 == d23 && d23 == d30);
}

Square::Square() : Rectangle() {
  Point2D defaultVs[4] = {
    Point2D(-1, -1),
    Point2D(1, -1),
    Point2D(1, 1),
    Point2D(-1, 1)
  };
    set_vertices(defaultVs);
}

Square::Square(const std::string& color, Point2D* vertices) : Rectangle(color, vertices) {
  if (!check(vertices)) {
    throw std::invalid_argument("Los vértices no forman un cuadrado válido");
  }
}

void Square::set_vertices(Point2D* vertices){
  if (!check(vertices)) {
    throw std::invalid_argument("Los vértices no forman un cuadrado válido");
  }
  Rectangle::set_vertices(vertices);
}

void Square::print(){
  std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
  out << "Square(" << s.get_color() << "): ";
  for (int i = 0; i < 4; i++) {
    out << s[i];
    if (i < 3) out << ", ";
  }
  return out;
}


