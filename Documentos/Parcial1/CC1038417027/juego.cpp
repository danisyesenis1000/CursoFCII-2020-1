#include <iostream>
#include <time.h>


using namespace std;


int juego()
{
  int n, num; //para el juego 
  int a; //para comprobar si el juego sigue
  srand(time(NULL));
  num =1 + rand()%(1-1000); //Crea un numero aleatorio
  //cout<<num<<endl; //Comprobacion del juego 
  cout<<"Ingrese un numero entre 1 y 1000"<<endl;
  cin>>n; //el usuario ingresa el numero
  //si el numero es diferente del numero del sistema entonces:
  //NOTA: Si es ingresa un numero diferente a un entero el programa entra en un bucle infinito
  
  while(n!=num)
    {
      if(n<num)
	{
	  cout<<"El número ingresado es menor"<<endl;
	}
      else if (n>num)
	{
	  cout<<"El número ingresado es mayor"<<endl;
	}
      cout<<"Ingrese otro número"<<endl;
      cin>>n;
    }
  int b=0;
  if (n==num)
    {
      
      cout<<"Felicidades has ganado"<<endl;
      cout<<"Si desea continuar el juego ingrese 1"<<endl;
      cout<<"Si desea finaliza el juego ingrese 0"<<endl;
      cin>>b;
    }
  return b;  
}
  





int main(){

  int a;
   
  a = juego();
  if(a==1)
    {
      a = juego();
	}
  
  return 0;
}

