#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()          // Función principal.
{
  int adivinar;     // Esta variable va a ser el número que entre el usuario para adivinar el número.
  int a = 0;            // El contador que va a seguir hasta que el usuario adivine.
  int b;           // Esta variable va a servir para que el usuario siga o no jugando.
  srand(time(NULL));  // Semilla del número aleatorio.

  cout << "Hola, este es un juego para que adivines un número." << endl;

  int numero = 1+rand()%(1001-1);  // Numero aleatorio entre 1 y 1000.

  cout << "Estoy pensando en un número entre 1 y 1000" << endl;

  while ( a < 100 )   // Número de intentos.
    {
      cout << "Adivina el número: ";
      cin >> adivinar;     // El usuario tiene que entrar los números para adivinar.
      a++;

      if (adivinar < numero)                     // Condiciones para comprobar si el numero es mayor, menor o igual.
	cout << "Su elección es menor que el número" << endl;
      else if (adivinar > numero)
	cout << "Su elección es mayor que el número" << endl;
      else if (adivinar == numero )
	{
	cout << "Muy bien!! Adivinaste" << endl;
	cout << "¿Quieres seguir adivinando? 1 para Sí, 2 para No";   // Le da la desición al usuario de si quiere continuar adivinando.
	cin >> b;
	if (b == 1)
	  continue;
	else
	  break;
	}
    }
  return 0;
}
