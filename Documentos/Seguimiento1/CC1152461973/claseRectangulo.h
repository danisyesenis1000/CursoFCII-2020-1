#include <iostream>
#include <stdlib.h>
using namespace std;

//definamos la clase del rectangulo
class Rectangulo{
	private:
		double largo, ancho;
	public:
		Rectangulo(double,double);
		double perimetro();
		double area();	
		void AsignarDatos(double, double);
		void AsignarAncho(double);
		void AsignarLargo(double);
		void MostrarDatos();
		void ObtenerAncho();
		void ObtenerLargo();
};
