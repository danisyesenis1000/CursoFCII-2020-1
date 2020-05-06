#include "clases.h"
#include <math.h>
using namespace std;

Reinas::Reinas(): T { 0 }{}

long Reinas::mod(long a, long b){
    return (a%b+b)%b; }

void Reinas::plot(){


	for(int i=0;i<L;i++){
		for(int j=0;j<L;j++){
			if(T[i][j]==0)
				cout<<". ";
			if(T[i][j]==1)
				cout<<"o ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool Reinas::check(int i,int j){
	
	for(int n=1;n<L+1;n++)
		if(T[mod(i+n,L)][j]==1)
			return 0;

	for(int n=1;n<L+1;n++)
		if(T[i][mod(j+n,L)]==1)
			return 0;


	for(int n=-8;n<8;n++){
		int a=i+n;
		int b=j+n;
		if(a>=0 && a<8 && b>=0 && b<8)
			if(T[a][b]==1)
				return 0;
		}
	
	for(int n=-8;n<8;n++){
		int a=i-n;
		int b=j+n;
		if(a>=0 && a<8 && b>=0 && b<8)
			if(T[a][b]==1)
				return 0;
		}
	return 1;

}


int Reinas::run(int n){
	//plot();
	//getchar();

	if(n==8){
		cout<<"Solucion:"<<endl;
		plot();
		exit(0);
	}

	for(int i=0;i<L;i++)
		for(int j=0;j<L;j++)
			if(check(i,j)){
				T[i][j]=1;
				n=n+1;
				if(run(n)==0){
					T[i][j]=0;
					n=n-1;
				}
			}
	return 0;	
}