#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 12
enum Direccion {derecha, izquierda, arriba, abajo}; //Le da valores a cada direccion en la que se pueda mover.
const int Max = 100;  // Numero maximo de 'o' para hacer el camino del laberinto.


// Funciones prototipo.

void RecorrerLaberinto(char Laberinto[][N], int x_mov, int y_mov, int mov, int fila, int columna);
void GenerarLaberinto(char Laberinto[][N], int *, int *);
bool Coordenadas(char Laberinto[][N], int f, int c);
bool Cuadricula(int x, int y);
void Mostrar(char Laberinto[][N]);

int main()
{

  char Laberinto[N][N];
  int xi, yi, x, y;
  srand(time(0));

  for (int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
	Laberinto[i][j] = '#';
    }

  GenerarLaberinto(Laberinto, &xi, &yi);

  x = xi;
  y = yi;

  RecorrerLaberinto(Laberinto, xi, yi, x, y, derecha);
  
  return 0; 

 }

/*
 Esta función va a ser útil para decirle al programa que si el 
próximo movimiento es 'o' entonces siga, sino, busque otro movimiento.
*/

bool Coordenadas(char Laberinto[N][N], int f, int c)
{
  return (f >= 0 && f < N && c >= 0 && c < N && Laberinto[f][c] == 'o');
}

/*
Esta función nos va a servir para definir si el proximo movimiento
que se haga si esta dentro del laberinto.
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

/*
Función que muestra en pantalla el laberinto.
 */

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

void GenerarLaberinto(char Laberinto[][N], int *pos_x, int *pos_y)
{
  int a, x, y, entrada, salida;

  do{
    entrada = rand() % 4;
    salida = rand() % 4;
  } while(entrada == salida);

  //Determinamos la posicion de entrada

  if(entrada == 0)
    {
      *pos_x = 1 + rand() % 10;
      *pos_y = 0;
      Laberinto[*pos_x][0] = 'o';
    }
  else if( entrada == 1)
    {
      *pos_x = 0;
      *pos_y = 1 + rand() % 10;
      Laberinto[0][*pos_y] = 'o';
    }
  else if (entrada == 2)
    {
      *pos_x = 1 + rand() % 10;
      *pos_y = N-1;
      Laberinto[*pos_x][N-1] = 'o';
    }
  else
    {
      *pos_x = N-1;
      *pos_y = 1 + rand() % 10;
      Laberinto[N-1][*pos_y] = 'o';
    }

  // Determinamos la posicion de salida.

  if(salida == 0)
    {
      a = 1 + rand() % 10;
      Laberinto[a][0] = 'o';
    }
  else if(salida == 1)
    {
      a = 1 + rand() % 10;
      Laberinto[0][a] = 'o';
    }
  else if(salida == 2)
    {
      a = 1 + rand() % 10;
      Laberinto[a][N-1] = 'o';
    }
  else
    {
      a = 1 + rand() % 10;
      Laberinto[N-1][a] = 'o';
    }

  // crea el camino dentro del laberinto
  
  for (int cuenta= 1; cuenta < Max; cuenta++)
    {
      x = 1 + rand() % 10;
      y = 1 + rand() % 10;
      Laberinto[x][y] = 'o';
    }
}

/*
Esta función es la que recorre el laberinto
 */

void RecorrerLaberinto(char Laberinto[N][N], int x_mov, int y_mov, int mov, int fila, int columna)
{
  static bool Pos = false;
  
  Laberinto[fila][columna] = 'x';  // Inicia el laberinto.
  Mostrar(Laberinto);

  if (x_mov == fila && y_mov == columna && Pos)
    {
      cout << "Vuelva al inicio \n";   // Lo devuelve al inicio si no encuentra salida.
    return;
    }
  else if ( Cuadricula(fila,columna) && fila != x_mov && y_mov != columna)
   {
     cout << "Laberinto completado \n";  // Si llega al final completa el laberinto.
     return;
   }
  else
    {
      int n, next;
      Pos = true;
      
      // Condiciones para que se mueva.

      for( n = 0, next = mov; n < 4; n++, next++, next %= 4)
	{
	  switch( next )
	    {
	    case derecha:
	      if (Coordenadas(Laberinto, fila+1, columna)){
		RecorrerLaberinto(Laberinto, x_mov, y_mov,fila+1,columna, derecha);
		  return;
	      }
	      break;

	    case izquierda:
	      if ( Coordenadas(Laberinto, fila-1, columna)){
		RecorrerLaberinto(Laberinto, x_mov, y_mov,fila-1,columna, izquierda);
		return;
	      }
	      break;

	    case arriba:
	      if (Coordenadas(Laberinto, fila, columna+1)){
		RecorrerLaberinto(Laberinto, x_mov, y_mov,fila,columna+1, arriba);
		return;
	      }
	      break;

	    default:
	      if(Coordenadas(Laberinto, fila, columna-1)){
		RecorrerLaberinto(Laberinto, x_mov, y_mov, fila, columna-1, abajo);
		return;
	      }
	      break;
	    }
	}
    }
}

