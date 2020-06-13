#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

class Automaton{
public:
    Automaton();
    ~Automaton();

    // first way to run the game, this way get it all from terminal
    void Automaton_1D();
    // second way to run thr game, from the main you give: Rule, number
    // of entries of the initial condition , number of steps , initial condition
    void Automaton_1D(int , int , int , int *);
    
    // give one step in the evolution
    void Evolution(int , int , int **, int **);

    // Print double pointer in the screen
    void Print(int , int , int **);
    // Print pointer in the screen
    void Print(int , int *); 
    void Print(int , double *);
    // Print pointer in a File
    void Print_File(string , int , double *, int =5);
    void Print_File(string , int , int , int **);

    // funtion for the allocation of memory of the matrix
    int** Alloc_Int(int , int , int);
    // change one number in decimal form to binary form
    void To_Binary(int , int *);
    // initialization of the matrix in zeros, or 1 and -1 for the spin
    void Full(int **);
    void Set_dim(int );
    void Set_rule(int );

    // calculate of magnetization like the sum of the spins in the grid
    int Magnetization(int , int , int **);
    double Spin_Energy(double , double , int , int , int , int **);
    double Magnetization_Graph(int , int , double , double , int , double);
    // create a array with an amount of data same sapced between two limits
    double* Linspace(double , double , int );
private:
    int dim;
    int rule;
    int **M;
    // double pointer for giving the rules of evolution of the automata
    int **Dicc;
};

#endif
