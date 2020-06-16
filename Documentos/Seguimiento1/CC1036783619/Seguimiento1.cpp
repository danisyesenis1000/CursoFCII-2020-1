#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{

	double l,  w,  d, perimetro, volumen, area; 
	l=25.0;
	d=5.0;
	w=10.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;

	cout << "       largo     ancho  profundidad perimetro volumen    area\n"; 
	cout <<"        ________________________________________________________\n";

	
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;
	     
		
	l=25.0;	
	d=5.5;
	w=10.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=25.0;	
	d=6.0;
	w=10.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=25.0;	
	d=6.5;
	w=10.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=30.0;	
	d=5.0;
	w=12.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=30.0;	
	d=5.5;
	w=12.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=30.0;	
	d=6.0;
	w=12.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;

	l=30.0;	
	d=6.5;
	w=12.0;
	perimetro= 2*(l+w);
	volumen=l*d*w;
	area=2*(l+w)*d + l*w;
	cout << setw(10) << l
	     << setw(10) << w
	     << setw(10) << d
	     << setw(10) << perimetro
	     << setw(10) << volumen
	     << setw(10) << area << endl;




 return 0;
}
