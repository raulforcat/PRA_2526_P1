#include "Rectangle.h"

bool Rectangle::check(Point2D* v) {
    double d01 = Point2D::distance(v[0], v[1]);
    double d12 = Point2D::distance(v[1], v[2]);
    double d23 = Point2D::distance(v[2], v[3]);
    double d30 = Point2D::distance(v[3], v[0]);

    return (d01 == d23 && d12 == d30);
}

Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1,  0.5),
        Point2D( 1,  0.5),
        Point2D( 1, -0.5),
        Point2D(-1, -0.5)
    };
}

Rectangle::Rectangle(const std::string &color, Point2D* v)
    : Shape(color) {

    if (!check(v)) {
        throw std::invalid_argument("Vertices no forman un rectángulo");
    }

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = v[i];
    }
}

Rectangle::Rectangle(const Rectangle& r)
    : Shape(r.get_color()) {

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* v) {
    if (!check(v)) {
        throw std::invalid_argument("Vertices no forman un rectángulo");
    }

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = v[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        set_color(r.get_color());
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "Rectangle(" << r.get_color() << "): ";
    for (int i = 0; i < 4; i++) {
        out << r.vs[i];
        if (i < 3) out << ", ";
    }
    return out;
}

double Rectangle::area() const{ 
  return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const{
  return (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2])) * 2;
}

void Rectangle::translate(double incX, double incY){
  for(int i = 0; i < 4; i++){
    vs[i] = Point2D(vs[i].x + incX, vs[i].y + incY);
  }
}

void Rectangle::print(){
  std::cout << *this << std::endl;
}

