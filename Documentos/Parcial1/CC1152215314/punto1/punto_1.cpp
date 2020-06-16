#include "punto_1.h"

Adivinar::Adivinar(){intento=0;correcto=0;}  //Constructor

void Adivinar::Jugar()
{
  AsignarCorrecto();              //llama para darle un valor aleatorio a correcto
  int centinela=1;                //variable local que me va decir si sigo jugando o no
  cout << "Inicio el juego, intoduzca algun valor:" << endl;
  while(centinela!=0)
    {
      ValorUsuario();             //le pide al usuario un valor
      if(intento==correcto)
	{
	 cout << "adivino!" << endl;
	 cout << "quiere seguir jugando? escriba 0 para terminar o cualquier numero para seguir" << endl;
	 cin >> centinela;
	 AsignarCorrecto();      //le asigno un nuevo valor a correcto por si quiere seguir jugando
	 continue;
	}
      MostrarMensaje();          //muestra si el correcto es menor o mayor
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
