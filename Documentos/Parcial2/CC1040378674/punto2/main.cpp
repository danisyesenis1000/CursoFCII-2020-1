#include <iostream>

#include "queen_organizer.h"

void test(int rows, int columns, int number_of_queens);

int main(){
    // se testea el caso de un tablero 8 x 8 con 8 reinas
    std::cout << "Test para un tablero 8 x 8 con 8 reinas\n";
    test(8, 8, 8);

    std::cout << "\n";

    // se testea el caso de un tablero 15 x 15 con 15 reinas
    std::cout << "Test para un tablero 15 x 15 con 15 reinas\n";
    test(15, 15, 15);
}

void test(int rows, int columns, int number_of_queens){
    Organizer organizer = Organizer(rows, columns, number_of_queens);

    organizer.backtracking_solution();
    std::cout << organizer;
}