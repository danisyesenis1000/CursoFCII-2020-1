/*Para resolver este programa me guié por el ejemplo 4.9 
(pero resuelto por mi),  donde se sugiere una estructura de 
selección if anidada principal, donde se genera las condiciones 
particulares: a=0 y b=0, a=0, c=0, y para la ultima condición 
else se genera un anidamiento dentro de  este donde las condiciones 
depende del discriminante, y es allí donde se hace notar el caso 
de las raíces complejas, se resuelve por separado la parte real 
y imaginaria, para ser mostrado el resultado final como comentario.*/
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
  double a, b, c, d, e, f, g, h;
  cout<<"Este prograba resuelve la ecuacion cuadratica cuya forma es: a(x^2)+bx+c=0. "<<endl;
  cout<<"Por favor ingrese los valores a, b, c."<<endl;
  cout<<"para encontrar los factores x que resuelven esta ecuacion."<<endl;
  cin>> a>> b>> c;
  
  if(a==0.0 && b==0.0)
    cout<<"La ecuacuin es degenerada y no tiene raices"<<endl;
  else if (a==0.0)
    cout<<"La ecuacion tiene solo una raiz y es: "<<-c/b<<endl;
  else if (c==0.0)
    cout<<"x1=0 y x2="<<-b/a<<endl;  
  else
    {
      if (pow(b,2.0) > 4.0*a*c) 
	{
	  cout<<"x1="<< (-b+sqrt(pow(b,2.0)-(4.0*a*c)))/(2.0*a) <<endl;
          cout<<"x2="<< (-b-sqrt(pow(b,2)-(4.0*a*c)))/(2.0*a) <<endl;
	}
      else if (pow(b,2.0) < 4.0*a*c){
		  cout<<"las raices son imaginarias "<<endl;
		  d=pow(b,2.0)-(4.0*a*c);
		  e=-d;
          f=sqrt(e);
	      g=f/(2*a);
	      h=-b/(2*a);
          cout<<"x1="<<h<<"+i"<<g<<endl;
	      cout<<"x2="<<h<<"-i"<<g<<endl;
	  }
	  else {
		  cout<<"ambas raices son las mismas"<<-b/(2*a)<<endl; 
	  }
  }
  return 0;
}
  
			     
						 
     
