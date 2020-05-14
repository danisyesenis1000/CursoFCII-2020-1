#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
public:
    Rectangle(double length, double width);

    void setDimensions(double length, double width);
    void setLength(double length);
    void setWidth(double width);

    double getLength();
    double getWidth();
    double getArea();
    double getPerimeter();

    void showData();

private:
    double m_length;
    double m_width;
};

#endif
