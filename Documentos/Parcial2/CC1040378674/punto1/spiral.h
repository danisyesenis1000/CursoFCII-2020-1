#ifndef SPIRAL_H
#define SPIRAL_H

#include "circular.h"

class Spiral: public Circular {
private:
    double m_z0;
    double m_vz;
public:
    // el usuario puede crear la clase inicializando todos los paramtros
    Spiral(double radius, double angular_frequency, double dt, double time,
             double number_of_time_intervals, double fase, double z0, double vz);
    // el usuario puede usar la clase sin inicializar nada, pero se debe tener
    // cuidado, pues se le esta permitiendo usar los getters de los atributos
    Spiral();
    ~Spiral();

    // metodos que brindan informacion de los atributos de clase
    double get_z0();
    double get_vz();

    // metodos para cambiar los valores de los atributos de clase
    double set_z0(double z0);
    double set_vz(double vz);

    // metodo para obtener la posicion en "z" de la particula
    double get_z_pos(double time);

    // metodo que mueve la particula durante el tiempo especificado
    // en los atributos de clase con los parametros actuales y se
    // van guardando los datos en array(se esta usando sobrecarga de metodos)
    int move_and_track(double *&x, double *&y, double *&z);

    // metodo que mueve la particula durante el tiempo especificado
    // en los atributos de clase con los parametros actuales y se
    // van guardando los datos en un archivo de texto
    void move_and_track(const char *filename);
};

#endif
