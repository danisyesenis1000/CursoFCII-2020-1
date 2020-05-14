#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "runge_kutta.h"
#include "linear_shooting.h"

using namespace std;

// estos polinomios se definen de forma global para poder usarlos
// en las ecuaciones que se le pasan al integrador RungeKutta
real_value_function px;
real_value_function qx;
real_value_function rx;

// se pasa como parametro las variables que especifican el intervalo de integracion, las condiciones
// sobre cada extremo del intervalo y el numero de pasos del intervalo
LinearShooting::LinearShooting(double ini, double end, double con_ini, double con_end, double num_int) {
    set_initial_point(ini);
    set_final_point(end);
    set_interval_number(num_int);
    set_initial_condition_1(con_ini);
    set_initial_condition_2(con_end);
}

// para configurar parametros del integrador
void LinearShooting::set_initial_point(double ini){
    m_a = ini;
}

void LinearShooting::set_final_point(double end){
    m_b = end;
}

void LinearShooting::set_interval_number(double num_int){
    m_N = num_int;
}

void LinearShooting::set_initial_condition_1(double con_ini){
    m_alpha = con_ini;
}

void LinearShooting::set_initial_condition_2(double con_end){
    m_beta = con_end;
}

void LinearShooting::set_h(){
    m_h = (m_b - m_a) / m_N; 
}

// el problema de condiciones de frontera se vuelve 2 problemas de condiciones
// iniciales, especificados por las ecuaciones "y1" y "identity" para el problema 1
// de condiciones iniciales y "y2" y "identity" para el problema 2 de condiciones
// iniciales
double y1(double *args){
    // esta funcion no es mas que y'' = p(x) * y' + q(x) * y + r(x)
    return px(args[0]) * args[2] + qx(args[0]) * args[1] + rx(args[0]);
}

double y2(double *args){
    // y'' = p(x) * y' + q(x) * y
    return px(args[0]) * args[2] + qx(args[0]) * args[1];
}

// para resolver una ecuacion de orden 2 con el integrador de RungeKutta, se debe
// transformar el problema en un sistema de 2 ecuaciones haciendo el cambio de variable
// w = y', asi se obtiene las ecuaciones
// w' = f(t, y, w)
// y' = w = g(t, y, w)
// por tanto la segunda ecuacion es la funcion identidad en la segunda componente
double identity(double *args){
    return args[2];
}

void LinearShooting::integrate(vector<double> &X, vector<double> &w1, vector<double>&w2,
        real_value_function p, real_value_function q, real_value_function r){
    // el usuaio ingresa los polinomios del problema lineal y estos se asignan a las
    // variables globales, para que las funciones "y1" y "y2" puedan verlos
    px = p;
    qx = q;
    rx = r;

    // se configuran los arreglos que se pasan al integrador RungeKutta
    functype *functions = (functype *) malloc((size_t) sizeof(functype) * 2);
    functions[0] = identity;
    functions[1] = y1;

    // condiciones iniciales del problema
    double *initial_conditions = (double *) malloc((size_t) sizeof(double) * 2);
    initial_conditions[0] = m_alpha;
    initial_conditions[1] = 0;

    // se establece el paso
    set_h();

    // se crea el integrador para el primero problema de condiciones iniciales
    RungeKutta r_1(functions, 2, m_a, m_b, initial_conditions, m_h);

    // segundo sistema
    functions[0] = identity;
    functions[1] = y2;

    // condiciones iniciales
    initial_conditions[0] = 0;
    initial_conditions[1] = 1;

    // se crea el integrador para el segundo problema de condiciones iniciales
    RungeKutta r_2(functions, 2, m_a, m_b, initial_conditions, m_h);

    // se resuelven los problemas
    r_1.solve();
    r_2.solve();

    // se construye la solucion de acuerdo al metodo del disparo lineal en la que
    // y(x) = y1(x) + C * y2(x), en este caso C = slope
    double slope = (m_beta - r_1.get_dependent_variable_j(m_N, 0)) / r_2.get_dependent_variable_j(m_N, 0);

    X.push_back(r_1.get_independent_variable(0));
    w1.push_back(m_alpha);
    w2.push_back(slope);
    for (int i = 1; i < r_1.get_total_steps(); i++){
        X.push_back(r_1.get_independent_variable(i));

        w1.push_back(r_1.get_dependent_variable_j(i, 0) + slope * r_2.get_dependent_variable_j(i, 0));
        w2.push_back(r_1.get_dependent_variable_j(i, 1) + slope * r_2.get_dependent_variable_j(i, 1));
    }
}

// metodo que guarda la solucion en un archivo de texto
void LinearShooting::Imprimir(string nombre, vector<double>&X, vector<double>&w1, vector<double>&w2){
    // objeto para escribir en el archivo
    fstream archivo_sal(nombre.c_str(),ios::out);
    if(archivo_sal.fail()){
        cout << "Error al intentar abrir el archivo" << endl;
        exit(1);
    }
  
    for(int i=0;i<m_N+1;i++){
        archivo_sal << left << fixed << setprecision(5) << setw(6) << X[i] << " " << setw(6) << w1[i] << " " << setw(6) << w2[i] << endl;
    }

    archivo_sal.close();
}
