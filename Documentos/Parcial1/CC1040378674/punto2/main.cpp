#include <iostream>
#include <cmath>

bool is_perfect(int number);
void show_divisors(int number);


int main(){
    for (int i = 0; i < 10000; i++){
        if (is_perfect(i)){
            show_divisors(i);
        }        
    }
}


bool is_perfect(int number){
    int accumulator = 1;

    for (int i = 2; i < sqrt(number); i++){
        if(number % i == 0){
            accumulator += i;
            accumulator += number / i;
        }
    }

    return accumulator == number;
}


void show_divisors(int number){
    std::cout << number << " = 1";
    for (int i = 2; i < sqrt(number); i++){
        if(number % i == 0){
            std::cout << " + " << i << " + " << number / i;
        }
    }

    std::cout << std::endl;
}
