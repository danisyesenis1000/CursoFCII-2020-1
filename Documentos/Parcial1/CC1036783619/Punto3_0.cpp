#include <iostream>
#include <stdlib.h>
#include "Punto3.h"
using namespace std;

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
