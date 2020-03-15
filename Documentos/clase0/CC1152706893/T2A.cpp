#include <iostream>
using namespace std; 
#include "T2.h"

int main() //funcion principal
{
	Rectangulo RectanguloA;
	
	RectanguloA.asignarDatos(10,10);
	RectanguloA.mostrarDatos();
	RectanguloA.obtenerAncho();
	RectanguloA.obtenerLargo();
	
	return 0;
	
}
