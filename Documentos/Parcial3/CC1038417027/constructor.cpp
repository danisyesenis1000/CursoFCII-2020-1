#include <iostream>
//#ifndef "metodo_de_diferencias_finitas.h"
#include "metodo_de_diferencias_finitas.h"
#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void imprimir(const vector<double> &,const vector<double> &);

metodo::metodo(int n, double a, double b, double al, double be,functype *f)
{
  N = n;
  inicioX=a;
  finalX=b;
  inicioY=al;
  finalY=be;
  h = (finalX - inicioX)/(N+1);
  func = (functype*) malloc((size_t) sizeof(functype) * 3);
  func[0]=f[0];
  func[1]=f[1];
  func[2]=f[2];
  
}


void metodo::paso()
{
  vector <double> x(N+2);
  vector <double> u(N+1);
  vector <double> z(N+1);
  vector <double> w(N+2);
  ofstream archivo_sal;
  archivo_sal.open("valores.txt");

  if (archivo_sal.fail())
    {
      cout<<"Es imposible abrir el archivo"<<endl;
      exit(1);
    }
  
  x[0]=inicioX;
  for (int i=1;i<=N;i++)
    {
      if (i==1)
	{
	  u[0]=0.0;
	  z[0]=0.0;
	  u[N]=0.0;
	  double l1,a1,b1,d1;
	  x[i]= inicioX + h;
	  a1= 2 + pow(h,2)*func[1](&x[i]);
	  b1= -1 + (h/2)* func[0](&x[i]);
	  d1= -pow(h,2)*func[2](&x[i]) + (1 + (h/2)*func[0](&x[i]))*inicioY;
	  l1=a1;
	  u[i]=b1/a1;
	  z[i]=d1/l1;
	}
      else if(i==N)
	{
	  double ln,an,cn,dn;
	  x[i]= finalX - h ;
	  an= 2 + pow(h,2)*func[1](&x[i]);
	  cn= -1 -(h/2)*func[0](&x[i]);
	  dn= -pow(h,2)*func[2](&x[i]) + (1 + (h/2)*func[0](&x[i]))*finalY;
	  ln=an - cn*u[i-1];
	  z[i]=(dn - cn*z[i-1])/ln;
	}
      else
	{
	  double li,ai,bi,ci,di;
	  x[i]= inicioX + i*h;
	  ai= 2 + pow(h,2)*func[1](&x[i]);
	  bi= -1 + (h/2)*func[0](&x[i]);
	  ci= -1 - (h/2)*func[0](&x[i]);
	  di= -pow(h,2)*func[2](&x[i]);
	  li=ai -ci*u[i-1];
	  u[i]=bi/li;
	  z[i]=(di - ci*z[i-1])/li;
	}
    }
  w[0]=inicioY;
  w[N+1]=finalY;
  w[N]=z[N];
  double b=N-1;
  for(int i=1;i<N;i++)
    { 
      w[b]=z[b] - u[b]*w[b+1];
      archivo_sal<<x[b]<<" "<<w[b]<<endl;
      b=b-1;
    }
  archivo_sal.close();
}
void imprimir(const vector<double> &arreglo1, const vector<double> &arreglo2)
{
  
  size_t i;
  for (i=0;i<arreglo1.size();i++)
    {
      cout<<setw(12)<<arreglo1[i]<<setw(12)<<arreglo2[i]<<endl;
    }
}

metodo::~metodo(){
    free(func);
}
