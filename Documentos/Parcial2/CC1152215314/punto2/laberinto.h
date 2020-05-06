#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

class Laberinto
{
 public:
  Laberinto(int );
  void Generar_Laberinto(void);
  void Recorrer_Laberinto(void);
  void Laberinto_pdf(void);
  void Imprimir_Laberinto(void);
  void Copiar_Laberinto(void);
 private:
  int pasos;
  int dim;
  char copia[12][12];
  char arreglo[12][12];
  int centinela;
  int imp;
};
