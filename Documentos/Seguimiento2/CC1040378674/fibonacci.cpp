#include <iostream>
#include <vector>


void fibonacci_vector(unsigned int n, std::vector<int> &fibonacci);
void fibonacci_arreglo(unsigned int n, int fibonacci[]);

int main(){
    int terms = 10;

    std::cout << "Metodo de vectores" << std::endl;
    std::vector<int> result;

    fibonacci_vector(terms, result);

    std::cout << std::endl;

    std::cout << "Metodo de arreglos" << std::endl;
    int array[terms] = {0};

    fibonacci_arreglo(terms, array);

    return 0;
}


void fibonacci_vector(unsigned int n, std::vector<int> &fibonacci){
    if(n > 1){
        fibonacci.push_back(1);
        std::cout << fibonacci.at(0) << ' ';
    }
    
    if(n >= 2){
        fibonacci.push_back(1);
        std::cout << fibonacci.at(1) << ' ';
    }

    if(n > 2){
        for(int i = 2; i < n; i++){
            fibonacci.push_back(fibonacci.at(i - 1) + fibonacci.at(i - 2));

            std::cout << fibonacci.at(i) << ' ';
        }

        std::cout << std::endl;
    }
}


void fibonacci_arreglo(unsigned int n, int fibonacci[]){
    if(n > 1){
        fibonacci[0] = 1;
        std::cout << fibonacci[0] << ' ';
    }
    
    if(n >= 2){
        fibonacci[1] = 1;
        std::cout << fibonacci[1] << ' ';
    }

    if(n > 2){
        for(int i = 2; i < n; i++){
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

            std::cout << fibonacci[i] << ' ';
        }

        std::cout << std::endl;
    }
}
