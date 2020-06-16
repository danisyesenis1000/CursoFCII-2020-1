#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string parrafo;
  cout<<"Ingrese algún párrafo del libro que esté leyendo"<<endl;
  getline(cin, parrafo);
  //int longitud = parrafo.length();
  
  string parrafo11(parrafo); //creo una copia de la entrada antes de modificarla para el punto 11
  string parrafo12(parrafo); //creo una copia de la entrada antes de modificarla para el punto 12
  
  //punto 10
  int i = parrafo.find("e"); // posicion de la primera e
  while (i!= string::npos ) //mientras i sea diferente a la ultima letra del parrafo
    {
      parrafo.replace(i,1, "x"); //reemplaza 1 caracter en la posicion i por una x
      i = parrafo.find("e", i+1); //siguiente posicion donde encuentre una letra e
    }
  
  cout<<"\nSi cambiamos las letras 'e' (sin tildar) de su párrafo por x, se obtiene:\n"<< parrafo << endl;
  
  // punto 11
  string buscar11;
  string reemplazo11;
  cout<<"\nAhora ingrese la cadena de caracteres que desea reemplazar en su párrafo, la primera vez que aparece"<<endl;
  getline(cin, buscar11);
  cout<<"\nIngrese la cadena de caracteres por la que desea reemplazarla"<<endl;
  getline(cin, reemplazo11);

  int j = parrafo11.find(buscar11);
  parrafo11.replace(j, int(buscar11.length()), reemplazo11);
  cout<<"Reemplazando el primer valor donde se encuentra la cadena, obtenemos:\n"<<parrafo11<<endl;

  // punto 12
  string buscar12;
  string reemplazo12;
  cout<<"\nPor último, ingrese la cadena que desee reemplazar a lo largo de todo su párrafo"<<endl;
  getline(cin, buscar12);
  cout<<"\n¿Qué cadena de caracteres quiere que la reemplace?"<<endl;
  getline(cin, reemplazo12);

  int k = parrafo12.find(buscar12); //primera apraricion de la cadena a reemplazar
  while(k != string::npos )
    {
      parrafo12.replace(k, int(buscar12.length()), reemplazo12);
      k = parrafo12.find(buscar12, k+1);
    }
  cout<<"Reemplazando la cadena escogida en todo el párrafo, se obtiene:\n"<<parrafo12<<endl;
      
    return 0;  
}
