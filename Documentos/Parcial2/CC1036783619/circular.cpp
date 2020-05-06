#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include "circular.h"
//Constructor de la clase Circular
Circular::Circular(double _radio, double _frecuencia, double _fase, double _ttotal, double _tinterv, int _ninterv){
	_tinterv=_ttotal/_ninterv;
	radio=_radio;
	frecuencia=_frecuencia;
	fase=_fase;
	ttotal=_ttotal;
	ninterv=_ninterv;
	tinterv= _tinterv;
}

Circular::~Circular(){
	
}

//Definición de funciones miembro de la clase Circular
void Circular::xpos(){ //Posición en x
	
	double _xpos[ninterv];
	for(int i=0; i<=ninterv; i++){
		_xpos[i]=radio*cos(frecuencia*i*tinterv+fase);
		cout<<"La posicion en x en el tiempo "<<i*tinterv<<" es "<<_xpos[i]<<endl;
	}
	
	
}

void Circular::ypos(){ //Posición en y
	
	double _ypos[ninterv];
	for(int i=0; i<=ninterv; i++){
		_ypos[i]=radio*sin(frecuencia*i*tinterv+fase);
		cout<<"La posicion en y en el tiempo "<<i*tinterv<<" es "<<_ypos[i]<<endl;
	}
	
	
};


