#include"clase.h"

Reinas::Reinas(int fajedrez1,int cajedrez1,int nreinas1){
  fajedrez=fajedrez1;
  cajedrez=cajedrez1;
  nreinas = nreinas1;
}

Reinas::~Reinas(){
}

 
int Reinas::CajaAjedrez(){
  char preinas[fajedrez][cajedrez];
  for(int i=0;i<fajedrez;i++){ //Crea la caja
    for(int j=0;j<cajedrez;j++){
      preinas[i][j]= 'X';
    }
  }
  for(int i=0;i<fajedrez;i++){
    for(int j=0;j<cajedrez;j++){
      cout<<preinas[i][j]; //Imprime la caja
    }
    cout<<"\n";
  }
}

//Acá se realiza el algoritmo
int Reinas::PosicionReinas(){
  int intentos=cajedrez*fajedrez;
  int preinas[intentos][fajedrez][cajedrez]; //Matriz de posiciones actuales
  int prreinas[intentos][fajedrez][cajedrez]; //Matriz donde se copiará la configuración actual para comparar
  int contador[intentos];
  int i;
  int j;
  int p;
  for(p=0;p<intentos;p++){
    contador[p]=0;
    for(i=0;i<fajedrez;i++){
      for(j=0;j<cajedrez;j++){
	preinas[p][i][j]= 0; //Volvemos a crear nuestro tablero
      }
    }
  }
  for(p=0;p<intentos;p++){
    for(i=0;i<fajedrez;i++){
      for(j=0;j<cajedrez;j++){
	int demonio1=0;//Crea un "demonio" para columnas (analogía demonio maxwell o ejemplos de M.C), que busca reinas
	int demonio2=0;//Crea un "demonio" para filas
	int demonio31=0;//Crea un "demonio" para la diagonal superior
	int demonio32=0;//Crea un "demonio" para la diagonal inferior
	int demonio33=0;//Crea un "demonio" para la segunda diagonal superior
	int demonio34=0;//Crea un "demonio" para la segunda diagonal inferior
	for(int k=0;k<cajedrez;k++){
	  if(preinas[p][i][k]!=0){ //Filas
	    demonio1=1;
	  }
	}
	for(int k=0;k<fajedrez;k++){
	  if(preinas[p][k][j]!=0){ //Columnas
	    demonio2=1;
	  }
	}
	for(int k=0;k<cajedrez;k++){
	  if(preinas[p][i+k][j+k]!=0 && (i+k)<cajedrez && (j+k)<fajedrez){ //Diagonal superior
	    demonio31=1;
	  }
	}
	
	for(int k=0;k<fajedrez;k++){
	  if(preinas[p][i-k][j-k]!=0 && (i-k)>=0 && (j-k)>=0){ //Diagonal inferior
	    demonio32=1;
	  }
	}
	
	for(int k=0;k<cajedrez;k++){
	  if(preinas[p][i+k][j-k]!=0 && (i+k)<fajedrez && (j-k)>=0){ //Antidiagonal superior
	    demonio33=1;
	  }
	}
	
	for(int k=0;k<fajedrez;k++){
	  if(preinas[p][i-k][j+k]!=0 && (i-k)>=0 && (j+k)<cajedrez){ //Antidiagonal inferior
	    demonio34=1;
	  }
	}
	if(demonio1!=1 && demonio2!=1 && demonio31!=1 && demonio32!=1 && demonio33!=1 && demonio34!=1){ //Condición de Reina
	  preinas[p][i][j]=1; //Pone la reina
	  for(int h=0;h<intentos;h++){
	    if(preinas[p][i][j]==prreinas[h][i][j]){ //Compara con la pasada y todas sus anteriores
	      preinas[p][i][j]=0; //Cambia reina para evitar repetir la misma rutina
	    }
	  }
	  if(preinas[p][i][j]==1){
	    contador[p]=contador[p]+1; //Contador de reinas
	  }
	}
      }
    }
    for(i=0;i<fajedrez;i++){
      for(j=0;j<cajedrez;j++){
	prreinas[p][i][j]=preinas[p][i][j]; //Copia la configuración actual
      }
    }    
  }
  for(int p=0;p<intentos;p++){
    if (contador[p]==nreinas){
      for(int i=0;i<fajedrez;i++){
	for(int j=0;j<cajedrez;j++){ 
	  cout<<preinas[p][i][j]; //Nuestra matriz de n reinas
	}
	cout<<"\n";
      }
      cout<<"\n";
    }
  }
  cout<<"\n";  
}

