#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <math.h> 
#include <algorithm> 
using namespace std;

float f(float x, float y,float yp){
	return -(yp*yp)-y+log(x);
}

float fy(float x,float y,float yp){
	return -1;
}

float fyp(float x, float y,float yp){
	return -2*y;
}

int main(){

float al=1;
float bl=2;
float alfa=0;
float beta=log(2);
float h=0.01;
int N=((bl-al)/h)-1;
float tol=pow(10,-6);
int M=500;

std::vector<float> w(N+2, 0);


w[0]=alfa;
w[N+1]=beta;


for(int i=1;i<=N;i++)
	w[i]=alfa+i*((beta-alfa)/(bl-al))*h;




int k=1;
while(k<=M){
	
	std::vector<float> a(N+1, 0);
	std::vector<float> b(N+1, 0);
	std::vector<float> c(N+1, 0);
	std::vector<float> d(N+1, 0);
	
	
	float x=al+h;
	float t=(w[2]-alfa)/(2*h);
	a[1]=2+h*h*fy(x,w[1],t);
	b[1]=-1+(h/2)*fyp(x,w[1],t);
	d[1]=-(2*w[1]-w[2]-alfa+h*h*f(x,w[1],t));
	
	
	for(int i=2;i<=N-1;i++){
		x=al+i*h;
		t=(w[i+1]-w[i-1])/(2*h);
		a[i]=2+h*h*fy(x,w[i],t);
		b[i]=-1+(h/2)*fyp(x,w[i],t);
		c[i]=-1-(h/2)*fyp(x,w[i],t);
		d[i]=-(2*w[i]-w[i+1]-w[i-1]+h*h*f(x,w[i],t));
	
	}
	x=bl-h;
	t=(beta-w[N-1])/(2*h);
	a[N]=2+h*h*fy(x,w[N],t);
	c[N]=-1-(h/2)*fyp(x,w[N],t);
	d[N]=-(2*w[N]-w[N-1]-beta+h*h*f(x,w[N],t));


	
	std::vector<float> l(N+1, 0);
	std::vector<float> u(N+1, 0);
	std::vector<float> v(N+1, 0);
	std::vector<float> z(N+1, 0);
	
	l[1]=a[1];
	u[1]=b[1]/a[1];
	z[1]=d[1]/l[1];
	
	for(int i=2;i<=N-1;i++){
		l[i]=a[i]-c[i]*u[i-1];
		u[i]=b[i]/l[i];
		z[i]=(d[i]-c[i]*z[i-1])/l[i];
	}
	l[N]=a[N]-c[N]*u[N-1];
	z[N]=(d[N]-c[N]*z[N-1])/l[N];

	v[N]=z[N];
	w[N]=w[N]+v[N];

	for(int i=N-1;i>=1;i--){
		v[i]=z[i]-u[i]*v[i];
		w[i]=w[i]+v[i];

	}
	float s=0;

	for(int i=0;i<=N+1;i++)
		s=s+v[i]*v[i];

	
	if(sqrt(s)<tol){
		for(int i=0;i<=N+1;i++)
			cout<<w[i]<<endl;
		
		break;
	}

	else{
		k=k+1;
	}

}
cout<<"max_iter"<<endl;




float max = *max_element(w.begin(), w.end());
int wid=N;

int he=100;
vector<vector<int>> red(wid, vector<int>(he, 0));

for(int i=0;i<N;i++){
	int j=w[i]*he/max;
	red[i][j]=255;


}

FILE *f;
unsigned char *img = NULL;
int filesize = 54 + 3*wid*he; 

img = (unsigned char *)malloc(3*wid*he);
memset(img,0,3*wid*he);
int xc,yc,r,g,b;

for(int i=0; i<wid; i++)
{
    for(int j=0; j<he; j++)
    {
        xc=i; yc=(he-1)-j;
        r = red[i][j];
        g = 0;
        b =0;
        if (r > 255) r=255;
        if (g > 255) g=255;
        if (b > 255) b=255;
        img[(xc+yc*wid)*3+2] = (unsigned char)(r);
        img[(xc+yc*wid)*3+1] = (unsigned char)(g);
        img[(xc+yc*wid)*3+0] = (unsigned char)(b);
    }
}


unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
unsigned char bmppad[3] = {0,0,0};

bmpfileheader[ 2] = (unsigned char)(filesize    );
bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
bmpfileheader[ 4] = (unsigned char)(filesize>>16);
bmpfileheader[ 5] = (unsigned char)(filesize>>24);

bmpinfoheader[ 4] = (unsigned char)(       wid    );
bmpinfoheader[ 5] = (unsigned char)(       wid>> 8);
bmpinfoheader[ 6] = (unsigned char)(       wid>>16);
bmpinfoheader[ 7] = (unsigned char)(       wid>>24);
bmpinfoheader[ 8] = (unsigned char)(       he    );
bmpinfoheader[ 9] = (unsigned char)(       he>> 8);
bmpinfoheader[10] = (unsigned char)(       he>>16);
bmpinfoheader[11] = (unsigned char)(       he>>24);

f = fopen("img3.bmp","wb");
fwrite(bmpfileheader,1,14,f);
fwrite(bmpinfoheader,1,40,f);
for(int i=0; i<he; i++)
{
    fwrite(img+(wid*(he-i-1)*3),3,wid,f);
    fwrite(bmppad,1,(4-(wid*3)%4)%4,f);
}


free(img);
fclose(f);


}