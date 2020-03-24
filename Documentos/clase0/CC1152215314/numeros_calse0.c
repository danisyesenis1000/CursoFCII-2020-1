#include <stdio.h>
#include <stdlib.h>

int suma(int , int ); //prototipo de funcion a utilizar

int suma(int n1,int n2){
  int acum,i;
  printf("introduzca dos valores enteros\n");
  printf("introduzca el menor de los valores\n");
  scanf("%d",&n1);
  printf("introduzca el mayor de los valores\n");
  scanf("%d",&n2);
  acum=0;
  for(i=n1;i<=n2;i++)
    {
      acum=acum+i;
    }
  return acum;
}

int main()
{
  int total,d1,d2,ind;
  total=suma(d1,d2);

  printf("introduzca el 1 si quiere salida en pantalla o 0 si quiere salida en archivo txt\n");
  scanf("%d",&ind);
  
  if(ind==1)
    printf("%d \n",total);
  
  if(ind==0)
    {
      FILE *cfptr; //puntero a FILE
      if((cfptr=fopen("salida.dat","w"))==NULL)
	printf("El archivo no pudo ser abierto\n");
      else
	{
	  fprintf(cfptr,"%d",total);
	  fclose(cfptr);
	}
    }
  return 0;
}
