#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  
  cout << "Largo-- " << "--Ancho-- " << "--Profundidad-- " << "--Perimetro-- " << "--Volumen-- " << "--Area de sup sub " << endl;
  
  for (float  pro=5.0; pro<7.0; pro=pro+0.5){

    float la=25.0;
    float an=10.0;
    float pe;
    float vo;
    float ar;
    pe=2.0*(la+an);
    vo=la*an*pro;
    ar=(pe*pro)+(la*an);
    
    cout << " " << fixed << setprecision(1) << la << "      " << an << "         " << pro << "            " << pe << "        " << vo << "         " << ar << "      " << endl;
  }

  for (float  pro=5.0; pro<7.0; pro=pro+0.5){

    float la=30.0;
    float an=12.0;
    float pe;
    float vo;
    float ar;
    pe=2.0*(la+an);
    vo=la*an*pro;
    ar=(pe*pro)+(la*an);
    
    cout << " " << fixed << setprecision(1) << la << "      " << an << "         " << pro << "            " << pe << "        " << vo << "         " << ar << "      " << endl;
    
    
  }
  
  return 0;
}
