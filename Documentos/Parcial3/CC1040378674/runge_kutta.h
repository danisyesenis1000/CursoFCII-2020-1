#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

typedef double (*functype)(double *);

// esta clase representa un integrador para un sistema de m ecuaciones
// que usa el metodo Runge Kutta de orden 4
class RungeKutta {
private:
    // especifican el intervalo de integracion
    double m_a;
    double m_b;

    // subdivision del intervalo de integracion
    double m_h;

    // esto guardara la direccion de memoria de las m funciones
    functype *m_f;

    // indica en que paso va el metodo
    int m_step;
    const int m_total_steps;

    // arreglo en el que se iran guardando los valores obtenidos
    double *m_time;
    double **m_y;

    // numero de ecuaciones a resolver, es m, el mismo numero de funciones
    // que se pasan como argumento
    int m_order;

    // variables usadas para la resolucion del sistema de ecuaciones, estas
    // variables son usadas para el metodo de Runge Kutta
    double *m_k1i;
    double *m_k2i;
    double *m_k3i;
    double *m_k4i;

    // las m funciones que se pasan como argumento, para que el metodo fuera lo
    // mas general posible, deben recibir un array de doubles, asi, esta clase
    // puede pasar m argumentos a cada funcion, donde m queda como un parametro
    // que el usuario especifica al instanciar la clase
    double *m_args;
public:
    // se debe pasar el array de ecuaciones(m funcionpes), como estas funciones siempre reciben
    // la variable independiente como primer argumento, las funciones tendran un numero de
    // argumentos igual a m + 1. a y b indican limite superior e inferior del intervalo
    // respectivamente y0, es un puntero a un arreglo con las m condiciones iniciales. Se le
    // ofrece al usuario 2 formas de inicializar la clase, si el usuario quiere una division
    // conocidad para la variable indepenciente en el intervalo de integracion, debe especifica h,
    // pero si al usuario le interesa fijar el numero de puntos solucion debe especificar el
    // argumento steps, que indica cuantos pasos de integracion realizara el metodo
    RungeKutta(functype *functions, int order, double a, double b, double *y0, double h=1e-3);
    RungeKutta(functype *functions, int order, double a, double b, double *y0, int steps);

    ~RungeKutta();

    // estos metodos arrojan informacion del integrador
    double get_h();
    int get_current_step();
    int get_total_steps();

    // no se hicieron setters para la clase pues cambiar una variable implica cambiar algunas
    // otras(y no habia tiempo para implementar esto, en una futura version tal vez este
    // esa funcionalidad), por ejemplo, si se cambia el numero de pasos, entonces h debe
    // cambiar de acuerdo a la formula h = (b - a) / #numero_pasos, no solo esto, todos los
    // arreglos creados en el constructor deben cambiar de acuerdo a la nueva configuracion,
    // aunque no estan los setters, esto no limita la funcionalidad de la clase, pues solo se
    // debe intanciar otro objeto.

    // este metodo solo avanza un paso en la solucion del problema, es decir, solo realiza
    // el proceso de integracion hasta obtener el siguiente punto solucion
    double next_step();

    // este metodo resuelve el problema en todo el dominio especificado, lo realiza llamando
    // iterativamente al metodo RungeKutta::next_step
    void solve();

    // con estos metodos se obtiene informacion de las soluciones en un paso determinado de
    // una de las varibles deseadas
    double get_independent_variable(int step);
    double get_dependent_variable_j(int step, int variable);

    // para escribir las soluciones en un archivo de texto
    void write_solution_to_file(const char *filename);
};

#endif
