#include <iostream>
#include <iomanip>
#include <cmath>
// P será ancho + largo
//A será ancho*largo

using namespace std;

float perimetro (float A, float P )
{
  return 2*P;
}

float volumen (float A, float prof )
{
  return A*prof;
}

float area_sup (float A, float P, float prof )
{
  return 2*P*prof + A;
}

int main()
{
  
  float largo[]={25,25,25,25,30,30,30,30}; 
  float ancho[]={10,10,10,10,12,12,12,12}; 
  float profundo[]={5, 5.5, 6, 6.5, 5, 5.5, 6, 6.5};
  float A[8]; float P[8];
  //largo = 25; 
  //ancho = 10; 
  //profundo = 5.0;

  //float A = largo[0]*ancho[0];
  //float P = largo[0]+ancho[0];
  
  cout<< "Largo | Ancho | Profundidad | Perímetro | Volumen | Area superficial"<<endl;
  cout<< "***** | ***** | ************|********** | ******* | ****************"<<endl;
  for(int i = 0; i<8; i++){
	A[i] = largo[i]*ancho[i];
	P[i] = largo[i]+ancho[i];
       
  cout<< setw(3) <<  largo[i]  << setw(7)<< ancho[i] << setw(11)<< profundo[i] <<setw(15)<< perimetro(A[i], P[i])<<setw(12)<< volumen(A[i], profundo[i])<<setw(12)<< area_sup(A[i],P[i], profundo[i]) <<setw(12) <<endl;
      }
  return 0;
}

