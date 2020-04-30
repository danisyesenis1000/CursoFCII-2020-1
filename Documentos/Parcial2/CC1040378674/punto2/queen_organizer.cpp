#include <iostream>
#include <cstdlib>
#include <ctime>

#include "queen_organizer.h"

Organizer::Organizer(int rows, int columns, int number_of_queens):
                     m_rows{rows},
                     m_columns{columns},
                     m_number_of_queens{number_of_queens}{
    // se usa aleatorieda para uno de los metodos de solucion
    srand (time(NULL));

    // se pide memoria de forma dinamica, dado que la dimension depende del usuario
    // este arreglo guardara informacion de todas las reinas
    m_positions = (int **) malloc((size_t) sizeof(int *) * m_number_of_queens);

    for (int i = 0; i < m_number_of_queens; i++){
        // cada reina tiene informacion de la fila y la columna que ocupa
        m_positions[i] = (int *) malloc((size_t) sizeof(int) * 2);

        // las posiciones se enumeran desde 1, por eso se usa 0 para indicar
        // que a la reina "i" no se le ha asignado una posicion
        m_positions[i][ROW] = 0;
        m_positions[i][COLUMN] = 0;
    }
    
}

Organizer::~Organizer(){
    // cuando se pide memoria de forma dinamica se debe liberar antes
    // de terminar la ejecucion del programa
    for (int i = 0; i < m_number_of_queens; i++){
        free(m_positions[i]);
    }

    free(m_positions);
}

// TODO: se debe generalizar para el caso en el que se hayan puesto reinas en el tablero
// este metodo verifica si el tablero tiene solucion
bool Organizer::is_soluble(){
    return m_number_of_queens <= m_rows && m_number_of_queens <= m_columns;
}

// esta funcion verifica si 2 reinas estan colisionando, es decir, retorna
// true cuando las reinas se matan entre si, false en caso contrario
bool Organizer::are_colliding(int row1, int column1, int row2, int column2){
    // si las reinas estan en la misma fila o en la misma columna, entonces
    // se matan entre si
    bool collide = row1 == row2 || column1 == column2;

    // cuando 2 reinas estan en la misma diagonal descentedente(ej:
    // (a, b) y (a + n, b + n)) cumplen la condicion a - b = (a + n) - (b + n)
    collide = collide || (row1 - column1 == row2 - column2);

    // cuando 2 reinas estan en la misma diagonal ascendente(ej:
    // (a, b) y (a - n, a + n)) cumplen la condicion a + b = (a - n) + (b + n)
    collide = collide || (row1 + column1 == row2 + column2);

    return collide;
}

// este metodo verifica si introduciendo la reina en la posicion
// especificada, esta colisionara con las que ya estan en el tablero
bool Organizer::check_for_collisions(int row, int column){
    for (int i = 0; i < m_number_of_queens; i++){
        if(are_colliding(row, column, m_positions[i][ROW], m_positions[i][COLUMN]))
            return true;
    }

    return false;
}

// este metodo reinicia las posiciones de las damas a cero
void Organizer::restart_state(){
    for (int i = 0; i < m_number_of_queens; i++){
        m_positions[i][ROW] = 0;
        m_positions[i][COLUMN] = 0;
    }
}

// esta funcion trata de encontrar una solucion al azar
bool Organizer::make_a_trial(){
    restart_state();

    int row = 0;
    int column = 0;

    for (int i = 0; i < m_number_of_queens; i++){
        row = rand() % m_rows + 1;
        column = i + 1;

        if(check_for_collisions(row, column)){
            return false;
        }

        m_positions[i][ROW] = row;
        m_positions[i][COLUMN] = column;
    }

    return true;
}

// este metodo resuelve el problema de las n reinas
void Organizer::brute_force_solution(){
    bool is_solve = false;

    while(!is_solve){
        is_solve = make_a_trial();
    }
}

// esta funcion verifica si el problema fue resuelto
bool Organizer::is_solve(){
    for (int i = 0; i < m_number_of_queens; i++){
        // el problema fue resuelto si todas las posiciones son diferentes de cero
        if (m_positions[i][ROW] == 0 || m_positions[i][COLUMN] == 0){
            return false;
        }
    }

    return true;
}

// este metodo resuelve el problema de las n reinas usando backtraking
bool Organizer::backtracking_solution(int position){
    bool was_solve = false;

    if (position == 1){
        restart_state();
    }

    for (int i = 1; i < m_number_of_queens + 1; i++){
        // si no se tiene una posicion valida, se pasa a la siguiente iteracion
        if(check_for_collisions(i, position)){
            continue;
        }

        // si la posicion es valida, entonces se asignan los valores
        m_positions[position - 1][ROW] = i;
        m_positions[position - 1][COLUMN] = position;

        // si lo anterior se ejecuto y se esta en el caso base, entonces
        // el problema ya esta resuelto
        if(position == m_number_of_queens){
            return true;
        }

        // recursivamente se consiguen las posiciones de las demas reinas
        if (position < m_number_of_queens){
            was_solve = backtracking_solution(position + 1);
        }

        // si se resolvio el problema entonces se retorna true, en caso contrario
        // se dejan las posiciones en cero
        if(was_solve){
            return true;
        }else{
            m_positions[position - 1][ROW] = 0;
            m_positions[position - 1][COLUMN] = 0;
        }
    }
    
    // si se sale del for es porque no se encontro una solucion
    return false;
}

// para mostrar el tablero en pantalla
std::ostream& operator<< (std::ostream &out, const Organizer &organizer){
    for (int i = 1; i < organizer.m_rows + 1; i++){
        for (int j = 1; j < organizer.m_columns + 1; j++){
            bool queen_position = false;

            // se verifica si la posicion (i, j) corresponde a la de alguna reina
            for (int k = 0; k < organizer.m_number_of_queens; k++){
                if(organizer.m_positions[k][ROW] == i && organizer.m_positions[k][COLUMN] == j){
                    queen_position = true;
                    break;
                }
            }

            // en caso que la posicion corresponda a la de una reina se
            // imprime R, . en caso contrario
            if (queen_position){
                out << "R ";
            }else{
                out << ". ";
            }
        }

        out << '\n';
    }

    return out;
}

// TODO: este metodo debe ser implementado
// este metodo agrega una reina en el tablero, siempre que sea posible(si no entra
// en colision on otras reinas)
bool Organizer::locate_queen(int row, int column, bool overlap){
}
