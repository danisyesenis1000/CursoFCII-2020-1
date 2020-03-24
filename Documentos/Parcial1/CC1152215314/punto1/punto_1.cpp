#include "punto_1.h"

Adivinar::Adivinar(){intento=0;correcto=0;}

void Adivinar::Jugar()
{
  AsignarCorrecto();
  int centinela=1;
  while(centinela!=0)
    {
      ValorUsuario();
      if(intento==correcto)
	{
	 cout << "adivino!" << endl;
	 cout << "quiere seguir jugando? escriba 0 para terminar o cualquier numero para seguir" << endl;
	 cin >> centinela;
	 continue;
	}
      MostrarMensaje();
    }
}

//====================================================================================================//

void Adivinar::AsignarCorrecto()
{
  srand(time(NULL));             //Semilla 
  correcto=1+(rand()%1000);      //valor aleatorio entre 0 y 1000
}

void Adivinar::ValorUsuario()
{
  cin >> intento;
}


void Adivinar::MostrarMensaje()
{
  if(intento<correcto)
    cout << "el valor correcto es mayor que su intento" <<endl;
    if(intento>correcto)
    cout << "el valor correcto es menor que su intento" <<endl;
}
