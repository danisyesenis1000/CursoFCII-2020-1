#include <cstdlib>

#include "runge_kutta.h"

void test();

double i1(double *args){
    return -4 * args[1] + 3 * args[2] + 6;
}

double i2(double *args){
    return -2.4 * args[1] + 1.6 * args[2] + 3.6;
}

int main(){
    test();

    return 0;
}

void test(){
    functype *functions = (functype *) malloc((size_t) sizeof(functype) * 2);
    functions[0] = i1;
    functions[1] = i2;

    double *initial_conditions = (double *) malloc((size_t) sizeof(double) * 2);
    initial_conditions[0] = 0;
    initial_conditions[1] = 0;

    RungeKutta r(functions, 2, 0, 0.5, initial_conditions, 0.1);

    r.solve();

    r.write_solution_to_file("2_equations.txt");

    free(functions);
    free(initial_conditions);
}
