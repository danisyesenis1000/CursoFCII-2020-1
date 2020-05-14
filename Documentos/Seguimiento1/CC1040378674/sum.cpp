
#include <iostream>
#include <stdio.h>

/* 
This function calculate the sum of the integers
beetwen a and b
*/
int sum(int a, int b){
    // sum of the integer beetwen 1 and a
    int sum2a = a * (a + 1) / 2;

    // sum of the integer beetwen 1 and a
    int sum2b = b * (b + 1) / 2;

    // we need to add a
    return sum2b - sum2a + a;
}

int main(){
    int a, b;
    int option;

    // getting info from user
    std::cout << "Type the first integer: ";
    std::cin >> a;

    std::cout << "Type the second integert: ";
    std::cin >> b;
    std::cout << std::endl;

    std::cout << "Do you want get the result on screen or on output.txt file?";
    std::cout << std::endl;

    std::cout << "Type 0 for screen and 1 for output.txt file: ";
    std::cin >> option;
    std::cout << std::endl;

    if (option == 0){
        // print info on screen
        std::cout << "The sum of " << a << " and " << b << " is " << sum(a, b);
        std::cout << std::endl;
    }else {
        // the file for save the output
        FILE *file = fopen("output.txt", "w");

        // write the output to the file
        fprintf(file, "The sum of %d and %d is %d\n", a, b, sum(a, b));
    }

    return 0;
}
