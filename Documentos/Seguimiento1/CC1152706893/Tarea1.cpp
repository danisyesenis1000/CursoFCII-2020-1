#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	cout << "Largo " << "  Ancho  " << " Profundidad " << " Perimetro " << " Volumen " << " Area SS " << endl;
	for (float pr=5.0; pr<7.0; pr=pr+0.5){
		float l, an, p, v, a;
		l=25.0;
		an=10.0;
		p=2.0*(l+an);
		v=l*an*pr;
		a=2.0*(l+an)*pr+(l*an);
		
		cout << " " << fixed << setprecision(1) << l << "   " << an << "       " << pr << "         " << p << "     " << v << "   " << a << "   " << endl;
		
		}
		
		for (float pr=5.0; pr<7.0; pr=pr+0.5){
		float l, an, p, v, a;
		l=30.0;
		an=12.0;
		p=2.0*(l+an);
		v=l*an*pr;
		a=2.0*(l+an)*pr+(l*an);	
		
		cout << " " << fixed << setprecision(1) << l << "   " << an << "       " << pr << "         " << p << "     " << v << "   " << a << "   " << endl;
		}
		
		return 0;
	}
