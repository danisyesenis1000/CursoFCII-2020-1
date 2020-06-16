#include <iostream> //importamos librerias necesarias
#include <iomanip>
#include <complex>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "parabolicas.h"

using namespace std;

#define pi 3.141592653589793

double xfin; //valor final del intervalo
double xfin1;
double xfin2;

void Init(double u[], double x[], int m) //condicion inicial
{                              
   int i;
   
   for(i=1; i<=m; i++)
     {
       u[i]=sin(pi*x[i]/xfin);
     }
}


int main()
{
  //metodo de crank nkelson
   double *u0, *u, *x;
   double alpha, f, pasok, pasoh, t, tfin;
   int i, m;
   FILE *out;

   alpha=1e0;  // coeficiente de difusion
   xfin=1e0;  //punto final                                  
   m=11;    //numero de intervalos en x                           
   tfin=5;  //tiempo                                     
   pasok=0.0005; //paso en el tiempo 0.
   
   Parabolica p;

   u0=p.Vector(1,m);
   u=p.Vector(1,m); // solucion
   x=p.Vector(1,m); //espacial 

   pasoh=xfin/(m-1); //paso
   
   for(i=1; i<=m; i++)
     {
       x[i]=(i-1)*pasoh; // espacial
     }

   Init(u0,x,m);// solucion inicial

   t=0e0;
   
   while(t < tfin)
     {                                
      t += pasok; // incrementamos tiempo
      p.metcrankni(u0,u,m,alpha,pasoh,pasok);// propagacion de la solucion

      for(i=1; i<=m; i++)
	{
	  u0[i]=u[i];// actualizamos solucion
	}
     }

   out=fopen("Crank-Nicolson.txt","w");                     
   fprintf(out,"        x \t\t w \t    u(x,0.5) \t    error\n");
   f=exp(-pi*pi*alpha*t/(xfin*xfin)); //solucion real
   
   for(i=1; i<=m; i++)
     {
       fprintf(out,"%15.8f%15.8f%15.8f%15.8f\n",x[i],u[i],f*sin(pi*x[i]/xfin),u[i]-f*sin(pi*x[i]/xfin));
     }
   
   fclose(out);

  //===============================================================================

   //metodo de diferencias regresivas
   double *u01, *u1, *x1;
   double alpha1, f1, pasok1, pasoh1, t1, tfin1;
   int i1, m1;
   FILE *out1;

   alpha1=1e0;                                     
   xfin1=1e0;                                        
   m1=11;                               
   tfin1=5;                                      
   pasok1=0.0005;
   
   u01=p.Vector(1,m1);
   u1=p.Vector(1,m1);                           
   x1=p.Vector(1,m1);                                         

   pasoh1=xfin1/(m1-1);
   
   for(i1=1; i1<=m1; i1++)
     {
       x1[i1]=(i1-1)*pasoh1;                     
     }

   Init(u01,x1,m1);                                         

   t1=0e0;
   
   while(t1 < tfin1)
     {                                        
      t1 += pasok1; 
      
      p.metdifreg(u01,u1,m1,alpha1,pasoh1,pasok1);                      

      for(i1=1; i1<=m1; i1++)
	{
	  u01[i1]=u1[i1];                 
	}
     }

   out1=fopen("Diferencias_regresivas.txt","w");        
   fprintf(out1,"        x \t\t w \t    u(x,0.5) \t    error\n");
   f1=exp(-pi*pi*alpha1*t1/(xfin1*xfin1));
   
   for(i1=1; i1<=m1; i1++)
     {
       fprintf(out1,"%15.8f%15.8f%15.8f%15.8f\n",x1[i1],u1[i1],f1*sin(pi*x1[i1]/xfin1),u1[i1]-f1*sin(pi*x1[i1]/xfin1));
     }
   fclose(out1);

   //========================================================

   //metodo de diferencias progresivas 
   double *u02, *u2, *x2;
   double alpha2, f2, pasok2, pasoh2, t2, tfin2;
   int i2, m2;
   FILE *out2;

   alpha2=1e0;                                    
   xfin2=1e0;                                       
   m2=11;                                
   tfin2=5;                                          
   pasok2=0.0005;                                              
     
   u02=p.Vector(1,m2);
   u2=p.Vector(1,m2);                           
   x2=p.Vector(1,m2);                                          

   pasoh2=xfin2/(m2-1);
   
   for(i2=1; i2<=m2; i2++)
     {
       x2[i2]=(i2-1)*pasoh2;                     
     }

   Init(u02,x2,m2);                                        

   t2=0e0;
   while (t2 < tfin2)
     {                                        
      t2 += pasok2;                                               
      p.metdifpro(u02,u2,m2,alpha2,pasoh2,pasok2);                     

      for(i2=1; i2<=m2; i2++)
	{
	  u02[i2]=u2[i2];                  
	}
     }

   out2=fopen("Diferencias_progresivas.txt","w");                     
   fprintf(out2,"        x \t\t w \t    u(x,0.5) \t    error\n");
   f2=exp(-pi*pi*alpha2*t2/(xfin2*xfin2));
   for(i2=1; i2<=m2; i2++)
     {
       fprintf(out2,"%15.8f%15.8f%15.8f%15.8f\n",x2[i2],u2[i2],f2*sin(pi*x2[i2]/xfin2),u2[i2]-f2*sin(pi*x2[i2]/xfin2));
     }
   fclose(out2);

   return 0;

}
