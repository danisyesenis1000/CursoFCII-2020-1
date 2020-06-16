//Ejercicio 11
//Luisa Fernanda Vargas Restrepo

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string cadena, cadena1, cadena2;
  cout << "Ingrese el mensaje: " << endl;
  getline(cin, cadena);
  cout << "Ingrese la cadena que va a cambiar: " << endl;
  getline(cin, cadena1);
  cout << "Ingrese el reemplazo de la cadena que va a cambiar: " << endl;
  getline(cin, cadena2);
  int longitud = cadena1.length();
  int posicion = cadena.find(cadena1);
  
  cadena.replace(posicion, longitud, cadena2);
  
  cout << "El mensaje cambiado es: " << cadena << endl;
    
  return 0;
}
