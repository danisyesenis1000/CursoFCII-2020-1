#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <iostream>
using namespace std;

int main ()
{
    int iSecret, iGuess;
    int val;
    /* initialize random seed: */
    srand (time(NULL));
    while(val!=1)
    {
        /* generate secret number between 1 and 10: */
        iSecret = rand() % 1000 + 1;

        do{
            cout <<"adivina el numero entre (1 y 1000): ";
            cin >> iGuess;
            if (iSecret<iGuess){ 
                cout << "el numero es menor al elegido\n";
                }

            if (iSecret>iGuess){ 
                cout << "el numero es mayor al elegido\n";
                }
        }while (iSecret!=iGuess);
        
        cout << "el numero es correcto\n";
        cout<< "¿desea seguir jugando? (NO = 1, SI = 2)";
        cin >> val;
    }
    return 0;
}


