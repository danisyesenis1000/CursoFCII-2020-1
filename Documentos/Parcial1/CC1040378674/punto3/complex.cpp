#include <cmath>

#include "complex.h"

Complex::Complex(double x, double y){
    set_data(x, y);
}


void Complex::set_data(double x, double y){
    m_x = x;
    m_y = y;
}


double Complex::get_real_part(){
    return m_x;
}


double Complex::get_imaginary_part(){
    return m_y;
}


Complex Complex::operator+(const Complex &other){
    return Complex(m_x + other.m_x, m_y + other.m_y);
}


Complex Complex::operator-(const Complex &other){
    return Complex(m_x - other.m_x, m_y - other.m_y);
}


std::ostream& operator<< (std::ostream &out, const Complex &complex){
    if(fabs(complex.m_y) < 1e-16){
            out << complex.m_x;
    }else{
        out << complex.m_x << (complex.m_y > 0 ? " + " : " - ") << fabs(complex.m_y) << 'i';
    }

    return out;
}
