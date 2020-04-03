#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    cout << "Ejericio 10" << endl;

    string message; //declara un objeto string
    
    cout <<"Introduzca una cadena:\n ";
    
    getline(cin, message);

    cout << "La cadena que se acaba de introducir es:\n "
    <<message<<endl;
    
    int i=0;
    while(i!=string::npos)
    {
      i=message.find("e");
      
        if(i!=string::npos)
        {
            message.replace(i,1,"x");
        }
    
    }
    
    cout << "La cadena cambiada es:\n "
    <<message<<endl;


    cout << "Ejericio 11" << endl;

    string message1;
    string message2;
    string message3;
    cout << "Introduzca una nueva cadena:\n ";
    
    getline(cin, message1);

    cout << "La cadena que se acaba de introducir es:\n " <<message1<<endl;
    

    cout << "Introduzca la ocurrencia deseada:\n ";
    
    getline(cin, message2);

    cout << "La ocurrencia que desea buscar es:\n " <<message2<<endl;

    cout << "Introduzca el caracter por el cual desea cambiar:\n ";
    
    getline(cin, message3);

    cout << "el caracter por el cual desea cambiar es:\n " << message3<<endl;

    int j=0;
    j=message1.find(message2);
      
    if(j!=string::npos)
    {
        message1.replace(j,int(message2.length()),message3);
    }
    
    
    
    cout << "La cadena cambiada es:\n "
    <<message1<<endl;


    cout << "Ejericio 12" << endl;

    string message4;
    string message5;
    string message6;
    cout << "Introduzca una nueva cadena:\n ";
    
    getline(cin, message4);

    cout << "La cadena que se acaba de introducir es:\n " <<message5<<endl;
    

    cout << "Introduzca la ocurrencia deseada:\n ";
    
    getline(cin, message5);

    cout << "La ocurrencia que desea buscar es:\n " <<message5<<endl;

    cout << "Introduzca el caracter por el cual desea cambiar:\n ";
    
    getline(cin, message6);

    cout << "el caracter por el cual desea cambiar es:\n " <<message6<<endl;

    int k=0;
    while(k!=string::npos)
    {
      k=message4.find(message5);
      
        if(k!=string::npos)
        {
            message4.replace(k,int(message5.length()),message6);
        }
    
    }
    
    
    cout << "La cadena cambiada es:\n "
    <<message4<<endl;
    return 0;
}




