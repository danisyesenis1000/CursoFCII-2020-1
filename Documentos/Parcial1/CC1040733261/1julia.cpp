#include <iostream>
using namespace std;

int main(){
	
	double a=1920,h=1080, zoom=1; //Establecer ancho, altura amplitud
	double cx=-0.8, cy=0; //establece los punt cx de la parte real y cy7 de la parte imaginaria de para la funcion de Julia c=cx + icy de f=z²+c 
    double movex=0, movey=0;//inicializa el desplazamiento en el punto 0,0 	
    double maxiter=255, i;  // cantidad de iterzaciones
    double x, y, zx=0, zy=0, tmp; //fra; 
    cout<<"los puntos y distancia al cuadrado que determina los conjuntos de julia para c=("<<cx<<","<<cy<<")"<<endl;
    for (x=0; x<a; x++){//inicia el primer ciclo que desplaza orizontalmente
		for (y=0; y<h; y++){
			zx = 1.5*(x - a/2)/(0.5*zoom*a) + movex;
			zy = 1.0*(y - h/2)/(0.5*zoom*h) + movey;
			i=maxiter;
			while ((zx*zx)+(zy*zy)<=4 && i>1){
				tmp = zx*zx - zy*zy + cx;
				zy=2.0*zx*zy + cy;
				zx=tmp;
				//fra=(zx*+zx)+(zy*zy);
				i--;
				cout<<"El punto ("<<zx<<","<<zy<<")"<<" tiene la distancia al cuadrado "<<i<<endl; 
			}
		}	
	}	
		
 
	return 0;
}
