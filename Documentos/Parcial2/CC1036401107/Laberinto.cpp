#include <iostream>
#include <cstdlib>

using namespace std;

#define N 12
enum Direccion {derecha, izquierda, arriba, abajo};

// Posiciones iniciales.
const int xi = 2;
const int yi = 0;

//Funciones prototipo.

void RecorrerLaberinto(char Laberinto[][N], int x_mov, int y_mov, int mov);
bool Coordenadas(char Laberinto[][N], int f, int c);
bool Cuadricula(int x, int y);
void Mostrar(char Laberinto[][N]);



int main()
{

  //Laberinto que hay que recorrer.  
  
  char Laberinto[N][N] = {{'#','#','#','#','#','#','#','#','#','#','#'\
,'#'},
                          {'#','o','o','o','#','o','o','o','o','o','o'\
,'#'},
                          {'o','o','#','o','#','o','#','#','#','#','o'\
,'#'},
                          {'#','#','#','o','#','o','o','o','o','#','o'\
,'#'},
                          {'#','o','o','o','o','#','#','#','o','#','o'\
,'o'},
                          {'#','#','#','#','o','#','o','#','o','#','o'\
,'#'},
                          {'#','o','o','#','o','#','o','#','o','#','o'\
,'#'},
                          {'#','#','o','#','o','#','o','#','o','#','o'\
,'#'},
                          {'#','o','o','o','o','o','o','o','o','#','o'\
,'#'},
                          {'#','#','#','#','#','#','o','#','#','#','o'\
,'#'},
                          {'#','o','o','o','o','o','o','#','o','o','o'\
,'#'},
                          {'#','#','#','#','#','#','#','#','#','#','#'\
\
                           ,'#'}};
  
  // Se llama la función que recorre el laberinto.
  
  RecorrerLaberinto(Laberinto, xi, yi, derecha);
  return 0;
}

/* 
Función que va a servir para definir si en el próximo movimiento
hay una parde o se puede caminar.
 */

bool Coordenadas(char Laberinto[N][N], int f, int c)
{
  return (f >= 0 && f < N && c >= 0 && c < N && Laberinto[f][c] == 'o');
    
}

/*
Función que define el tamaño de la cuadricula y si se 
esta moviendo dentro de ella.
 */

bool Cuadricula(int x, int y)
{
  if (( x == 0 || x == N-1) && ( y >= 0 && y <= N-1 ))
    return true;
  else if ((y == 0 || y == N-1) && (x >=0 && x <= N-1))
    return true;
  else
    return false;
}

// Esta función muestra el laberinto en pantalla.

void Mostrar(char Laberinto[N][N])
{
  for (int x = 0; x < N; x++)
    {
      for (int y = 0; y < N; y++)
	{
	cout << Laberinto[x][y] << ' ';
	}
      cout << '\n';
    }
  cout << "\nProximo movimiento\n" << endl;
  cin.get();
}

/*
Función con la que se va a poder mover a traves del laberinto.
 */

void RecorrerLaberinto(char Laberinto[N][N], int x_mov, int y_mov, int mov)
{
  static bool Pos = false;
  
  Laberinto[x_mov][y_mov] = 'x';   //  Pone x en cada movimiento.
  Mostrar(Laberinto);

  if (x_mov == xi && y_mov == yi && Pos)
    {
      cout << "Vuelva al inicio \n";   // Si no encuentra salida vuelva al inicio.
    return;
    }
  else if ( Cuadricula(x_mov, y_mov) && x_mov != xi && y_mov != yi)
    {
      cout << "Laberinto completado \n";   // Si llega al final.
    return;
    }
  else
    {
      int n, next;
      Pos = true;

      for( n = 0, next = mov; n < 4; n++, next++, next %= 4)  //Se definen los movimientos que puede tener.
	{
	  switch( next )
	    {
	    case derecha:
	      if (Coordenadas(Laberinto, x_mov+1, y_mov)){               //Si la derecha es 'o' entonces camine    
		  RecorrerLaberinto(Laberinto, x_mov+1, y_mov, derecha);
		  return;
	      }
	      break;

	    case izquierda:
	      if ( Coordenadas(Laberinto, x_mov-1, y_mov)){              //Si la izquierda es 'o' entonces camine
		RecorrerLaberinto(Laberinto, x_mov-1, y_mov, izquierda);
		return;
	      }
	      break;

	    case arriba:
	      if (Coordenadas(Laberinto, x_mov, y_mov+1)){           // Si arriba es 'o' entonces camine.
		RecorrerLaberinto(Laberinto, x_mov, y_mov+1, arriba);
		return;
	      }
	      break;

	    default:
	      if(Coordenadas(Laberinto, x_mov-1, y_mov)){           // Si abajo es 'o' entonces camine.
		RecorrerLaberinto(Laberinto, x_mov-1, y_mov, abajo);
		return;
	      }
	      break;
	    }
	}
    }
}
