#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void cambia_letra(string); // prototipo de la funcion cambiar _letra

int main()
{
  string string1;// Se define el primer string1
  cout<<"==Cambiar la letra 'e' por una letra 'x'==\n"<<endl;
  cout<<"Ingresa cadena de caracteres= ";
  getline(cin, string1);  // Pide al usuario agregar una cadena de caracteres
  cout<<endl;

  cambia_letra(string1); // llama lla funcion cambia_letra
    
  return 0;
}

//creamo la funcion cambiar letra

void cambia_letra(string string1)
{
  int posicion = string1.find( "e" ); // utilizamos find para encontrar la letra 'e'
  while ( posicion != string::npos ) // cambiamos todas las letras 'e' por x
    {
      string1.replace( posicion, 1, "x" );
      posicion = string1.find( "e", posicion + 1 );
    }
  
  cout<<"La nueva cadena de carateres es = "<<string1<<endl; // se imprime la nueva cadena
  
}
