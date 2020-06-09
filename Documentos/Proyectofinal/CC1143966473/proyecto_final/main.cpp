#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include <fstream> 
#include <string>
#include "funciononda.h"
using namespace std;
#define pi 3.141592653589793
int main()
{
    double *Psi, *Chi;
    double *Psi2, *V, *x;
    double  PsiNorm, t;
    int it;
    double a=10e0; //ancho de barrera de potencial
    double V0=30e0; //altura de barrera de potencial
    double x0=-20e0; //posicion inicial para el paquete de ondas
    double sig=1e0; //ancho de paquete
    double k0=10e0; //numero de onda promedio
    double xmax=100e0; //maximo x
    double hx=1e-1; //tamaño de paso espacial
    double tmax=5e0; //tiempo maximo de propagacion
    double ht=5e-3; //paso temporal
    int nout=40; //salida cada nout pasos
    int nx=2*(int)(xmax/hx+0.5)+1; //número impar de intervalos espaciales
    int nt=(tmax/ht +0.5); //número  de intervalos temporales
    int nx2=nx/2; //numero de pasos de tiempo

    FuncionOnda p;
    Psi  = p.Init_arrreglo(1,nx); //funcion de onda
    Chi  = p.Init_arrreglo(1,nx);
    Psi2 = p.Init_arrreglo(1,nx); //densidad de probabilidad
    V = p.Init_arrreglo(1,nx); //potencial
    x = p.Init_arrreglo(1,nx); //variable espacial 


    for(int i=1; i<=nx; i++) //valores del potencial y de la variable espacial
    {    
       x[i] = (i-nx2-1)*hx;
       V[i] = p.Potencial(x[i],a,V0);
    }

    p.Paqueteinicial(Psi,Chi,x,nx,x0,sig,k0); // se prepara el paquete inicial

    ofstream archivoClientesSalida("archivos_Gauss_seidel/solucion.txt"); 
    if (!archivoClientesSalida ) {cout << "No se pudo abrir el archivo" << endl;exit( 1 );}
    archivoClientesSalida << "x[i]" <<'|' << "V[i]" << '|' << "Psi[i]"<<'|'<<"Chi[i]"<<'|'<<"Psi2[i]"<< endl;
    for (it=1; it<=nt; it++) 
    {                                    
      t = it*ht;
      p.SolGaussSeidel(Psi,Chi,V,nx,hx,ht);    // se soluciona el sistema de ecuaciones
      p.Densidadprob(Psi,Chi,Psi2,nx,hx,PsiNorm);  // se calcula la desnsidad de probabilidad              

      if (it % nout == 0 || it == nt) 
      {
         for (int i=1; i<=nx; i++) // se escribe el archivo de los resultados
         {
             archivoClientesSalida << x[i] <<'|' << V[i] << '|' << Psi[i]<<'|'<<Chi[i]<<'|'<<Psi2[i]<< endl;
         }
       }
    }
    //cout<<"hola"<<endl;
    return 0;
}