#include <iostream>
#include <iomanip>

using namespace std;

inline float perimetro(float a,float l)
{return 2.0*(a+l);}

inline float volumen(float a,float l,float p)
{return a*l*p;}

inline float a_sub(float a,float l,float p)
{return 2*(a+l)*p + a*l;}


//PRINCIPAL
int main()
{
  float peri,vol,sub;   //declaracion de las variables a usar
  float largo[8],ancho[8],profundidad[8];


  //imprimo el encabezado
  cout << setw(10) << "Largo"<< setw(10) << "Ancho   " << setw(10) << "Profundidad   " << setw(10) << "Perimetro    " << setw(10) << "Volumen   " << setw(10) << "Area de superficie subterranea" << setw(10) << endl;
  
  cout << setw(10) << "****"<< setw(10) << "****   " << setw(10) << "*********     " << setw(10) << "********    " << setw(10) << "******      " << setw(10) << "*****************              " << setw(10) << endl;					       
																							
  //lleno los arreglos
  for(int i1=0;i1<8;++i1)
    {
      profundidad[i1]= 5.0 + (0.5)*(i1%4);
      if(i1<4)
	{
	  ancho[i1]=10.0;
	  largo[i1]=25.0;
	}
      else
	{
	  ancho[i1]=12.0;
	  largo[i1]=30.0;
	}
      peri=perimetro(ancho[i1],largo[i1]);                  //calculo el perimetro
      vol=volumen(ancho[i1],largo[i1],profundidad[i1]);     //calculo el volumen
      sub=a_sub(ancho[i1],largo[i1],profundidad[i1]);       //calculo el area de superficie subterranea

      cout << setw(9) << largo[i1] << setw(7) << ancho[i1] << setw(9) << profundidad[i1] << setw(14) << peri << setw(12) << vol << setw(10) << sub << setw(10) << endl;
    }
  return 0;
}
