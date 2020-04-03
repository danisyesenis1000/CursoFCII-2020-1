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
complejo::complejo(double R1,double I1,double R2,double I2){ //Constructor
	parteReal1=R1;
	parteReal2=R2;
	parteImaginaria1=I1;
	parteImaginaria2=I2;	
}
void complejo::asignarDatos(double r1, double i1, double r2, double i2){
	parteReal1=r1;
	parteReal2=r2;
	parteImaginaria1=i1;
	parteImaginaria2=i2;
}
 double complejo::sumaReal(){
	 return(parteReal1+parteReal2);	
}
double complejo::restaReal(){
	 return parteReal1-parteReal2;	
}

 double complejo::sumaImaginario(){
	 return(parteImaginaria1+parteImaginaria2);	
}

double complejo::restaImaginario(){
	 return parteImaginaria1-parteImaginaria2;	
}

void complejo::imprimirsuma(){
	cout<<"La suma de los numeros es:  "<<sumaReal()<< " + "<<sumaImaginario()<<"i"<<endl;
}
void complejo::imprimirresta(){
	cout<<"La resta de los numeros es:  "<<restaReal()<<" + " <<restaImaginario()<<"i"<<endl;
}

void complejo::obtenerParteRealSuma(){
	cout<<"La parte real para la suma es:  "<<sumaReal()<<endl;
}

void complejo::obtenerParteImaginariaSuma(){
	cout<<"La parte imaginaria para la suma es:  "<<sumaImaginario()<<endl;
}
void complejo::obtenerParteRealResta(){
	cout<<"La parte real para la resta es:  "<<restaReal()<<endl;
}

void complejo::obtenerParteImaginariaResta(){
	cout<<"La parte imaginaria para la resta es:  "<<restaImaginario()<<endl;
}

int main(){ //se prueba cada uno de los metodos de la clase
	complejo Z(2,4,1,3);
	Z.imprimirsuma();
	Z.imprimirresta();
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaSuma();
	Z.obtenerParteRealResta();
	Z.obtenerParteImaginariaResta();
	Z.asignarDatos(5,6,4,8);
	Z.imprimirsuma();
	Z.imprimirresta();	
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaResta();
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaResta();	

return 0;	
}
