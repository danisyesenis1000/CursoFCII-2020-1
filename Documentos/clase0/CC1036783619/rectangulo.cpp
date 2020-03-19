#include <iostream>
#include <stdlib.h>
using namespace std;

class Rectangulo{
	private:
		double largo, ancho;
	public:
		Rectangulo(double,double);
		double perimetro();
		double area();	
		void asignarDatos(double, double);
		void asignarAncho(double);
		void asignarLargo(double);
		void mostrarDatos();
		void obtenerLargo();
		void obtenerAncho();
};
Rectangulo::Rectangulo(double largo0, double ancho0){
	largo=largo0;
	ancho=ancho0;	
}
void Rectangulo::asignarDatos(double largoi, double anchoi){
	largo=largoi;
	ancho=anchoi;
}
void Rectangulo::asignarAncho(double anchoi){
	ancho=anchoi;
}
void Rectangulo::asignarLargo(double largoi){
	largo=largoi;
}
 double Rectangulo::area(){
	 return(largo*ancho);	
}
double Rectangulo::perimetro(){
	 return 2*largo + 2*ancho;	
}
void Rectangulo::obtenerLargo(){
	cout<<"El largo es: "<<largo<<endl;
}
void Rectangulo::obtenerAncho(){
	cout<<"El ancho es: "<<ancho<<endl;
}
void Rectangulo::mostrarDatos(){
	cout<<"El area es: "<<area()<<endl;
	cout<<"El perimetro es: "<<perimetro()<<endl;

}

int main(){
	double a,b;
	Rectangulo R(4,5);
	R.mostrarDatos();
	R.obtenerAncho();
	R.obtenerLargo();
return 0;	
}
