#include <iostream>

using namespace std;

double det2( double a, double b, double c, double d);//prototipo de la funcion determinante 2x2
double det3( double e, double f, double g, double h, double i, double j, double k, double l, double m);//prototipo de la funcion determinante 3x3
int main(){
	double a11, a12, a21, a22;
	double b11, b12, b13, b21, b22, b23, b31, b32, b33;
	double detII, detIII;
	cout<<"Por favor ingrese los elementos de la matriz 2x2 en el siguiente orden: "<<endl;
	cout<<"a11  a12 a21 a22 "<<endl;
	cin>>a11>>a12>>a21>>a22;
	
	detII= det2(a11, a12, a21, a22);//llamado de la función 2x2 para el determinante 2x2
	cout<<"el dererminante de la matriz 2x2 es "<< detII<<endl;
	
	cout<<"¡Muy bien! Ahora por favor ingrese los elementos de la matriz 3x3 en el siguiente orden: "<<endl;
	cout<<" a11 a12 a13 a21 a22 a23 a31 a32 a33 "<<endl;
	cin>>b11>>b12>>b13>>b21>>b22>>b23>>b31>>b32>>b33;   
	detIII=det3(b11, b12, b13, b21, b22, b23, b31, b32, b33);//llamado de la función 3x3
	cout<<"el determinante de la matriz 3x3 es: "<<detIII<<endl;
	//getch(); 
	return 0;
}
//definicion de función determinante 2x2
double det2( double a, double b, double c, double d){
	double det1;
	det1=(a*d)-(b*c);
	
	return det1;
}
double det3( double e, double f, double g, double h, double i, double j, double k, double l, double m){//definición de la función determinante 3x3
	double deta;
	deta=(e*det2( i, j, l, m))-(h*det2( f, g, l, m))+(k*det2(f, g, i, j));//llamado de la función determinante 2x2 para definir la funciíon determinante 3x3
	
	return deta;
}


	
