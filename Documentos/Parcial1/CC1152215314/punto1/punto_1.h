#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

class Adivinar{
 public:
  Adivinar();               //Constructor de la clase
  void Jugar();             //unica llamada que hara el usuario
  void AsignarCorrecto();   //Asigna el valor aleatorio entre 0 y 1000
  void ValorUsuario();      //le pide el valor al usuario
  void MostrarMensaje();    //desplegara los mensajes en pantalla
 private:
  int intento;              //variable del intento
  int correcto;             //variable donde se guardara el valor a adivinar
};
