#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "circular.h"

// solo se necesitan inicializar las variables en el constructor
Circular::Circular(double radius, double angular_frequency, double dt,
                   double time, double number_of_time_intervals, double fase):
                   m_radius{radius}, m_angular_frequency{angular_frequency},
                   m_dt{dt}, m_time{time},
                   m_number_of_time_intervals{number_of_time_intervals},
                   m_fase{fase}{
}

// este contructor ofrece una alternativa para los usuarios peresozos, permite
// crear un objeto sin pasar parametros, como el usuario puede despues de esto
// usar los getters(aunque las variables no esten inicializadas), se delega
// la inicializacion al constructor anterior, esto evita comportamiento
// inesperados en c++ debido a la no inicializacion
Circular::Circular(): Circular(0, 0, 0, 0, 0, 0){

}

// no hay procesos importantes para el destructor, por eso no hay codigo
Circular::~Circular(){
}

// metodos que brindan informacion de los atributos de clase
double Circular::get_radius(){
    return m_radius;
}

double Circular::get_angular_frequency(){
    return m_angular_frequency;
}

double Circular::get_dt(){
    return m_dt;
}

double Circular::get_time(){
    return m_time;
}

double Circular::get_number_of_time_intervals(){
    return m_number_of_time_intervals;
}

double Circular::get_fase(){
    return m_fase;
}

// para todos los setters se agrego la posibilidad de obtener el valor
// que se tenia antes del cambio del valor de la variable
double Circular::set_radius(double radius){
    double previus_value = m_radius;
    m_radius = radius;

    return previus_value;
}

double Circular::set_angular_frequency(double angular_frequency){
    double previus_value = m_angular_frequency;
    m_angular_frequency = angular_frequency;

    return previus_value;
}

double Circular::set_dt(double dt){
    double previus_value = m_dt;
    m_dt = dt;

    return previus_value;
}

double Circular::set_time(double time){
    double previus_value = m_time;
    m_time = time;

    return previus_value;
}

double Circular::set_number_of_time_intervals(double number_of_time_intervals){
    double previus_value = m_number_of_time_intervals;
    m_number_of_time_intervals = number_of_time_intervals;

    return previus_value;
}

double Circular::set_fase(double fase){
    double previus_value = m_fase;
    m_fase = fase;

    return previus_value;
}

// para los metodos get_x_pos y get_y_pos se pasa time como parametro
// pues el atributo m_time especifica el tiempo que se desea se mueva
// la particula, conceptualmente time y m_time son distintos
double Circular::get_x_pos(double time){
    return m_radius * cos(m_angular_frequency * time + m_fase);
}

double Circular::get_y_pos(double time){
    return m_radius * sin(m_angular_frequency * time + m_fase);
}

// se debe pasar una referencia al puntero, pues se desea cambiar
// la direccion a la que apunta, se retorna la longitud de los arreglos
int Circular::move_and_track(double *&x, double *&y){
    // cantidad de campos requeridos para almacenar todas las posiciones
    int length = m_time / m_dt;

    x = (double *) malloc((size_t) sizeof(double) * length);
    y = (double *) malloc((size_t) sizeof(double) * length);

    for (int i = 0; i < length; i++){
        x[i] = get_x_pos(m_dt * i);
        y[i] = get_y_pos(m_dt * i);
    }

    return length;
}

// este metodo guardad arrays en un archivo de texto
void Circular::save_positions_to_file(const char *filename, const char *header,
                            int columns, int length, double **positions){
    FILE *output = fopen(filename, "w");

    fprintf(output, "%s\n", header);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < columns; j++){
            fprintf(output, "%f ", positions[j][i]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
}

// metodo que mueve la particula durante el tiempo especificado
// en los atributos de clase con los parametros actuales y se
// van guardando los datos en un archivo de texto
void Circular::move_and_track(const char *filename){
    double **positions = (double **) malloc((size_t) sizeof(double *) * 2);
    int length = move_and_track(positions[0], positions[1]);

    save_positions_to_file(filename, "x y", 2, length, positions);
}