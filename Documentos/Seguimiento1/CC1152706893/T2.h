/*Tarea
Diseñe una clase llamada Rectangulo que tenga como datos miembro en doble precision largo y ancho. y las funciones miembro  de asignarDatos,asignarAncho, asignarLargo, area, perimetro,
mostrarDatos, obtenerAncho y obtenerLargo.*/

//Declaración de clase

class Rectangulo
{
	private: //datos miembro 
	double largo;
	double ancho;
	
	public: //funciones miembro
		Rectangulo(double = 0, double = 0);
		void asignarDatos(double, double);
		double asignarAncho(double);
		double asignarLargo(double);
		float area();
		float perimetro();
		void mostrarDatos();
		void obtenerAncho();
		void obtenerLargo();
		
	};

