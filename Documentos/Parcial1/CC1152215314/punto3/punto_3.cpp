#include "punto_3.h"

Complejo::Complejo(){numero1[0]=0;numero1[1]=0;numero2[0]=0;numero2[1]=0;suma[0]=0;suma[1]=0;resta[0]=0;resta[1]=0;multiplicacion[0]=0;multiplicacion[1]=0;};

void Complejo::MostrarNumeros()
{
  cout << "numero1 = " << setw(5) << fixed << setprecision(2) << *(numero1) << " + i" << setw(5) << fixed << setprecision(2) << *(numero1+1) << endl;
  cout << "numero2 = " << setw(5) << fixed << setprecision(2) << *(numero2) << " + i" << setw(5) << fixed << setprecision(2) << *(numero2+1) << endl;
}

void Complejo::AsignarDatos1(double real1,double imaginario1)
{
  *(numero1)=real1;
  *(numero1+1)=imaginario1;
}

void Complejo::AsignarDatos2(double real2,double imaginario2)
{
  *(numero2)=real2;
  *(numero2+1)=imaginario2;
}

void Complejo::SumaNumeros()
{
  *(suma)=(*(numero1))+(*(numero2));
  *(suma+1)=(*(numero1+1))+(*(numero2+1));;
  cout << "la suma es = " << setw(6) << fixed << setprecision(2) << *(suma) << " + i"<< setw(6) << fixed << setprecision(2) << *(suma+1) << endl;
}

void Complejo::RestaNumeros()
{
  *(resta)=(*(numero1))-(*(numero2));
  *(resta+1)=(*(numero1+1))-(*(numero2+1));;
  cout << "la resta es = " << setw(6) << fixed << setprecision(2) << *(resta) << " + i"<< setw(6) << fixed << setprecision(2) << *(resta+1) << endl;
}


void Complejo::MultiplicaNumeros()
{
  *(multiplicacion) = (*(numero1)) * (*(numero2)) - (*(numero1+1)) * (*(numero2+1));
  *(multiplicacion+1) = (*(numero1+1)) * (*(numero2)) + (*(numero1)) * (*(numero2+1));
  cout << "la multiplicacion es = " << setw(6) << fixed << setprecision(2) << *(multiplicacion) << " + i"<< setw(6) << fixed << setprecision(2) << *(multiplicacion+1) << endl;

}

void Complejo::MostrarParteReal()
{
  cout << "Parte real del numero1 = " << setw(5) << fixed << setprecision(2) << *(numero1) << endl << "Parte real del numero2 = " << setw(5) << fixed << setprecision(2) << *(numero2) << endl;
}

void Complejo::MostrarParteImg()
{
  cout << "Parte imaginaria del numero1 = " << setw(5) << fixed << setprecision(2) << *(numero1+1) << endl << "Parte imaginaria del numero2 = " << setw(5) << fixed << setprecision(2) << *(numero2+1) << endl;
}
