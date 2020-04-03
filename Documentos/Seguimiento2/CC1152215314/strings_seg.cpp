#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void ejercicio10(void);
void ejercicio11(void);
void ejercicio12(void);

int main()
{
  ejercicio10();
  ejercicio11();
  ejercicio12();
  return 0;
}


void ejercicio10(void)
{  
  cout << "Bienvenido al ejericio 10" << endl;
  
  string str1;
  cout << "introduzca un mensaje" << endl;
  getline(cin,str1);
 
  int pos=0;
  while(pos!=-1)
    {
      pos=str1.find("e");
      if(pos>=0)
	str1.replace(pos,1,"x");
    }
  cout << str1 << endl;
  cout << endl;
}

void ejercicio11(void)
{
  cout << "Bienvenido al ejericio 11" << endl;
  
  string str1;
  string str2;
  string str3;
  cout << "introduzca un mensaje" << endl;
  getline(cin,str1);
  cout << "introduzca la parte del string que quiere cambiar" << endl;
  getline(cin,str2);
  cout << "introduzca porque string quiere cambiarlo" << endl;
  getline(cin,str3);

  int pos=str1.find(str2);
  str1.replace(pos,str2.size(),str3);

  cout << str1 << endl;
  cout << endl;
}

void ejercicio12(void)
{
  cout << "Bienvenido al ejericio 12" << endl;
  
  string str1;
  string str2;
  string str3;
  cout << "introduzca un mensaje" << endl;
  getline(cin,str1);
  cout << "introduzca la parte del string que quiere cambiar, tenga en cuenta que todas las ocurrencias de lo que quiere cambiar seran modificadas " << endl;
  getline(cin,str2);
  cout << "introduzca porque string quiere cambiarlo" << endl;
  getline(cin,str3);
  int pos=0;
  while(pos!=-1)
    {
      pos=str1.find(str2,pos);
      if(pos>=0)
	str1.replace(pos,str2.length(),str3);
    }
  cout << str1 << endl;
  cout << endl;
}
