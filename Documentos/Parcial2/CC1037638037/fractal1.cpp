#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <math.h> 

using namespace std;

#define w 1000
#define h 1000


class fractal{

	
	int red[w][h];



	float prm=0;


   void gen(){

   	float za,zb;
  	for (int a=0;a<w;a++)
		for (int b=0;b<h;b++){
			
			za=a/float(w);
			zb=b/float(h);

			int n=0;
			int n_max=100;
			float z_max=10;

			while(n<n_max && sqrt(za*za+zb*zb)<z_max){
				float z2a=za*za-zb*zb;
				float z2b=2*za*zb;
				za=z2a-0.1;
				zb=z2b+0.65;

				//za=z2a+0.7885*cos(prm);
				//zb=z2b+0.7885*sin(prm);

				n=n+1;	
			}

			red[a][b]=n*255/n_max;

		}


   }
   void plot(){

   	FILE *f;
	unsigned char *img = NULL;
	int filesize = 54 + 3*w*h; 

	img = (unsigned char *)malloc(3*w*h);
	memset(img,0,3*w*h);
	int x,y,r,g,b;


		for(int i=0; i<w; i++)
		{
		    for(int j=0; j<h; j++)
		    {
		        x=i; y=(h-1)-j;
		        r = red[i][j];
		        g = 0;
		        b = 0;
		        if (r > 255) r=255;
		        if (g > 255) g=255;
		        if (b > 255) b=255;
		        img[(x+y*w)*3+2] = (unsigned char)(r);
		        img[(x+y*w)*3+1] = (unsigned char)(g);
		        img[(x+y*w)*3+0] = (unsigned char)(b);
		    }
		}
		
		
		unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
		unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
		unsigned char bmppad[3] = {0,0,0};
		
		bmpfileheader[ 2] = (unsigned char)(filesize    );
		bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
		bmpfileheader[ 4] = (unsigned char)(filesize>>16);
		bmpfileheader[ 5] = (unsigned char)(filesize>>24);
		
		bmpinfoheader[ 4] = (unsigned char)(       w    );
		bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
		bmpinfoheader[ 6] = (unsigned char)(       w>>16);
		bmpinfoheader[ 7] = (unsigned char)(       w>>24);
		bmpinfoheader[ 8] = (unsigned char)(       h    );
		bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
		bmpinfoheader[10] = (unsigned char)(       h>>16);
		bmpinfoheader[11] = (unsigned char)(       h>>24);
		
		f = fopen("img1.bmp","wb");
		fwrite(bmpfileheader,1,14,f);
		fwrite(bmpinfoheader,1,40,f);
		for(int i=0; i<h; i++)
		{
		    fwrite(img+(w*(h-i-1)*3),3,w,f);
		    fwrite(bmppad,1,(4-(w*3)%4)%4,f);
		}
		
		
		free(img);
		fclose(f);


   }
public:
   void run(){

   	gen();
   	
   	plot();
   	
   }

   	

   
			 
};



int main(){


	fractal* f= new fractal();
	f->run();




}