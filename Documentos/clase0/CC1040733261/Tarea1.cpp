#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	      // definiendo los valores a introducir y hoperar
	      //como flotantes
	double lar, anc, prof, per, vol, aresup, h, p;
	cout<<"este programa le ofrese saber: el perimetro, volumen y el área de la superficie subterranea de su piscina. Para esto usted debe de ingresar los valores:largo, ancho y profundidad, ingresandolos a medida de que se los vayamos pidiendo comencemos"<<endl;
	cout<<"por favor imgrese el largo: "<<endl;
	cin>>lar;
	cout<<"por favor imgrese el ancho: "<<endl;
	cin>>anc;
	cout<<"por favor imgrese la profundidad: "<<endl;
	cin>>prof;
	h=lar*anc;
	p=lar+anc;
	    //imprime el titulo en este se encuentra los valores ingresados 
	    // y el resultado
	cout<<"teniendo en cuenta que ADSS es el área de la superficie subterranea, los resultados son:\n";
	cout<<"largo       ancho       profundidad       perimetro       volumen       ADSS\n";
	cout<<"------      ------      -----------       ----------     --------      -------\n";
	per=2*p;
	vol=h*prof;
	aresup=(2*p*prof)+h;
	cout<<setw(8
	)<<setiosflags(ios::showpoint)
	<<setw(5)<<lar<<setw(11)<<anc<<setw(15)<<prof
	<<setw(17)<<per<<setw(15)<<vol<<setw(13)<<aresup<<endl;
	return 0;
}
	
