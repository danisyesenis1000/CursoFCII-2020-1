#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Reemplazo1( string & );          //Punto 10
void Reemplazo2( string &, string &, string & );   // Punto 11
void Reemplazo3( string &, string &, string & );   // Punto 12

int main()
{
  string Cadena1, Cadena2, Cadena3, Cadena4, Cadena5, Cadena6, Cadena7, Cadena8; 

  // Punto 10
  
  cout << "Punto 10" << endl;
  cout << "Por favor ingrese una oración:" << endl;
  getline( cin, Cadena1 );

  Reemplazo1( Cadena1 );

  cout << "\nLa oración despues de hacer el reemplazo es:" << endl;
  cout << Cadena1 << endl;

  // Punto 11

  cout << "\n Punto 11\n";
  cout << "Por favor ingrese una oración: " << endl;
  getline( cin, Cadena2 );

  cout << "Palabra que desea reemplazar: ";
  getline( cin, Cadena3 );
  cout << "Palabra reemplazo: ";
  getline( cin, Cadena4);

  Reemplazo2( Cadena2, Cadena3, Cadena4 );

  cout << "\nLa oracion despues de hacer el reemplazo es: " << endl;
  cout << Cadena2 << endl;

  // Punto 12

  cout << "\n Punto 12 \n";
  cout << "Por favor ingrese una oracion:\n ";
  getline(cin, Cadena5 );

  cout << "Palabra que desea reemplazar: ";
  getline( cin, Cadena6 );
  cout << "Palabra reemplazo: ";
  getline( cin, Cadena7 );

  Reemplazo3( Cadena5, Cadena6, Cadena7 );

  cout << "\nLa oración despues de hacer el reemplazo:\n";
  cout << Cadena5 << endl; 

  return 0;
}

void Reemplazo1( string &Cadena1 )
{
  int posicion = Cadena1.find( "e" );

  while( posicion != string::npos )
    {
      Cadena1.replace( posicion, 1, "x" );
      posicion = Cadena1.find( "e", posicion + 1 );
    }
}

void Reemplazo2( string &Cadena2, string &Cadena3, string &Cadena4 )
{
  int posicion1 = Cadena2.find( Cadena3 );
  Cadena2.replace ( posicion1, Cadena3.length(), Cadena4 );
  
}

void Reemplazo3( string &Cadena5, string &Cadena6, string &Cadena7)
{
  int posicion2 = Cadena5.find( Cadena6 );

  while( posicion2 != string::npos )
    {
      Cadena5.replace(posicion2, Cadena6.length(), Cadena7 );
      posicion2 = Cadena5.find( Cadena6, posicion2 + 1);
    }
}
