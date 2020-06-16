#include <cmath>

#include "linear_shooting.h"

// polinomios que definen el problema lineal
double p(double x){
    return 0.0;
}

double q1(double x){
    return -pow((M_PI/10.0),2);
}

double q2(double x){
    return -pow((2*M_PI/10.0),2);
}

double q3(double x){
    return -pow((3*M_PI/10.0),2);
}

double q4(double x){
    return -pow((4*M_PI/10.0),2);
}

double r(double x){
    return 0.0;
}

void test();

int main(){
    test();

    return 0;
}

void test(){
    // se definen los vectores
    vector<double> pos;
    vector<double> y;
    vector<double> y_p;

    // se instancia el integrador y se configuran parametros para solucionar 
    LinearShooting integrar(10.0, 20.0, 0.0, 10.0, 1000.0);

    integrar.integrate(pos, y, y_p, p, q1, r);
    integrar.Imprimir("datos1.txt", pos, y, y_p);
    pos.clear();
    y.clear();
    y_p.clear();

    integrar.integrate(pos, y, y_p, p, q2, r);
    integrar.Imprimir("datos2.txt", pos, y, y_p);
    pos.clear();
    y.clear();
    y_p.clear();

    integrar.integrate(pos, y, y_p, p, q3, r);
    integrar.Imprimir("datos3.txt", pos, y, y_p);
    pos.clear();
    y.clear();
    y_p.clear();

    integrar.integrate(pos, y, y_p, p, q4, r);
    integrar.Imprimir("datos4.txt", pos, y, y_p);
}
