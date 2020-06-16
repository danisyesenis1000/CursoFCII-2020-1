#include <iostream> 
#include <cstdlib>
#include <vector>
#include <unistd.h>

#include "jdlv.h"
using namespace std;

jdlv::jdlv(int N){
    setdim(N);
    setmapa(); 
}

void jdlv::setdim(int N){
    dim = N;
}

void jdlv::setmapa(){
    mapa.resize(dim);

    for(int i = 0; i < mapa.size(); i++){
        mapa[i].resize(dim);
    }

    for(int f = 0; f < dim; f++){
        for(int c = 0; c < dim; c++){
            mapa[f][c] = rand() % 3;
        }
    }
}

void jdlv::analizarVecinos(int posf, int posc){
    vecinos1 = 0;
    vecinos2 = 0;

    for(int m =- 1; m <= 1; m++){
        for(int n =- 1; n <= 1; n++){
            if(m != 0 and n != 0){    
                if(mapa[(posf + dim - m) % dim][(posc + dim - n) % dim] == 1){
                    vecinos1++;
                } else if(mapa[(posf + dim -m) % dim][(posc + dim - n) % dim] == 2){
                    vecinos2++;
                }
            }
        }
    }
}


void jdlv::ciclo(){
    vector<vector<int> > nueva_conf = mapa;
  
    for (int f = 0; f < dim; f++){
        for(int c = 0; c < dim; c++){
	        analizarVecinos(f, c);
            //cout << vecinos1 << " " << vecinos2 << endl;
	        if(mapa[f][c] == 0){
                if(vecinos1 > vecinos2){
	                if(vecinos1 == 3 && vecinos2 == 0 || vecinos1 == 2 && vecinos2 == 1){	            
                        nueva_conf[f][c] = 1;
                    }	               
                }

                if(vecinos2 > vecinos1){
                    if(vecinos2 == 3 && vecinos1 == 0 || vecinos2 == 2 && vecinos1 == 1 ){	            
                        nueva_conf[f][c] = 2;
                    }	               
                } else{
		            nueva_conf[f][c] = 0;
                }
            }

            if (mapa[f][c] == 1){
                if(vecinos1 + vecinos2 >= 4){		
                    nueva_conf[f][c] = 0;
                } else if(vecinos1 > vecinos2 ){	    
                    nueva_conf[f][c] = 1;
                } else if(vecinos2 > vecinos1 && vecinos2>1){	    
                    nueva_conf[f][c] = 2;
                } else {		
                    nueva_conf[f][c] = 0;
                }
            }
                
            if (mapa[f][c] == 2){
                if(vecinos1 + vecinos2 >= 4){		
                    nueva_conf[f][c] = 0;
                } else if(vecinos1 > vecinos2 && vecinos1>1){	    
                    nueva_conf[f][c] = 1;
                } else if(vecinos2 > vecinos1 && vecinos2>1){	    
                    nueva_conf[f][c] = 2;
                } else{		
                    nueva_conf[f][c] = 0;
                }
            }
        }
    }

    mapa = nueva_conf;
}

void jdlv::dibujar(){
    for(int f = 0; f < dim; f++){
        for(int c = 0; c < dim; c++){
	        if(mapa[f][c] == 1)
	            cout << "o ";
	        else if(mapa[f][c] == 2)
	            cout << "x ";
	        else if(mapa[f][c] == 0)
	            cout << "  ";
        }

        cout << "\n";
    }
}
