#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
private:
    double m_x;
    double m_y;

    void set_data(double x, double y);
public:
    Complex(double x, double y);

    double get_real_part();
    double get_imaginary_part();

    Complex operator+(const Complex &other);
    Complex operator-(const Complex &other);

    friend std::ostream& operator<< (std::ostream &out, const Complex &complex);
};

#endif
