#include "laberinto.h"

Laberinto::Laberinto(int dimension)
{
  dim=dimension;     //dimension del laberinto, para generarlo de forma aleatoria podria en principio cambiarse, cualquier dimension!
  pasos=0;           //me va a ir contando los pasos que da el hombrecito en el laberinto
  imp=1;             //si es 1 imprime el laberinto en cada paso, si es 0 no lo imprime
}

//FUNCION QUE IMPRIME LABERINTO
void Laberinto::Imprimir_Laberinto(void )
{
  for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
	{
	  cout << setw(3) << copia[i][j];
	}
      cout << endl;
    }
  cout << endl;
  cout << "==================================" << "PASO " << pasos << " ===============================" << endl;
}

//CREO A MANO EL LABERINTO DEL EXAMEN
void Laberinto::Laberinto_pdf(void)
{
  for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
	{
	  if(i==0 || i==dim-1)
	    arreglo[i][j]='#';
	  else
	    {
	      if(j==0 || j==dim-1)
		arreglo[i][j]='#';
	      else
		arreglo[i][j]='.'; 
	    }
	}
    }
  arreglo[2][0]='.';
  arreglo[1][4]='#'; arreglo[2][2]='#'; arreglo[2][4]='#'; arreglo[2][6]='#'; arreglo[2][7]='#'; arreglo[2][8]='#';
  arreglo[2][9]='#'; arreglo[3][1]='#'; arreglo[3][2]='#'; arreglo[3][4]='#'; arreglo[3][9]='#';
  arreglo[4][5]='#'; arreglo[4][6]='#'; arreglo[4][7]='#'; arreglo[4][9]='#';
  arreglo[5][1]='#'; arreglo[5][2]='#'; arreglo[5][3]='#'; arreglo[5][5]='#'; arreglo[5][7]='#'; arreglo[5][9]='#';
  arreglo[6][3]='#'; arreglo[6][5]='#'; arreglo[6][7]='#'; arreglo[6][9]='#';
  arreglo[7][1]='#'; arreglo[7][3]='#'; arreglo[7][5]='#'; arreglo[7][7]='#'; arreglo[7][9]='#';
  arreglo[8][9]='#';
  arreglo[9][1]='#'; arreglo[9][2]='#'; arreglo[9][3]='#'; arreglo[9][4]='#'; arreglo[9][5]='#'; arreglo[9][7]='#'; arreglo[9][8]='#'; arreglo[9][9]='#';
  arreglo[10][7]='#';
  arreglo[4][11]='.';
}


//ESTA FUNCION ME VA A COPIAR EL LABERINTO CON EL FIN DE SOBRE LA COPIA IR PONIENDO LAS 'X' A MEDIDA QUE AVANZA EL HOMBRECILLO
void Laberinto::Copiar_Laberinto()
{
  for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
	{
	  copia[i][j]=arreglo[i][j];
	}
    }
}

//FUNCION QUE RESUELVE LABERINTOS
void Laberinto::Recorrer_Laberinto()
{
  //encontrar la posicion inicial siempre a la izquierda
  int h=0;
  for(int i=0;i<dim;i++)
    {
      if(arreglo[i][0]=='.')
	{
	  h=i;
	  break;
	}
    }

  int x=h;int y=1; //esta es la posicion inicial x:filas, y:columnas arreglo[x][y]
  int c=1;         //este numero me dice cual es la derecha del hombrecito en el laberinto
                   //si esta en 1, es porque va caminando hacia donde las columnas aumentan y su derecha es la casilla de abajo
                   //si esta en 2, es porque va caminando hacia donde las filas disminuyen y su derecha es la casilla de la derecha
                   //si esta en 3, es porque va caminando hacia donde las filas aumentan y su derecha es la casilla de la izquierda
                   //si esta en 4, es porque va caminando hacia donde las columnas disminuyen y su derecha es la casilla de arriba
  if(imp==1)
    cout << "posicion inicial " << x << ',' << y << endl;
  
  //mis vecinos seran:
  // arreglo[i][j+1]
  // arreglo[i][j-1]
  // arreglo[i+1][j]
  // arreglo[i-1][j]

  //Copiar Laberinto
  Copiar_Laberinto();

  //Laberinto inicial
  if(imp==1)
    Imprimir_Laberinto();

  //Ponemos x en los valores iniciales del laberinto
  copia[x][y]='x';
  copia[x][y-1]='x';

  int acum=0;  //este contador me va a decir que si me demoro mucho en resolver un laberinto de prueba es que ese laberinto no se puede resolver
  pasos=0;     //pasos=0 para ir llevando el conteo para cada laberinto que intente
  while(y<11)
  {
    acum+=1;
    if(acum>900)       //si acumulador es mayor que 900 el laberinto no se pudo resolver (se puede mejorar poniendo el numero maximo como funcion de la dimension, pero asumi que para 12x12 900 pasos es suficiente para descartar el laberinto)
      {
	centinela=2;   //centinela=2 le va a decir a la funcion que crea laberintos que el que creo no se puede resolver
	break;
      }
    //CONDICIONES PARA CUANDO C=1
    if(c==1 && arreglo[x+1][y]=='#' && arreglo[x][y+1]=='.')  //SITUAICON_1: si tengo muro abajo y puedo avanzar a la derecha lo hago.
      {
	y+=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)                 //si imp=1 imprima, si imp=0 no imprima estoy probando laberintos
	  Imprimir_Laberinto();
	continue;
      }
    if(c==1 && arreglo[x+1][y]=='#' && arreglo[x][y+1]=='#' && arreglo[x-1][y]=='.') //SITUACION_2: muro abajo y adelante y puedo avanzar hacia arriba lo hago.
      {
	x-=1;
	c=2;  //al subir quedo mirando hacia donde disminuyen las filas.

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==1 && arreglo[x+1][y]=='#' && arreglo[x][y+1]=='#' && arreglo[x-1][y]=='#') //SITUACION_3: muro abajo y adelante y arriba me devuelvo.
      {
	y-=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	c=4; //al devolverme ya quedo mirando hacia donde las columnas disminuyen.
	continue;
      }
    if(c==1 && arreglo[x+1][y]=='.')  //SITUACION_4: vengo yendo a la derecha y puedo ir abajo.
      {
	x+=1;
	c=3; //al bajar ya quedo mirando hacia donde aumentan las filas.

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }


    
    //CONDICIONES PARA C=2
    if(c==2 && arreglo[x-1][y]=='#' && arreglo[x][y+1]=='#')
      {
	y-=1;
	c=4;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==2 && arreglo[x][y+1]=='.')
      {
	y+=1;
	c=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==2 && arreglo[x-1][y]=='#' && arreglo[x][y+1]=='#' && arreglo[x][y-1]=='#')
      {
	x+=1;
	c=3;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==2 && arreglo[x][y+1]=='#' && arreglo[x-1][y]=='.')
      {
	x-=1;
	copia[x][y]='x';

	pasos+=1;
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }


    
    //CONDICIONES PARA C=3
    if(c==3 && arreglo[x][y-1]=='#' && arreglo[x+1][y]=='#' && arreglo[x][y+1]=='#')
      {
	x-=1;
	c=2;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==3 && arreglo[x][y-1]=='#' && arreglo[x+1][y]=='.')
      {
	x+=1;
	copia[x][y]='x';

	pasos+=1;
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==3 && arreglo[x][y-1]=='.')
      {
	y-=1;
	c=4;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==3 && arreglo[x][y-1]=='#' && arreglo[x+1][y]=='#' && arreglo[x][y+1]=='.')
      {
	y+=1;
	c=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }

    

    //CONDICIONES PARA C=4
    if(c==4 && arreglo[x-1][y]=='#' && arreglo[x][y-1]=='.')
      {
	y-=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==4 && arreglo[x][y-1]=='#' && arreglo[x-1][y]=='#' && arreglo[x+1][y]=='#')
      {
	y+=1;
	c=1;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==4 && arreglo[x-1][y]=='#' && arreglo[x][y-1]=='#' && arreglo[x+1][y]=='.')
      {
	x+=1;
	c=3;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
    if(c==4 && arreglo[x-1][y]=='.')
      {
	x-=1;
	c=2;

	pasos+=1;
	copia[x][y]='x';
	if(imp==1)
	  Imprimir_Laberinto();
	continue;
      }
  }
  if(centinela!=2 && imp==1)
    {
      cout << "posicion final " << x << "," <<  y << endl;
    }
}


//====================================================
// GENERAR LABERINTOS DE FORMA ALEATORIA
//====================================================
void Laberinto::Generar_Laberinto(void )
{
  centinela=0;             //me va a decir si el que creo se puede resolver o no. 
  while(centinela==0)      //mi idea es crear una matriz dim x dim con entradas aleatorias entre '#' y '.'
    {                      // (para mi es una analogia de como se llena una reticula con espines en un material paramagnetico)
      srand(time(NULL));
      double a;
      for(int i=0;i<dim;i++)
	{
	  for(int j=0;j<dim;j++)
	    {
	      if(i==0 || i==dim-1)                    //pongo '#' en las fronteras
		arreglo[i][j]='#';
	      else
		{
		  if(j==0 || j==dim-1)                //pongo '#' en las fronteras
		    arreglo[i][j]='#';
		  else
		    {
		      a=(double) rand()/RAND_MAX;
		      if(a<0.3)                       //manipulo las probabilidades con que pone '#' o '.'
			arreglo[i][j]='#';
		      if(a>=0.3)
			arreglo[i][j]='.'; 
		    }
		}
	    }
	}
      int g1=1+rand()%(dim-2);  //genero un numero aleatorio entero entre 1 y 10 de cual sera la entrada al laberinto
      arreglo[g1][0]='.';
      arreglo[g1][1]='.';

      int g2=1+rand()%(dim-2);  //genero un numero aleatorio entero entre 1 y 10 de cual sera la salida al laberinto
      arreglo[g2][dim-1]='.';
      arreglo[g2][dim-2]='.';

      // prueba de que no hay columnas todas '#' esto de entrada seria un laberinto que no se resuelve
      int n=0;
      for(int l1=1;l1<dim-1;l1++)
	{
	  n=0;
	  for(int l2=1;l2<<dim-1;l2++)
	    {
	      if(arreglo[l2][l1]=='.')
		{
		  n=1;
		  break;
		}
	    }
	  if(n==0) //si hay un muro completo en una columna ==> laberinto no sirvio
	    {
	      centinela=2;
	      break;
	    }
	}

      if(centinela==2)
	{
	  centinela=0; // condicion de que el laberinto no sirvio, vuelva a hacer otro.
	  continue;
	}
	
      //Prueba de que se pudo resolver
      imp=0;                 //esto para que no imprima ya que es un intento
      Recorrer_Laberinto();  //si salgo de la prueba con centinela==2 vuelva a hacer otro, si salgo con centinela==0, eureka!

      if(centinela==2)
	{
	  centinela=0;   // condicion de que el laberinto no sirvio, vuelva a hacer otro.
	  continue;
	}
	
      if(centinela==0)
	{
	  break;      //condicion de salida
	}
    }
  cout << endl;
  cout << "==================================" << " LABERINTO ALEATORIO ===============================" << endl;
  
  for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
	{
	  cout << setw(3) << arreglo[i][j];
	}
      cout << endl;
    }
  //ahora si resulva el laberinto e imprimalo, ya se que se puede resolver
  imp=1;                 //esto para que  imprima ya que es estoy seguro el laberinto se puede resolver
  Recorrer_Laberinto();

  cout << endl;
  cout << endl;
  cout << "El programa resuelve el laberinto propuesto en el pdf el cual se que se resuelve en 80 pasos, luego crea un laberinto de forma aleatoria y tambien lo resuelve, el numero de pasos para resolverlo es incierto pero debe ser menor a 900 pasos" << endl;
}
