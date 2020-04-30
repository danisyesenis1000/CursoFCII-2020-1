#include<iostream>
#include<cmath>
#include "espiral.h"

int main(){

	cout<<"El movimiento en espiral tiene las siguientes posiciones: "<<endl;
	cout<<"                                                                    "<<endl;
	Espiral espiral1(1.0, 2.0, 0, 5, 0, 10, 2.0, 3.0);
	espiral1.xpos();
	espiral1.ypos();
	espiral1.zpos();
	
	
	return 0;
}
