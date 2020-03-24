#include <iostream>

int iterative_fibonacci(unsigned int n);
int recursive_fibonacci(unsigned int n);

int main(){
    std::cout << "Metodo recursivo" << std::endl;
    for(int i = 1; i < 10; i++){
        std::cout << recursive_fibonacci(i) << std::endl;
    }

    std::cout << "" << std::endl;

    std::cout << "Metodo iterativo" << std::endl;
    for(int i = 1; i < 10; i++){
        std::cout << iterative_fibonacci(i) << std::endl;
    }

    return 0;
}


int iterative_fibonacci(unsigned int n){
    int previous = 0;
    int result = 1;
    int temp;

    if(n == 1){
        return 1;
    }

    for(int i=1; i < n; i++){
        temp = result;

        result += previous;
        previous = temp;
    }

    return result;
}

int recursive_fibonacci(unsigned int n){
    if(n <= 2){
        return 1;
    }

    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}