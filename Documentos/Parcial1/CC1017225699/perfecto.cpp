#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <iostream>
using namespace std;

int main (){

    for(int i=1; i<=10000;i++ ){
        int S=0;
        
        for(int j=1; j<i;j++){
        
            if(i%j==0){
                
                S=S+j;
            }
        }
        
        if(i==S){
            cout<<"\nEl numero "<< i <<" es perfecto y sus divisores son: \n";
            for(int j=1; j<i;j++){
        
                if(i%j==0){
                    cout<<j <<", ";

                }            
            }
        }
        
    }

    return 0;
}
