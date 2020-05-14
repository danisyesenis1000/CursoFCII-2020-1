#ifndef LINEAR_SHOOTING_H
#define LINEAR_SHOOTING_H

#include <vector>
#include <string>

#include "runge_kutta.h"

using namespace std;

// como se desea resolver solo el problema lineal(el usuario solo debe definir un
// polinomio, es decir, una funcion que recibe y retorna un double), el usuario no
// se debe preocupar por funciones que reciban o retornen arreglos
typedef double (*real_value_function)(double);

class LinearShooting {
private:
    // especifican el intervalo de integracion
    double m_a;
    double m_b;

    // especifican las condiciones de frontera, en a y b respectivamente
    double m_alpha;
    double m_beta;

    // numero de puntos en los que se particiona el intervalo
    double m_N;

    // subdivision del intervalo de integracion
    double m_h;
public:
    LinearShooting(double, double, double, double, double);

    // para configurar parametros del integrador
    void set_h(void);
    void set_initial_point(double);
    void set_final_point(double);
    void set_interval_number(double);
    void set_initial_condition_1(double);
    void set_initial_condition_2(double);

    // este metodo soluciona la ecuacion en todo el dominio, se le pasan los
    // los vectores en los que se guardaran, la variable independiente,
    // la variable dependiente y y su primera derivada (y en ese mismo orden),
    // tambien se le pasan los polinomios que definen el problema lineal
    void integrate(vector<double> &X, vector<double> &w1, vector<double>&w2,
        real_value_function, real_value_function, real_value_function);
    
    // metodo que guarda la solucion en un archivo de texto
    void Imprimir(string, vector<double>&, vector<double>&, vector<double>&);
};

#endif
