/*
Programa que usa la clase definida en "RectangleHeader.h" y sus
funciones definidas en "RectangleImplem.cpp" para calcular el
area y perimetro de un rectangulo, ingresados su largo y ancho.

Compilacion y ejecucion:
g++ RectangleImplem.cpp RectangleExec.cpp -o Rectangle.exe
./Rectangle.exe
*/

#include <iostream>
#include "RectangleHeader.h"

int main()
{
  //Definicion de variables y espacios de memoria
  double MiLargo = 0.0, MiAncho = 0.0;
  double MiArea = 0.0, MiPerimetro = 0.0;
  std::vector<double> MisDatosIniciales {MiLargo, MiAncho};
  std::vector<double> MisDatosFinales {MiArea, MiPerimetro};

  //Creacion de clase "MiFigura"
  Rectangulo MiFigura;

  //Peticion de datos de entrada al usuario
  MiFigura.obtenerLargo();
  MiFigura.obtenerAncho();

  //Asignacion de los datos de entrada
  MisDatosIniciales[0] = MiFigura.asignarLargo( MiLargo );
  MisDatosIniciales[1] = MiFigura.asignarAncho( MiAncho );

  //Calculo del area y perimetro segun los datos ingresados
  MiArea = MiFigura.area();
  MiPerimetro = MiFigura.perimetro();

  //Asignacion de los datos de salida
  MisDatosFinales = MiFigura.asignarDatos( MiArea, MiPerimetro );

  //Muestra en pantalla de los resultados
  MiFigura.mostrarDatos( MisDatosFinales );

  return 0;
}
