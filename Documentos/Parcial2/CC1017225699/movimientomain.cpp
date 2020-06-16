// Demostración de la clase Rectangulo después de separar
// su interfaz desde su implementación.

#include <iostream>
#include <iomanip>
using namespace std;


#include "espiral.h" // NOTE: inclulle la definicion de la clase

int main()
{
   
   espiral S(0,5,3,1,1,0); //z0,V,radio, omega, alfa, tiempo
   cout << "movimiento espiral con parametros: Radio: " << S.getRadio() << ", frecuencia: " << S.getOmega() << ", fase: " <<S.getAlfa()<< " y velocidad: " << S.getV()
        << "\nsu Trayectoria es: "
        << "\n Tiempo   " << "Xpos    " << "Ypos     "<< "Zpos"<<endl;

        for(double i=0;i<100;i++)
        {
            double t =i*0.5;
            //cout << t<< endl;            
            espiral S(0,5,3,1,1,t);
            //cout << S.getTiempo()<< endl;     
            cout << "\n "<< setw(4) << S.getTiempo() << setw(8) << setprecision(2) << S.getXpos() <<setw(9) << setprecision(3) <<S.getYpos()<<setw(9) << setprecision(3) <<S.getZpos() <<endl; 
        }        
        
   
   return 0; 
} 
