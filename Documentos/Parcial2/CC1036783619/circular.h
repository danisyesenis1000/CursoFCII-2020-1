#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Definición de la clase Circular
class Circular{
	private:
		double radio, frecuencia, fase, ttotal; //radio, frecuencia angular, fase y tiempo total del movimiento circular
	
	public:
		double tinterv; //intervalo de tiempo
		int ninterv; //numero de intervalos de tiempo
		Circular(double, double, double, double, double, int); //Constructor
		~Circular(); //Destructor de la clase
		void xpos();
		void ypos();
		
};
