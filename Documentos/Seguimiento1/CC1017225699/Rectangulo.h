// Rectangulo.h
// Definición de la clase Rectangulo. Este archivo presenta
// interfaz publica sin revelar las implementaciones de los miembros de las
// funciones, que se definen en Rectangulo.cpp

#include <string>
//using std::string;

// Rectangulo class definition
class Rectangulo
{
public:
    Rectangulo( double, double ); 
    void setLargo( double );
    void setAncho( double );
    void setArea( double, double );
    void setPerimetro( double, double ); 
    double getLargo();
    double getAncho();
    double getArea();
    double getPerimetro(); 
    void displayMessage(); 
private:
    double RecLargo;
    double RecAncho;
    double RecArea;
    double RecPerimetro;   
};  
