#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::vector;

void fibonacci_arreglo(int,int *);
void mostrar_arreglo(int,int *);
void fibonacci_vector(int, vector< int >&);
void mostrar_vector(int,vector< int >&);

int main()
{
  cout << "ingrese hasta que valor de la sucesion de fibonacci quiere desplegar en pantalla" << endl;
  int lim;
  cin >> lim;

  //USANDO ARREGLOS
  int valores[lim]={0};
  fibonacci_arreglo(lim,valores);

  //USANDO VECTORES
  vector<int> valores1(1,0); //vector de tamaño 1 y ese valor inicializado en 0
  fibonacci_vector(lim,valores1);
  return 0;
}


/*============================================ Metodos Arreglos =========================================*/
void fibonacci_arreglo(int l,int *arreglo)
{
  int l1=0,l2=1,acum=0;
  if(l!=0)
    *(arreglo+1)=l2;
  for(int i=2;i<l;i++)
    {
      acum=l1+l2;
      *(arreglo+i)=acum;
      l1=l2;
      l2=acum;
    }
  mostrar_arreglo(l,arreglo);
}

void mostrar_arreglo(int l,int *arreglo)
{
  cout << setw(4);
  for(int i=0;i<l;i++)
    cout << *(arreglo+i) << setw(4);
  cout << endl;
}

/*============================================ Metodo vectores =========================================*/
void fibonacci_vector(int l,vector< int >&vector1)
{
  int l1=0,l2=1,acum=0;
  if(l!=0)
    vector1.push_back(l2);        //voy aumentando el tamaño del vector agregando el valor al final
  for(int i=2;i<l;i++)
    {
      acum=l1+l2;
      vector1.push_back(acum);    //voy aumentando el tamaño del vector agregando el valor al final
      l1=l2;
      l2=acum;
    }
  mostrar_vector(l,vector1);    
}

void mostrar_vector(int l,vector< int >&vector2)
{
  for(int i=0;i<l;i++)
    cout << vector2[i] << setw(4);
  cout << endl;
}
