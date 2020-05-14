#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  vector<float> height{25, 25, 25, 25, 30, 30, 30, 30};
  vector<float> width{10, 10, 10, 10, 12, 12, 12, 12};
  vector<float> depth{5.0, 5.5, 6.0, 6.5, 5.0, 5.5, 6.0, 6.5};
  
  float const1, const2;
  float perimeter, volume, sup_area;
  //int n=8;
  
  cout << setw(10) << "Largo" << setw(10) << "Ancho" << setw(15) << "Profundidad" << setw(15) << "Perimetro" << setw(12) << "Volumen" << setw(22) << "Area de superficie" << endl;
  cout << "   " << string(80, '-') << endl;
  
  for(int i=0; i<height.size(); i++){
    const1 = height[i]+width[i];
    const2 = height[i]*width[i];
    
    perimeter = 2*const1;
    volume = const2*depth[i];
    sup_area = 2*const1*depth[i] + const2;
    
    cout << setiosflags(ios::right | ios::showpoint) << fixed << setprecision(1) << setw(10) << height[i] << setw(10) << width[i] << setw(15) << depth[i] << setw(15) << perimeter << setw(12) << volume << setw(22) << sup_area << endl;
  }
  
  return 0;
}
