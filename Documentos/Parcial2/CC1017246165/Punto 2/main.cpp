#include"clase.h"

int main(){
  cout<<"A continuación está el programa de las 8 reinas, confirmaremos si encontramos solución"<<endl;
  int FilasAjedrez,ColumnasAjedrez,NumeroReinas;
  FilasAjedrez=8;
  ColumnasAjedrez=8;
  NumeroReinas=8;
  Reinas Ajedrez1(FilasAjedrez,ColumnasAjedrez,NumeroReinas);
  Ajedrez1.CajaAjedrez();
  cout<<"\n \n";
  Ajedrez1.PosicionReinas();
  return 0; 
}
