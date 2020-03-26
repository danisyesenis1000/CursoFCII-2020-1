#include <iostream>


using namespace std;

void perfecto(int num)
{
  int suma=0 ; 
  for (int i = 1;i<num;i++)
    {
      
      if(num%i==0)
	{
	  // cout<<"El numero "<<i<<" es multiplo"<<endl;
	  suma = suma + i;
	}
    }
  if (suma == num)
    {
      cout<<"El número "<<num<<" es un número perfecto"<<endl;
    }
}
int main()
{
  for(int x = 1;x<=10000;x=x+1)
    {
      perfecto(x);
    }
  
  return 0;
}
