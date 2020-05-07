#include <iostream>
//#ifndef "metodo_de_diferencias_finitas.h"
#include "metodo_de_diferencias_finitas.h"
#include <math.h>

using namespace std;


double p(double *x)
{
  double gamma= 1, alpha= 1,betta= 1;
  
  double a= gamma - (alpha + betta + 1)*x[0];
  double b = x[0]*(x[0]-1);
  return a/b;
}
double q(double *x)
{
  double alpha= 1, betta = 1;
  return alpha*betta / (x[0]*(x[0]-1));
}
double r(double *x)
{return 0;}
  
int main()
{
  functype *fa = (functype *) malloc((size_t) sizeof(functype) * 3);
  fa[0]=p;
  fa[1]=q;
  fa[2]=r;
  metodo a(50,2,20,-1,-0.05,fa);
  a.paso();

  a.~metodo();
}
