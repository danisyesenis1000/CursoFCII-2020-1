#include<iostream>
#include<cmath>
#include "espiral.h"

//Constructor de la clase Espiral donde se identifica qué se hereda de la clase Circular
Espiral::Espiral(double _radio, double _frecuencia, double _fase, double _ttotal, double _tinterv, int _ninterv, float _vz, float _zi):Circular( _radio, _frecuencia, _fase, _ttotal, _tinterv, _ninterv){
	_tinterv=_ttotal/_ninterv;
	ninterv=_ninterv;
	tinterv= _tinterv;
	vz=_vz;
	zi=_zi;
}

//Destructor de la clase Espiral
Espiral::~Espiral(){
} 

//Funcion propia de la clase Espiral

void Espiral::zpos(){
	double _zpos[ninterv];
	for(int i=0; i<=ninterv; i++){
		_zpos[i]=zi+i*tinterv*vz;
		cout<<"La posicion en z en el tiempo "<<i*tinterv<<" es "<<_zpos[i]<<endl;
	}
}
