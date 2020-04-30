#include <cstdlib>

#include "spiral.h"

Spiral::Spiral(double radius, double angular_frequency, double dt, double time,
             double number_of_time_intervals, double fase, double z0, double vz):
             Circular{radius, angular_frequency, dt, time,
            number_of_time_intervals, fase}, m_z0{z0}, m_vz{vz}{
}

// este contructor ofrece una alternativa para los usuarios peresozos, permite
// crear un objeto sin pasar parametros, como el usuario puede despues de esto
// usar los getters(aunque las variables no esten inicializadas), se delega
// la inicializacion al constructor anterior, esto evita comportamiento
// inesperados en c++ debido a la no inicializacion
Spiral::Spiral(): Spiral(0, 0, 0, 0, 0, 0, 0, 0){

}

// no hay procesos importantes para el destructor, por eso no hay codigo
Spiral::~Spiral(){
}

// no hay procesos importantes para el destructor, por eso no hay codigo
double Spiral::get_z0(){
    return m_z0;
}

double Spiral::get_vz(){
    return m_vz;
}

// para todos los setters se agrego la posibilidad de obtener el valor
// que se tenia antes del cambio del valor de la variable
double Spiral::set_z0(double z0){
    double previus_value = m_z0;
    m_z0 = z0;

    return previus_value;
}

double Spiral::set_vz(double vz){
    double previus_value = m_vz;
    m_vz = vz;

    return previus_value;
}


// metodo para obtener la posicion en "z" de la particula
double Spiral::get_z_pos(double time){
    return m_z0 + m_vz * time;
}

// metodo que mueve la particula durante el tiempo especificado
// en los atributos de clase con los parametros actuales y se
// van guardando los datos en array(se esta usando sobrecarga de metodos)
int Spiral::move_and_track(double *&x, double *&y, double *&z){
    int length = Circular::move_and_track(x, y);
    z = (double *) malloc((size_t) sizeof(double) * length);

    for (int i = 0; i < length; i++){
        z[i] = get_z_pos(Circular::get_dt() * i);
    }

    return length;
}

// metodo que mueve la particula durante el tiempo especificado
// en los atributos de clase con los parametros actuales y se
// van guardando los datos en un archivo de texto
void Spiral::move_and_track(const char *filename){
    double **positions = (double **) malloc((size_t) sizeof(double *) * 3);

    int length = move_and_track(positions[0], positions[1], positions[2]);
    save_positions_to_file(filename, "x y z", 3, length, positions);
}
