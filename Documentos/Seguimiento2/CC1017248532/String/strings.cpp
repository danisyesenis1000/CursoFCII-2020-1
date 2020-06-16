//This code corresponds to exercises 7.2.10, 7.2.11 and 7.2.12 from the guide book

#include <iostream>
#include <string>

using namespace std;

void Exercise10(string &);
void Exercise11(string &);
void Exercise12(string &);

int main(){
  string answer;
  
  string st1 = "hola me gusta el 456 porque el 456 es lo mejor";
  
  cout << "Por favor seleccione el ejercicio que quiere revisar: " << endl
       << "Ej 10: 0. Ej 11: 1. Ej 12: 2" << endl;

  getline(cin, answer);
  cout << endl;
  
  switch(stoi(answer)){

  case 0:
    Exercise10(st1);
    break;
    
  case 1:
    Exercise11(st1);
    break;

  case 2:
    Exercise12(st1);
    break;

  default:
    cout << "No se escogió una opción válida" << endl;
    break;
  }

  cout << endl;
  cout << "El string resultante tras correr el Ejercicio 1" << answer << ". Es: " << endl
       << st1 << endl;
  
  return 0;
}

void Exercise12(string &refstring){

  string st2; //Caracteres que serán reemplazados
  string st3; //Caracteres que se usarán para reemplazar st2
  
  cout << "El string a ser alterado es: " << endl
       << refstring << endl << endl;

  cout << "Por favor ingrese los caracteres que desea reemplazar" << endl;
  getline(cin, st2);
  
  cout << "Por favor ingrese los caracteres con los que desea reemplazarlo" << endl;
  getline(cin, st3);
  
  int pos = refstring.find(st2);

  while (pos != string::npos){
    
    refstring.replace(pos, st3.size(), st3);
    pos = refstring.find(st2, pos + st3.size());
  }
  
}

void Exercise11(string &refstring){

  string st2; //Caracteres que serán reemplazados
  string st3; //Caracteres que se usarán para reemplazar st2
  
  cout << "El string a ser alterado es: " << endl
       << refstring << endl << endl;

  cout << "Por favor ingrese los caracteres que desea reemplazar" << endl;
  getline(cin, st2);
  
  cout << endl;

  cout << "Por favor ingrese los caracteres con los que desea reemplazarlo" << endl;
  getline(cin, st3);
  
  int pos = refstring.find(st2);

  refstring.replace(pos, st3.size(), st3);

}

void Exercise10(string &refstring){
  
  cout << "El string original es: " << refstring << endl << endl;
  
  int posicion = refstring.find("e");

  while (posicion != string::npos){

    refstring.replace(posicion, 1, "x");
    posicion = refstring.find("e", posicion + 1);
  }
}
