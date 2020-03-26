#include <iostream>
#include <stdlib.h>

using namespace std;

class complejo {       
  private:             
    double parteReal;        
    double parteImaginaria;  

  public:
  	void asignarDatos (double,double);
    double obtenerParteReal();
    double obtenerParteImaginaria();
    void suma(double,double);
    void resta(double,double);
    void imprimir();
};


void complejo::asignarDatos (double x, double y) {
  parteReal = x;
  parteImaginaria = y;
}

double complejo::obtenerParteReal(){
	return parteReal;
}

double complejo::obtenerParteImaginaria(){
	return parteImaginaria;
}

void complejo::suma(double x,double y){
	parteReal=parteReal+x;
	parteImaginaria=parteImaginaria+y;
}

void complejo::resta(double x,double y){
	parteReal=parteReal-x;
	parteImaginaria=parteImaginaria-y;
}

void complejo::imprimir(){
	cout<<parteReal<<"+"<<parteImaginaria<<"i"<<endl;
}


int main(){
	cout<<"Prueba:"<<endl; 
	complejo z;
	z.asignarDatos(3,5);
	cout<<z.obtenerParteReal()<<endl;
	cout<<z.obtenerParteImaginaria()<<endl;
	z.suma(2,4);
	z.imprimir();
	z.resta(7,6);
	z.imprimir();
	
}