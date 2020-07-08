#include <iostream>
#include <cmath>
using namespace std;
void copoVonkoch(double l, double n);
void kochCurva(double xi, double yi, double xf, double yf, double n);

int main(){
	double b;
	copoVonkoch(200, 2);
	b=copoVonkoch(200, 2);
	return 0;
	//cout<<copoVonkoch(200, 2)<<endl;
}

//Función para crear  copo de Von Koch
void copoVonkoch(double l, double n){
	//generando primero los lados de un primer triangulo
	double pi=3.141593654, xvertice1, yvertice1, xvertice2, yvertice2;
    double xvertice3, yvertice3;
    
	xvertice1=0;
    yvertice1=0;
     
    xvertice2=l*cos(2*pi/3);
    yvertice2=l*sin(2*pi/3);
     
    xvertice3=l*cos(pi/3);
    yvertice3=l*sin(pi/3);
    
    //llamando la curva de von koch para aplicarla sobre cada lado de los triangulos
    kochCurva(xvertice1, yvertice1, xvertice2, yvertice2, n);
    kochCurva(xvertice2, yvertice2, xvertice3, yvertice3, n);
    kochCurva(xvertice3, yvertice3, xvertice1, yvertice1, n);
    
	
	return;
}

//función curva de Van koch
void kochCurva(double xi, double yi, double xf, double yf, double n){
	double pi=3.141593654, x1, y1, x2, y2, x3, y3;
	
	if (n==0){
		xi=0;
		xf=4;
		yi=0;
		yf=4;
	}
	
	else if (n>0){
		//Dubujo de los 3 segmentos 
		x1=xi+((xf-xi)/3.0);
		y1=yi+((yf-yi)/3.0);
		
		x3=xf-((xf-xi)/3.0);
        y3=yf-((yf-yi)/3.0);
                 
        x2=((x1+x3)*cos(pi/3))-((y3-y1)*sin(pi/3));
        y2=((y1+y3)*cos(pi/3))+((x3-x1)*sin(pi/3));
         
        //llamado de la funcion dentro de la misma función, 
        //pasando los valores acabados de  crear sucesivamente 
        //eso es aplicar recurcion  
        kochCurva(xi,yi,x1,y1,n-1);
        kochCurva(x1,y1,x2,y2,n-1);
        kochCurva(x2,y2,x3,y3,n-1);
        kochCurva(x3,y3,xf,yf,n-1);
	}
	
	return;
	}
		

		 







