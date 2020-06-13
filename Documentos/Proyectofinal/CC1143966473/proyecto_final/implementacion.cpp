#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include <fstream> 
#include <string>
#include "funciononda.h"
using namespace std;
#define pi 3.141592653589793


FuncionOnda::FuncionOnda(double an_p,double al_p, double x_int, double des_es,double num_onda,double x_max, double tam_x, double tmax_prop,double pa_temp, int s_np, int inter_x, int inter_t, int inter_nx2) //constructor
  
{
   a=an_p;       //ancho de barrera de potencial
   V0=al_p;      //altura de barrera de potencial
   x0=x_int;      //posicion inicial para el paquete de ondas
   sig=des_es;     //ancho de paquete
   k0=num_onda;      //numero de onda promedio
   xmax=x_max;    //maximo x
   hx=tam_x;      //tamaño de paso espacial
   tmax=tmax_prop;    //tiempo maximo de propagacion
   ht=pa_temp;      //paso temporal
   nout=s_np;       //salida cada nout pasos
   nx=inter_x;         //numero de intervalos en x
   nt=inter_t;      // numero intervalo en t
   nx2=inter_nx2;

}

double FuncionOnda::Potencial(double x, double a, double V0) //funcion potencial cuadrado
{
  if(fabs(x)<=0.5e0*a)
    {
      return V0;
    }
  else
    {
      return 0e0;
    }
}

void FuncionOnda::Paqueteinicial(double Psi[], double Chi[],double x[], int nx, double x0, double sig, double k0) //paquete de ondas inicial
{
  double c1;
  double c2;
  double dx;
  double f;
  
  c1=1e0/sqrt(sqrt(2e0*pi)*sig); //constante uno
  c2=-1e0/(4e0*sig*sig); //constante dos
  
  for(int i=1; i<=nx; i++)
    {
       dx = x[i] - x0;
       f = c1*exp(c2*dx*dx);
       if(f<1e-10)
	 {
	   f=0e0;
	 }
       Psi[i]=f*cos(k0*x[i]);
       Chi[i]=f*sin(k0*x[i]);
    }
}

void FuncionOnda::Densidadprob(double Psi[], double Chi[], double Psi2[], int nx, double hx, double &PsiNorm)
{
  for(int i=1; i<=nx; i++)
    {
      Psi2[i]=Psi[i]*Psi[i]+Chi[i]*Chi[i];  //densidad de probabilidad no normalizada
      
      if(Psi2[i]<1e-10)
	{
	  Psi2[i] = 0e0;
	}
    }
  PsiNorm=0.5e0*(Psi2[1]+Psi2[nx]);// integral por regla trapezoidal
  
  for(int i=2; i<=(nx-1); i++)
    {
      PsiNorm += Psi2[i];
    }

  PsiNorm *= hx;

  for(int i=1; i<=nx; i++)
    {
      Psi2[i] /= PsiNorm; //densidad de probabilidad normalizada
    }
}

double* FuncionOnda::Init_arrreglo(int ind_min, int ind_max) // Inicializamos el arreglo
{
   double *arr; //puntero para arreglo
   arr=(double*) malloc((ind_max-ind_min+1)*sizeof(double)); // se llena una espacio de memorio acon el primer bit vacio
   return arr-ind_min;      // se ajusta el arreglo                                 
}

void FuncionOnda::SolGaussSeidel(double Psi[], double Chi[], double V[], int nx, double hx,double ht)

{
   const double eps = 1e-6;    // tolerancia de error                         
   const int itmax = 100;      // el numero maximo de iteraciones                          
   static double *Psi0, *Chi0, *W; // Apuntadores para la aproximacion de primer orden
   double err, erri, lam, Psii, Chii; // Variables para calcular la parte real e imaginaria solo en esta funcion
   static int init = 1;
   int i, it;

   if (init=1) // Se inicializan los arreglos 
   {
      Psi0 = Init_arrreglo(1,nx); 
      Chi0 = Init_arrreglo(1,nx);
      W = Init_arrreglo(1,nx); 
      init = 0;
   }

   lam = ht/(4*hx*hx); // se encuantra el valor de lamda

   for (i=2; i<=nx-1; i++) {             // aproximacion explicita de orden cero
      W[i] = 0.5*ht*V[i] + 2*lam;
      Psi0[i] = Psi[i] - lam*(Chi[i-1] + Chi[i+1]) + W[i]*Chi[i];
      Chi0[i] = Chi[i] + lam*(Psi[i-1] + Psi[i+1]) - W[i]*Psi[i];
   }

   for (it=1; it<=itmax; it++) {               //Iteraciones de  Gauss-Seidel 
      err = 0e0;
      for (i=2; i<=nx-1; i++) {
         Psii = Psi0[i] - lam*(Chi[i-1] + Chi[i+1]) + W[i]*Chi[i];
         Chii = Chi0[i] + lam*(Psi[i-1] + Psi[i+1]) - W[i]*Psii; // local error estimate based on probability density
         erri = fabs((Psii*Psii+Chii*Chii) - (Psi[i]*Psi[i]+Chi[i]*Chi[i]));
         if (erri > err) 
         {
             err = erri; // maximo error
         }                
         Psi[i] = Psii;
         Chi[i] = Chii;
      }
      if (err <= eps) // para cuando tiene el minimo de error
        {
          break;
        }                              
   }

   if (it > itmax) 
   {
      cout<<"Excede el numero de iteraciones\n"<<endl;
   }
}

FuncionOnda::~FuncionOnda()
{}
