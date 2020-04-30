#ifndef QUEEN_ORGANIZER_H
#define QUEEN_ORGANIZER_H

#include <iostream>

// se definen estas macros en pro de la legibilidad
#define ROW 0
#define COLUMN 1

// el problema de las n reinas consiste en ubicar en un tablero de ajedrez de
// dimensiones n x n, n reinas (sin que se maten entre si) dado que ya se han
// ubicado m < n reinas en el tablero. La clase Organizer implementa diferentes
// metodos para resolver el problema.

class Organizer{
private:
    // numero de filas y columnas del tablero
    const int m_rows;
    const int m_columns;

    // numero de reinas a acomodar en el tablero
    const int m_number_of_queens;

    // arreglo bidimensional que alamacenara las posiciones de las reinas
    int **m_positions;

    // esta funcion verifica si el problema fue resuelto
    bool is_solve();

    // esta funcion verifica si 2 reinas estan colisionando, es decir, retorna
    // true cuando las reinas se matan entre si, false en caso contrario
    bool are_colliding(int row1, int column1, int row2, int column2);

    // este metodo reinicia las posiciones de las damas a cero
    void restart_state();

    // esta funcion trata de encontrar una solucion al azar, retorna true
    // si la encuentra, false en caso contrario
    bool make_a_trial();
public:
    Organizer(int rows, int columns, int number_of_queens);
    ~Organizer();

    // este metodo verifica si el tablero tiene solucion
    bool is_soluble();

    // este metodo verifica si introduciendo la reina en la posicion
    // especificada, esta colisionara con las que ya estan en el tablero
    bool check_for_collisions(int row, int column);

    // este metodo resuelve el problema de las n reinas al azar
    void brute_force_solution();

    // este metodo resuelve el problema de las n reinas usando backtraking
    bool backtracking_solution(int position=1);

    // para mostrar el tablero en pantalla
    friend std::ostream& operator<< (std::ostream &out, const Organizer &organizer);

    // TODO: este metodo debe ser implementado
    // este metodo agrega una reina en el tablero, siempre que sea posible(si no entra
    // en colision on otras reinas)
    bool locate_queen(int row, int column, bool overlap=false);
};

#endif
