#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

float Perimetro(float l, float h)
{  
    float P = 2*(l+h);
    return P;
}

float Volumen(float l, float h,float pp)
{  
    float V = l*h+pp;
    return V;
}

float ASupSub(float l, float h, float pp)
{  
    float ASS = 2*(l+h)*pp + l*h ;
    return ASS;
}




int main(){


	float Largo [8] = { 25,25,25,25,30,30,30,30};
	float Ancho [8] = { 10,10,10,10,12,12,12,12};
	float Profun [8] = {5.0,5.5,6.0,6.5,5.0,5.5,6.0,6.5};
	
	cout << "Largo" << "   " << "Ancho" << "   " << "Profundidad"<< "   " << "Perimetro" << "   " << "Volumen" <<"   "<< "Areasupsub" << endl;
	int i;
	for(i=0; i<=7; i=i+1){

			cout << Largo [i]<< "       " << Ancho [i]<< "         " << Profun [i]<< "          " <<Perimetro(Largo [i],Ancho [i])<<"       " <<Volumen(Largo [i],Ancho [i], Profun[i])<<"        " <<ASupSub(Largo [i],Ancho [i], Profun[i]) <<endl;
	}

return 0;

}


