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

   	int gen(vector<vector<int>> &vec){
		int a=vec.size();
		int b=vec[0].size();
		int ac=a/3;
		int bc=b/3;
		if(a<10 && b<10)
			return 0;
	
		
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				vector<std::vector<int>> sec(ac, std::vector<int>(bc, 0));
	
				gen(sec);
	
				for(int x=0;x<ac;x++)
					for(int y=0;y<bc;y++)
						vec[i*ac+x][j*bc+y]=sec[x][y];
			}
	
	
		for (int x=ac;x<2*ac;x++)
			for (int y=bc;y<2*bc;y++)
				vec[x][y]=255;
	
	
	
		}
   void plot(vector<vector<int>> &red){

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
		
		f = fopen("img2.bmp","wb");
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

		vector<vector<int>> red(w, vector<int>(h));
		gen(red);
   		plot(red);
   		
   }

   	

   
			 
};



int main(){


	fractal* f= new fractal();
	f->run();

}






