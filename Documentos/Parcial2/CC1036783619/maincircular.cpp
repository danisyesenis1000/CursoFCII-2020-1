#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include "circular.h"
int main(){
	cout<<"El movimiento circular tiene las siguientes posiciones: "<<endl;
	cout<<"                                                                    "<<endl;
	Circular circular1(1.0, 2.0, 0, 5, 0, 10);
	circular1.xpos();
	circular1.ypos();
	cout<<"                                                                    "<<endl;
	
	return 0;
}
