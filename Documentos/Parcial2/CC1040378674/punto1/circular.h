#ifndef CIRCULAR_H
#define CIRCULAR_H

class Circular {
private:
    double m_radius;
    double m_angular_frequency;
    double m_dt;
    double m_time;
    double m_number_of_time_intervals;
    double m_fase;
public:
    // el usuario puede crear la clase inicializando todos los paramtros
    Circular(double radius, double angular_frequency, double dt, double time,
             double number_of_time_intervals, double fase);
    // el usuario puede usar la clase sin inicializar nada, pero se debe tener
    // cuidado, pues se le esta permitiendo usar los getters de los atributos
    Circular();
    ~Circular();

    // metodos que brindan informacion de los atributos de clase
    double get_radius();
    double get_angular_frequency();
    double get_dt();
    double get_time();
    double get_number_of_time_intervals();
    double get_fase();

    // metodos para cambiar los valores de los atributos de clase
    double set_radius(double radius);
    double set_angular_frequency(double angular_frequency);
    double set_dt(double dt);
    double set_time(double time);
    double set_number_of_time_intervals(double number_of_time_intervals);
    double set_fase(double fase);

    // metodos para obtener la posicion en "x" y "y" de la particula 
    double get_x_pos(double time);
    double get_y_pos(double time);

    // metodo que mueve la particula durante el tiempo especificado
    // en los atributos de clase con los parametros actuales y se
    // van guardando los datos en array(se esta usando sobrecarga de metodos)
    int move_and_track(double *&x, double *&y);

    void save_positions_to_file(const char *filename, const char *header,
                                int columns, int length, double **positions);

    // metodo que mueve la particula durante el tiempo especificado
    // en los atributos de clase con los parametros actuales y se
    // van guardando los datos en un archivo de texto
    void move_and_track(const char *filename);
};

#endif
