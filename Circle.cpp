#include "Circle.h"

static const double pi = 3.1416;

Circle::Circle()
    : Shape("red"), center(), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const{
  return center;
}

void Circle::set_center(Point2D p){
  center = p;
}

double Circle::get_radius() const{
  return radius;
}

void Circle::set_radius(double r){
  radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
  return out << "Circle: (Color: " <<  c.get_color() << "; Centro: " << c.get_center() << "; Radio: " << c.get_radius() << ")";
}

double Circle::area() const{
  return pi * radius * radius;
}

double Circle::perimeter() const{
  return pi * radius * 2;
}

void Circle::translate(double incX, double incY){
  center = Point2D(center.x + incX, center.y + incY);
}

void Circle::print(){
  std::cout << *this << std::endl;
}
