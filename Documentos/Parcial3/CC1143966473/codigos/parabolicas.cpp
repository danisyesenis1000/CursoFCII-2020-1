//importamos librerias necesarias
#include <iostream> 
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <complex>

#include "parabolicas.h"
using namespace std;


Parabolica::Parabolica(double alpa,double longitud, double numero_div, double T,double paso_t) //constructor
  
{
  alpha=alpa;
  xfin=longitud;
  m=numero_div;
  tfin=T;
  pasok=paso_t;
  
}

double* Parabolica::Vector(int imin, int imax)
{
   double *p;
                                       // asignar inicio de bloque al puntero de matriz
   p = (double*) malloc((size_t) ((imax-imin+1)*sizeof(double)));
   
   if (!p)
     {
       printf("Vector: error de asignación!\n");
       exit(1);
     }
   
   return p-imin;                                      // ajustar
}

void Parabolica::TriDiagSys(double a[], double b[], double c[], double d[], int n)
{
   int i;

   if(b[1] == 0e0)
     {
       printf("TriDiagSys: matriz singular !\n");
       return;
     }
   
   for(i=2; i<=n; i++)
     {                                    // factorizacion
      a[i] /= b[i-1];
      b[i] -= a[i]*c[i-1];
      
      if(b[i] == 0e0)
	{
	  printf("TriDiagSys: matriz singular !\n");
	  return;
	}
      
      d[i] -= a[i]*d[i-1];
     }

   d[n] /= b[n];                                     // sustitucion hacia atras
   
   for(i=(n-1); i>=1; i--)
     {
       d[i] = (d[i] - c[i]*d[i+1])/b[i];
     }
}


void Parabolica::metcrankni(double u0[], double u[], int m, double alpha, double pasoh, double pasok)
{
   static double *a, *b, *c;
   double lambda, lambda1, lambda2;
   static int init = 1;                              // inicializacion
   int i;

   if (init)
      {
	a = Vector(1,m);
	b = Vector(1,m);
	c = Vector(1,m);
	init = 0;
      }

   lambda = (0.5e0)*(alpha)*pasok/(pasoh*pasoh); 
   lambda1 = 1e0 + 2e0*lambda;
   lambda2 = 1e0 - 2e0*lambda;

   b[1] = 1e0;
   c[1] = 0e0;        // construir coeficientes para sistema
   u[1] = u0[1];
   
   for (i=2; i<=(m-1); i++)
     {
      a[i] = -lambda;
      b[i] = lambda1;
      c[i] = -lambda;
      u[i] = lambda*u0[i-1] + lambda2*u0[i] + lambda*u0[i+1];
     }
   
   a[m] = 0e0;
   b[m] = 1e0;
   u[m] = u0[m];

   TriDiagSys(a,b,c,u,m);           // Resuelve sistema tridiagonal
}

//===========================================================================

void Parabolica::metdifreg(double u0[], double u[], int m, double alpha, double pasoh,double pasok)
{
   static double *a, *b, *c;
   double lambda, lambda1;
   static int init = 1;                              // inicializacion
   int i;

   if (init)
      {
	a = Vector(1,m);
	b = Vector(1,m);
	c = Vector(1,m);
	init = 0;
      }

   lambda = (alpha*pasok)/(pasoh*pasoh);
   lambda1 = 1e0 + 2e0*lambda;

   b[1] = 1e0;
   c[1] = 0e0;        // construir coeficientes para sistema
   u[1] = u0[1];
   
   for (i=2; i<=m-1; i++)
     {
       a[i] = -lambda;
       b[i] = lambda1;
       c[i] = -lambda;
       u[i] = u0[i];
     }
   
   a[m] = 0e0;
   b[m] = 1e0;
   u[m] = u0[m];

   TriDiagSys(a,b,c,u,m);            // Resuelve sistema tridiagonal
}

//===========================================================================

void Parabolica::metdifpro(double u0[], double u[], int m, double alpha, double pasoh,double pasok)
{
   double lambda, lambda1;
   int i;

   lambda = (alpha*pasok)/(pasoh*pasoh); //elementos diagonales secundarias
   lambda1 = 1e0 - 2e0*lambda; //elementos de la diagonal principal

   u[1] = u0[1];
   u[m] = u0[m];
   
   for (i=2; i<=(m-1); i++)
     {
       u[i] = lambda*u0[i-1] + lambda1*u0[i] + lambda*u0[i+1]; //solucion metodo de diferencias progresivas
     }     
}

Parabolica::~Parabolica() // destructor de la clase Parabolica
{
}
