/*El siguiente código define una clase llamada "Circular" que simula un movimiento circular y una clase hija de esta llamada "Espiral" que hereda su movimiento y le agrega un movimiento 
 en el eje z, generando así un movimiento es espiral. Se implementa para unos datos dados y se muestran las posiciones para cada tiempo de ambos movimientos*/

#include<iostream>
#include<cmath>

using namespace std;

//Definición de la clase Circular
class Circular{
	private:
		double radio, frecuencia, fase, ttotal; //radio, frecuencia angular, fase y tiempo total del movimiento circular
	
	public:
		double tinterv; //intervalo de tiempo
		int ninterv; //numero de intervalos de tiempo
		Circular(double, double, double, double, double, int); //Constructor
		~Circular(); //Destructor de la clase
		void xpos();
		void ypos();
		
};

//Definicion de la clase Espiral que hereda de la clase Circular
class Espiral : public Circular{
	private:
		float tinterv, vz, zi;
		int ninterv;           //Estos atributos son propios de Espiral, los demas los hereda de Circular, son la velocidad en z (vz) y posición inicial en z (zi) así como de los atributos privados de Circular que requiere implementar
	public:
		Espiral(double, double, double, double, double, int, float, float); //Constructor de la clase Espiral, como hereda, se debe poner de primero los atributos heredados, en este caso hereda los primeros 4 double
		~Espiral(); //Destructor
		void zpos(); //Función propia de la clase Espiral, posición en z
		
};

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

//Destructor de la clase circular
Circular::~Circular(){
}

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
	
	
}

//Funcion propia de la clase Espiral

void Espiral::zpos(){
	double _zpos[ninterv];
	for(int i=0; i<=ninterv; i++){
		_zpos[i]=zi+i*tinterv*vz;
		cout<<"La posicion en z en el tiempo "<<i*tinterv<<" es "<<_zpos[i]<<endl;
	}
}

int main(){
	cout<<"El movimiento circular tiene las siguientes posiciones: "<<endl;
	cout<<"                                                                    "<<endl;
	Circular circular1(1.0, 2.0, 0, 5, 0, 10);
	circular1.xpos();
	circular1.ypos();
	cout<<"                                                                    "<<endl;
	cout<<"####################################################################"<<endl;
	cout<<"                                                                    "<<endl;
	cout<<"El movimiento en espiral tiene las siguientes posiciones: "<<endl;
	cout<<"                                                                    "<<endl;
	Espiral espiral1(1.0, 2.0, 0, 5, 0, 10, 2.0, 3.0);
	espiral1.xpos();
	espiral1.ypos();
	espiral1.zpos();
	
	
	return 0;
}
