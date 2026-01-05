#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); i++) {
        delete shapes->get(i);
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    std::cout << "=== Drawing with " << shapes->size() << " shapes ===" << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        std::cout << "Shape " << i << ": ";
        shapes->get(i)->print();
    }
    std::cout << "=== End of drawing ===" << std::endl;
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    
    for (int i = 0; i < shapes->size(); i++) {
        Shape* shape = shapes->get(i);
        
        Circle* circle = dynamic_cast<Circle*>(shape);
        if (circle != nullptr) {
            total_area += circle->area();
        }
    }
    
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* shape = shapes->get(i);
        
        Square* square = dynamic_cast<Square*>(shape);
        if (square != nullptr) {
            square->translate(incX, incY);
        }
    }
}

