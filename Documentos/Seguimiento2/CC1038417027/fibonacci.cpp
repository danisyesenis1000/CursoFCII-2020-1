#include <iostream>
#include <iomanip> 
#include <vector>

using namespace std;
//----------------------------------------------------------------------
//------------------------Para imprimir --------------------------------
//----------------------------------------------------------------------
void imprimirVector(const vector<int> &);

void espacios(string b, int nv)
{
  for(int i=0;i<=nv;i++)
    {
      cout<<b;
    }
}
//----------------------------------------------------------------------

/* NOTA:Para ambas funciones tanto fibo1 como fibo2 n corresponde al numero de
 terminos que se desean imprimir de la serie de fibonacci*/

//----------------------------------------------------------------------
//------------------Funcion que trabaja con arreglos--------------------
//----------------------------------------------------------------------
void fibo1(int n)
{
  int fib[n+1];
  
  for(int i=0; i<n+1;i++){
    if(i==0){
      fib[0]=1;
      cout<<"El termino "<<i<<" de la serie de fibonacci es: "<<fib[i]<<endl;
    }
    else if(i==1){
      fib[1]=1;
      cout<<"El termino "<<i<<" de la serie de fibonacci es: "<<fib[i]<<endl;
    }
    else{
      fib[i]=fib[i-1]+fib[i-2];
      cout<<"El termino "<<i<<" de la serie de fibonacci es: "<<fib[i]<<endl;
    }
  }
}
//----------------------------------------------------------------------
//----------------------Funcion que trabaja con vectores----------------
//----------------------------------------------------------------------
void fibo2(int n)
{
  vector<int>fib2(n);
  for(int i=0; i<n+1;i++)
    {
      if(i==0)
	{
	fib2[0]=1;
	}
      else if(i==1)
	{
	  fib2[1]=1;
	  
	}
      else
	{
	  fib2[i]=fib2[i-1]+fib2[i-2];
	  
	}
    }
  imprimirVector(fib2);
}
//----------------------------------------------------------------------

int main(){
  string n="-";
  espacios(n,50);
  cout<<"\nSerie con arreglos"<<endl;
  fibo1(8);
  espacios(n,50);
  //cout<<n*100;
  cout<<"\nSerie con vectores"<<endl;
  fibo2(11);
  espacios(n,50);
  cout<<"\n";
  return 0;
}

//----------------------------------------------------------------------
//-----------------Para mostrar en pantalla los vectores----------------
//----------------------------------------------------------------------
void imprimirVector(const vector<int> &arreglo)
{
  size_t i;
  for(i = 0; i<arreglo.size()+1;i++)
    {
      cout<<setw(12)<<arreglo[i];
      if ((i+1)%4 ==0)
	cout<<endl;
    }
  if ( i%4 !=0)
    cout<<endl;
}
//----------------------------------------------------------------------
