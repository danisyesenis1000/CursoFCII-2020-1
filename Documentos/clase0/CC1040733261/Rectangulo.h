
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Rectangulo
{
	public:
	Rectangulo(double=0, double=0); 
	void asignarDatos (double, double);	
    double asignarAncho();
    double asignarLargo();
    double Area();
    double Perimetro(); 
    void mostrarDatos();
    void obtenerAncho();
    void obtenerLargo();
    
	private:
	double Largo, Ancho; 
	
  
};
