#include "clases.cpp"
#include <iostream>


using namespace std;


int main(){

Expiral e1(1, 1,1,1,0.1,10,5,3.14);//z0=1,vz=1,R=1,w=1,alf=3.14
cout<<"x(t=2):"<<e1.xpos(2)<<endl;//1*cos(1*2+3.14)
cout<<"y(t=2):"<<e1.ypos(2)<<endl;//1*sin(1*2+3.14)
cout<<"z(t=2):"<<e1.zpos(2)<<endl;//1+1*2
}