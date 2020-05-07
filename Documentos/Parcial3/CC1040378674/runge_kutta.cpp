#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>

#include "runge_kutta.h"

// se debe pasar el array de ecuaciones(m funcionpes), como estas funciones siempre reciben
// la variable independiente como primer argumento, las funciones tendran un numero de
// argumentos igual a m + 1. a y b indican limite superior e inferior del intervalo
// respectivamente y0, es un puntero a un arreglo con las m condiciones iniciales. Se le
// ofrece al usuario 2 formas de inicializar la clase, si el usuario quiere una division
// conocidad para la variable indepenciente en el intervalo de integracion, debe especifica h,
// pero si al usuario le interesa fijar el numero de puntos solucion debe especificar el
// argumento steps, que indica cuantos pasos de integracion realizara el metodo
RungeKutta::RungeKutta(functype *functions, int order, double a, double b, double *y0, double h):
    m_a{a},
    m_b{b},
    m_h{h},
    m_step{0},
    m_total_steps{(int) ceil((b - a) / h) + 2},
    m_order{order} {

    // se pide memoria para el arreglo de funciones
    m_f = (functype *) malloc((size_t) sizeof(functype) * m_order);

    // se pide memoria para guardar los punto solucione
    // en m_time cada componente indica un paso en el tiempo
    m_time = (double *) malloc((size_t) sizeof(double) * m_total_steps);
    // este arreglo es bidimensional, la primera dimension es para los pasos en el tiempo,
    // la segunda componente es para cada una de las variables
    m_y = (double **) malloc((size_t) sizeof(double *) * m_total_steps);

    // se pide espacio para el guardado de las variables auxiliares que se usan en el metodo
    m_k1i = (double *) malloc((size_t) sizeof(double) * m_order);
    m_k2i = (double *) malloc((size_t) sizeof(double) * m_order);
    m_k3i = (double *) malloc((size_t) sizeof(double) * m_order);
    m_k4i = (double *) malloc((size_t) sizeof(double) * m_order);

    m_args = (double *) malloc((size_t) sizeof(double) * (m_order + 1));

    // siempre es mala idea no cambiar el valor de las variables una vez se pidio espacio
    // usando malloc pues esta tiene informacion basura y por errores de tipeo se pueden
    // usar, llevando a que c++ se comporte de forma inesperada
    for (int i = 0; i < m_total_steps; i++){
        m_time[i] = 0;

        // como m_y es bidimensional, se necesita pedir espacio en cada componente
        m_y[i] = (double *) malloc((size_t) sizeof(double) * m_order);

        // cambia el valor de las variables a cero
        for (int j = 0; j < m_order; j++){
            m_y[i][j] = 0;
        } 
    }

    // la condicion inicial en el tiempo es la del limite inferior del intervalo
    m_time[m_step] = a;

    for (int i = 0; i < m_order; i++){
        // condiciones iniciales de las variables
        m_y[m_step][i] = y0[i];
    
        // se guardan las variables
        m_f[i] = functions[i];

        // se cambia el valor de las variables a cero
        m_k1i[i] = 0;
        m_k2i[i] = 0;
        m_k3i[i] = 0;
        m_k4i[i] = 0;

        m_args[i] = 0;
    }
}

// en principio este constructor realiza las mismas operaciones que el constructor anterior, solo
// que se especifica un parametro diferente con el que se obtiene h, para no repetirnos, entonces
// delegamos el trabajo de este constructor al anterior
RungeKutta::RungeKutta(functype *functions, int order, double a, double b, double *y0, int steps):
    RungeKutta(functions, order, a, b, y0, (b - a) / steps){
}

RungeKutta::~RungeKutta(){
    // cuando se pide memoria de forma dinamica, esta debe ser liberada
    free(m_f);

    free(m_time);

    free(m_k1i);
    free(m_k2i);
    free(m_k3i);
    free(m_k4i);

    free(m_args);

    // m_y es un arreglo de punteros a double, en el que cada componente es un arreglo de double
    // por tanto se debe liberar la memoria de cada componente(liberar cada arreglo) 
    for (int i = 0; i < m_total_steps; i++){
        free(m_y[i]);
    }

    // una vez se ha liberado la memoria de cada componente, se debe liberar la memoria en la que
    // se guardan las componentes
    free(m_y);
}

// estos metodos arrojan informacion del integrador
double RungeKutta::get_h(){
    return m_h;
}

int RungeKutta::get_current_step(){
    return m_step;
}

int RungeKutta::get_total_steps(){
    return m_total_steps;
}

// este metodo solo avanza un paso en la solucion del problema, es decir, solo realiza
// el proceso de integracion hasta obtener el siguiente punto solucion. Retorna el
// valor de la variable independiente del paso que se calculo
double RungeKutta::next_step(){
    // se debe verificar si el sistema fue o no solucionado
    if (m_step >= m_total_steps){
        // si el paso actual(m_step) es igual o mayor al numero total de pasos, entonces
        // ya se soluciono el problema en todo su dominio, esto es, [a, b]
        return m_time[m_step];
    }
    
    // se organizan los argumentos para obtener k1i
    m_args[0] = m_time[m_step];
    for (int i = 1; i < m_order + 1; i++){
        m_args[i] = m_y[m_step][i - 1];
    }

    // se calcula cada k1i de acuerdo al metodo de Runge Kutta 4
    for (int i = 0; i < m_order; i++){
        m_k1i[i] = m_h * m_f[i](m_args);
    }

    // se organizan los argumentos para obtener k2i
    m_args[0] = m_time[m_step] + m_h / 2;
    for (int i = 1; i < m_order + 1; i++){
        m_args[i] = m_y[m_step][i - 1] + m_k1i[i - 1] / 2;
    }

    // se calcula cada k2i de acuerdo al metodo de Runge Kutta 4
    for (int i = 0; i < m_order; i++){
        m_k2i[i] = m_h * m_f[i](m_args);
    }

    // se organizan los argumentos para obtener k3i
    m_args[0] = m_time[m_step] + m_h / 2;
    for (int i = 1; i < m_order + 1; i++){
        m_args[i] = m_y[m_step][i - 1] + m_k2i[i - 1] / 2;
    }

    // se calcula cada k3i de acuerdo al metodo de Runge Kutta 4
    for (int i = 0; i < m_order; i++){
        m_k3i[i] = m_h * m_f[i](m_args);
    }

    // se organizan los argumentos para obtener k3i
    m_args[0] = m_time[m_step] + m_h;
    for (int i = 1; i < m_order + 1; i++){
        m_args[i] = m_y[m_step][i - 1] + m_k3i[i - 1];
    }

    // se calcula cada k4i de acuerdo al metodo de Runge Kutta 4
    for (int i = 0; i < m_order; i++){
        m_k4i[i] = m_h * m_f[i](m_args);
    }

    // se avanza un paso y se escribe el punto solucion en los arreglos correspondientes
    m_step++;
    m_time[m_step] = m_time[m_step - 1] + m_h;

    for (int i = 0; i < m_order; i++){
        m_y[m_step][i] = m_y[m_step - 1][i] + (m_k1i[i] + 2 * m_k2i[i] + 2 * m_k3i[i] + m_k4i[i]) / 6;
    }

    // se retorna el valor de la variable independiente en el paso recien calculado
    return m_time[m_step];
}


// este metodo resuelve el problema en todo el dominio especificado, lo realiza llamando
// iterativamente al metodo RungeKutta::next_step
void RungeKutta::solve(){
    // el metodo debe empezar a solucionar no desde el punto a en el intervalo, pues el
    // usuario en algun momento pudo haber llamado al metodo RungeKutta::next_step,
    // se debe iniciar a solucionar el problema desde el paso en el que se v
    for (int i = get_current_step(); i < m_total_steps - 1; i++){
        next_step();
    }
}

// con estos metodos se obtiene informacion de las soluciones en un paso determinado de
// una de las varibles deseadas
double RungeKutta::get_independent_variable(int step){
    // si el usuario se quiere pasar de listo y desea obtener un paso en el que no se
    // ha hallado la solucion, entonces se le da la ultima solucion
    int index = step > m_step ? m_step: step;

    return m_time[index];
}

double RungeKutta::get_dependent_variable_j(int step, int variable){
    // si el usuario se quiere pasar de listo y desea obtener un paso en el que no se
    // ha hallado la solucion, entonces se le da la ultima solucion
    int index = step > m_step ? m_step: step;

    // si el usuario se quiere pasar de listo y desea obtener una variable que no existe
    // entonces se le da la ultima variable del sistema
    int var_index = variable > m_order ? m_order : variable;

    return m_y[index][var_index];
}

// para escribir las soluciones en un archivo de texto
void RungeKutta::write_solution_to_file(const char *filename){
    FILE *output_file = fopen(filename, "w");

    // si el usuario no ha llamado al metodo RungeKutta::solve, entonces no se pueden
    // guardar todas las variables, solo se puede guardar hasta donde se haya solucionado
    // por eso el for va hasta get_current_step
    for (int i = 0; i < get_current_step(); i++){
        // la primera columna corresponde a la variable independiente
        fprintf(output_file, "%f ", m_time[i]);

        // cada columna corresponde a una variable determinada
        for (int j = 0; j < m_order; j++){
            fprintf(output_file, "%f ", m_y[i][j]);
        }

        fprintf(output_file, "\n");
    }

    fclose(output_file);
}
