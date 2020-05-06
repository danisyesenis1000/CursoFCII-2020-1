#include <iostream>
#include "clase1.h"
#include <iomanip>
//#include "clase2.h"

using namespace std;

void mostrarDatos1(double [],double [],int);
void mostrarDatos2(double [],double [],double [],int);


int main()
{
  
  cout<<"Registro de los puntos en XY"<<endl;
  int n=10;
  
  Circular info(1.0,0.1,2.0,2,3,1,n);
  double xdatos[n],ydatos[n];
  info.resultado(xdatos,ydatos);
  mostrarDatos1(xdatos,ydatos,n);
  


  //presenta una fallo de redefinicion al ingresar la otra herencia.
  /*
  double zdatos[n];
  Expiral info2(1.0,0.1,2.0,2,3,1,n,2.0,1.0);
  info.resultado(xdatos,ydatos);
  info2.resultado2(zdatos);
  mostrarDatos2(xdatos,ydatos,zdatos,n);
  */
  //no funciono proponiendo esta forma
  //datos.resultado(xdatos,&datos.xpos);
  //puntero=&datos.xpos;  
  
}
void mostrarDatos1(double arr1[],double arr2[],int numero)
{
  cout<<"X"<<setw(15)<<"Y"<<endl;
  for(int i=0;i<numero;i++)
    {
      cout<<arr1[i]<<setw(15)<<arr2[i]<<endl;
    }
}
void mostrarDatos2(double arr1[],double arr2[],double arr3[],int numero)
{
  cout<<"X"<<setw(15)<<"Y"<<setw(15)<<"Z"<<endl;
  for(int i=0;i<numero;i++)
    {
      cout<<arr1[i]<<setw(15)<<arr2[i]<<setw(15)<<arr3[i]<<endl;
    }
}
