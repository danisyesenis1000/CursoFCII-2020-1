#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int intento;
  int aleatorio;
  char continuar= 's';
  
  while (continuar=='s')
    {
      aleatorio = 1+rand()%1000;
      cout<<"Adivine el número aleatorio del 1 al 1000 que hemos generado:"<<endl;
      cin>> intento;

      if  (intento==aleatorio)
	cout<<"Felicitaciones, ha acertado";
  
      else
	{
	  while(intento!=aleatorio)
	    {
	      if (intento>aleatorio)
		{
		  cout<<"Su elección es mayor al número correcto, intentelo nuevamente"<<endl;
		  cin>> intento;
		}
	      else
		{
		  cout<<"Su elección es menor al número correcto, intentelo nuevamente"<<endl;
		  cin>> intento;
		}
	    }
	  cout<<"Finalmente acertó";
	}
      
      cout<<"\n Si desea volver a jugar, escriba la letra s, en caso contrario presione otra letra \t";
      cin>> continuar;
    }
  return 0;
}
