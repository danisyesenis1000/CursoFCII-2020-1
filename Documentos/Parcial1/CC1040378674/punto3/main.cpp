#include <iostream>

#include "complex.h"

int main(){
    Complex a(1, 2);
    Complex b(4, -2);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;

    return 0;
}
