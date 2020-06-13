#include "Automaton.h"

// size of the grid of spins
#define SIZE 100
// amount of points for the magnetization
#define N_points 200
// size of the initial condition for the automata
#define SIZE1 100

void automaton_default();
void automaton_from_terminal();
void magnetization_simulation();

int main(){
    // automaton_default();
    // automaton_from_terminal();
    magnetization_simulation();

    return 0;
}

void automaton_default(){
    // Pass the initial condition and the rule
    Automaton game1;
                        
    int a[SIZE1] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, \
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    game1.Automaton_1D(126, SIZE1, 100, a);
}

void automaton_from_terminal(){
    // Everything with the terminal
    Automaton game1;
    game1.Automaton_1D();
}

void magnetization_simulation(){
    //==============================================================================================================
    //========== simulating the Ising model with a ferromagnetic material ==========================================
    //==============================================================================================================
    Automaton ISING;
    
    // Temperatures
    double T1 = 1.0;
    double T2 = 3.0;
    double T3 = 6.0;
    double *Field = NULL;
    
    // Full the vector of values of the magnetic field
    Field = ISING.Linspace(-15.0, 15.0, N_points);

    double mag1[N_points] = {0.0};
    double mag2[N_points] = {0.0};
    double mag3[N_points] = {0.0};
  
    for(int i = 0; i < N_points; i++){
        *(mag1 + i) = ISING.Magnetization_Graph(SIZE, 0, 0, Field[i], 100000, 1.0 / T1);
        *(mag2 + i) = ISING.Magnetization_Graph(SIZE, 0, 0, Field[i], 100000, 1.0 / T2);
        *(mag3 + i) = ISING.Magnetization_Graph(SIZE, 0, 0, Field[i], 100000, 1.0 / T3);
    }

    ISING.Print_File("Field.txt", N_points, Field);
    ISING.Print_File("Mag1.txt", N_points, mag1);
    ISING.Print_File("Mag2.txt", N_points, mag2);
    ISING.Print_File("Mag3.txt", N_points, mag3);

    free(Field);
}
