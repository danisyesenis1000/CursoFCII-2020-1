#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;

//Clase

class Reinas{
private:
  int fajedrez; //Filas
  int cajedrez; //Columnas
  int nreinas; //Numero de reinas
public:
  Reinas(int,int,int); //Constructor
  ~Reinas(); //Destructor
  int CajaAjedrez(); //Funcion que nos muestra nuestro ajedrez
  int PosicionReinas(); //Funcion que establece posición de las reinas
};
