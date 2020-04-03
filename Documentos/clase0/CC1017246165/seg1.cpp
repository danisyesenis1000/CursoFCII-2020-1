#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  double l,a,p,per,vol,as;
  /*  
  cout << "\introduzca un valor de largo ";
  cin >> l;
  cout << "\introduzca un valor de ancho ";
  cin >> a;
  cout << "\introduzca un valor de profundidad ";
  cin >> p;
  */
  cout <<"largo   Ancho   Profundidad   Perimetro   Volumen   Area Superficie Subterranea\n";
  cout <<"_____   _____   ___________   _________   _______   ___________________________ \n";


 

  l=25;
  a=10;
  p=5.0;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;
  l=25;
  a=10;
  p=5.5;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;
  l=25;
  a=10;
  p=6.0;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;

  l=25;
  a=10;
  p=6.5;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;

			
  l=30;
  a=12;
  p=5.0;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;
  l=30;
  a=12;
  p=5.5;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;
			    
  l=30;
  a=12;
  p=6.0;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;

  l=30;
  a=12;
  p=6.5;
  
  per = 2*(l+a);
  vol = l*a*p;
  as = 2*(l+a)*p + l*a;
  
  cout << setw(6) <<setiosflags(ios::showpoint)<<  l
       << setw(8) << a
       << setw(8) << p
       << setw(14) << per
       << setw(14) << vol
       << setw(14) << as << endl;

  return 0;
}

