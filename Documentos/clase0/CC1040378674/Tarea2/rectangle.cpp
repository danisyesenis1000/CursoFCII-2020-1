#include <iostream>

#include "rectangle.h"

Rectangle::Rectangle(double length, double width){
    setDimensions(length, width);
}

void Rectangle::setDimensions(double length, double width){
    m_length = length;
    m_width = width;
}

void Rectangle::setLength(double length){
    m_length = length;
}

void Rectangle::setWidth(double width){
    m_width = width;
}

double Rectangle::getLength(){
    return m_length;
}

double Rectangle::getWidth(){
    return m_width;
}

double Rectangle::getArea(){
    return m_length * m_width;
}

double Rectangle::getPerimeter(){
    return 2 * m_length + 2 * m_width;
}

void Rectangle::showData(){
    std::cout << "The dimensions of the rectangle are:";
    std::cout << std::endl;

    std::cout << "\tlength: " << m_length << std::endl;
    std::cout << "\twidth: " << m_width << std::endl;
}
