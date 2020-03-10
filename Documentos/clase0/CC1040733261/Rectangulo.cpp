
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
#include "Rectangulo.h" //importando la clace Rectangulo
Rectangulo::Rectangulo (double L, double A)
{
	asignarDatos(L,A); 
}

void Rectangulo::asignarDatos(double Larg, double Anch) 
{
	cout<<"este programa le calcula el area y perimetro de un rectangulo"<<endl;
	cout<<"por favor imgrese el Largo: \n"<<endl;
	cin>>Larg;
	cout<<"por favor imgrese el ancho: \n"<<endl;
	cin>>Anch;	
	Largo=Larg;
	Ancho=Anch;
}

double Rectangulo::asignarLargo()//inicia la entrada del largo
{
	
	return Largo;
}

double Rectangulo::asignarAncho()//inicia la entrada del Ancho
{
	
	return Ancho;
}

void Rectangulo::obtenerLargo()
{
	cout<<setw(10)<<"Largo = "<<setprecision(2)<<asignarLargo()<<endl;
}

void Rectangulo::obtenerAncho()
{
	cout<<setw(10)<<"Ancho = "<<setprecision(2)<<asignarAncho()<<endl;
}

double Rectangulo::Perimetro()
{
	return (2*asignarLargo())+(2*asignarAncho());
}

double Rectangulo::Area()
{
	return asignarLargo()*asignarAncho();
}

void Rectangulo::mostrarDatos()
{
	cout<<fixed<<setprecision(2)<<"Largo "<<asignarLargo()<<endl;
	cout<<fixed<<setprecision(2)<<"Ancho "<<asignarAncho()<<endl;
	cout<<fixed<<setprecision(2)<<"Perimetro "<<Perimetro()<<endl;
	cout<<fixed<<setprecision(2)<<"Area "<<Area()<<endl;
}
