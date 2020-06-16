#include "circular.h"
//Definicion de la clase Espiral que hereda de la clase Circular
class Espiral : public Circular{
	private:
		float tinterv, vz, zi;
		int ninterv;           //Estos atributos son propios de Espiral, los demas los hereda de Circular, son la velocidad en z (vz) y posici�n inicial en z (zi) as� como de los atributos privados de Circular que requiere implementar
	public:
		Espiral(double, double, double, double, double, int, float, float); //Constructor de la clase Espiral, como hereda, se debe poner de primero los atributos heredados, en este caso hereda los primeros 4 double
		~Espiral(); //Destructor
		void zpos(); //Funci�n propia de la clase Espiral, posici�n en z
		
};
