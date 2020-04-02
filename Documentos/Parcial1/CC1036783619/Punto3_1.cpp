#include <iostream>
#include <stdlib.h>
#include "Punto3.h"
using namespace std;

int main(){ //se prueba cada uno de los metodos de la clase
	complejo Z(2,4,1,3);
	Z.imprimirsuma();
	Z.imprimirresta();
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaSuma();
	Z.obtenerParteRealResta();
	Z.obtenerParteImaginariaResta();
	Z.asignarDatos(5,6,4,8);
	Z.imprimirsuma();
	Z.imprimirresta();	
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaResta();
	Z.obtenerParteRealSuma();
	Z.obtenerParteImaginariaResta();	

return 0;	
}
