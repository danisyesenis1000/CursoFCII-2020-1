#include <iostream> 
#include <cstdlib>
#include <vector>
#include <unistd.h>


#include "jdlv.h"
using namespace std;

int main(){
    srand(time(NULL));
    jdlv juego(50);

    while(1){
        juego.dibujar();
        usleep(255000);
        system("clear");
        juego.ciclo();
    }
}
