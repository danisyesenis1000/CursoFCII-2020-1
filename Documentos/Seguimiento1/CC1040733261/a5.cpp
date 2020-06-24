/*Para resolver este programa decidí hacerlo con una estructura 
de selección if anidada principal, donde se genera las condiciones 
del año del modelo, y internamente a cada una de estas condiciones 
se hace una estructura if anidada para las condiciones de peso.
Para inicializarlo se le informa al usuario de que trata el programa, 
se le solicita ingresar el año del modelo del automóvil y el peso de 
este en lbs.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, p;
	cout<<"Con base en el año del modelo y el peso de un automóvil"<<endl;
	cout<<"este programa despliega la clase de peso y la tarifa de registro."<<endl;
	cout<<"Por favor ingrese el año del modelo"<<endl;
	cin>>a;
	cout<<"Por favor ingrese el peso en lbs"<<endl;
	cin>>p;
	
	if (a<=1970){
		if (p<2700){
			cout<<"La clase de peso es 1 y la tarifa es 16.50"<<endl;
		}
		else if (p>=2700 && p<=3800){
			cout<<"La clase de peso es 2 y la tarifa es 25.50"<<endl;
		}
		else if (p>3800){
			cout<<"la clase de peso es 3 y la tarifa es 46.50"<<endl;
		}
	}
	else if (a>=1971 && a<=1979){
		if (p<2700){
			cout<<"La clase de peso es 4 y la tarifa es 27.00"<<endl;
		}
		else if (p>=2700 && p<=3800){
			cout<<"La clase de peso es 5 y la tarifa es 30.50"<<endl;
		}
		else if (p>3800){	
			cout<<"La clase de peso es 6 y la tarifa es 52.50"<<endl;
		}	
	}
	else if (a>=1980){
		if (p<3500){
			cout<<"La clase de peso es 7 y la tarifa es 19.50"<<endl;
		}
		else if (p>=3500){
			cout<<"La clase de peso es 8 y la tarifa es 52.50"<<endl;
		}		
    }
	return 0;
}

