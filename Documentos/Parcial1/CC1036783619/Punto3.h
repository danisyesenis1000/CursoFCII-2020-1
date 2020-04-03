#include <iostream>
#include <stdlib.h>
using namespace std;
class complejo{ //Crea la clase
	private:
		double parteReal1, parteImaginaria1, parteReal2, parteImaginaria2;
	public: //metodos
		complejo(double,double,double,double); 
		double sumaReal();  //suma de las partes reales
		double restaReal();	 //resta de las partes reales
		double sumaImaginario(); //suma de las partes imaginarias
		double restaImaginario(); //resta de las partes imaginarias
		void asignarDatos(double, double, double, double); //asigna datos de los complejos
		void imprimirsuma(); //imprime el resultado de la suma de los complejos
		void imprimirresta(); //imprime el resultado de la resta de los complejos
		void obtenerParteRealSuma(); //obtiene la parte real de la suma
		void obtenerParteImaginariaSuma(); //obtiene la parte imaginaria de la suma
		void obtenerParteRealResta(); //obtiene la parte real de la resta
		void obtenerParteImaginariaResta(); //obtiene la parte imaginaria de la resta
};
