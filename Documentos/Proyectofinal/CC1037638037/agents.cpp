#include <random>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <cerrno>

#include <vector>
#include <typeinfo>

#include <math.h> 
#include <algorithm> 

using namespace std;
bool fileExists(const string filename){
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
        return true;
    return false;}
    
string check_name(string name,int n){
    string s=name+to_string(n);
    if (fileExists(s))
        return check_name(name,n+1);
    else
        return s;}


random_device dev;
int n_rand(int n1,int n2){

	
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> r(n1,n2-1);
	return r(rng);


}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

float dist(float ax,float ay,float bx,float by){

   		float dx=abs(ax-bx);
   		float dy =abs(ay-by);
   		return sqrt(pow(dx, 2.0) +pow(dy, 2.0));


   		}




class Object{
   public:
   int id;
   int x,y;
   vector <int> hist_x;
   vector <int> hist_y;
   int Lx,Ly;

   Object(int _Lx,int _Ly){
  	Lx=_Lx;
  	Ly=_Ly;

   	x=n_rand(0,Lx);
   	y=n_rand(0,Ly);
   }

   	void save_hist_pos(){
   		hist_x.push_back(x); 
   		hist_y.push_back(y); 

   }

   
			 
};

class Resource: public Object{
   public:
   	int maxc=1000;
   	int c1=n_rand(500,maxc);
   	int c2=n_rand(500,maxc);
   	vector <int> hist_c1;
   	vector <int> hist_c2;

   	 Resource(int _Lx, int _Ly) : Object(_Lx,_Ly){}

   	void save_hist(){
   		save_hist_pos();
   		hist_c1.push_back(c1); 
   		hist_c2.push_back(c2); 

   	}
   	void reset(){
   		x=n_rand(0,Lx);
   		y=n_rand(0,Ly);
		c1=n_rand(500,maxc);
		c2=n_rand(500,maxc);


   	}
};


     
class Agent: public Object{
	public:
		int id;

   		int vision=30;
   		int maxw=1000;
   		float w1=n_rand(50,maxw);
   		float w2=n_rand(50,maxw);
  		float m1=0.5;
   		float m2=0.5;

   		vector <int> hist_w1;
   		vector <int> hist_w2;
   		vector <float> hist_wellfare;

   		Agent(int _Lx, int _Ly);
   		float get_welfare(float p1,float p2);
		void move_tow(float tx,float ty);
		bool m_allow(int tx,int ty);
		Resource* search_res();
		void move();
		void save_hist();
		void reset();

   		};


int Na=0;
vector <Agent> Agents_list;
vector <Resource> Resources_list;
vector <float> prices_list;




 Agent::Agent(int _Lx, int _Ly) : Object(_Lx,_Ly){
   			id=Na;
   			Na=Na+1;
   		}

float  Agent::get_welfare(float p1,float p2){

   			float mt=m1+m1;
   			return pow(p1,m1/mt)*pow(p2,m2/mt);}



   	void Agent::move_tow(float tx,float ty){
   		int dx=sgn(tx-x);
   		int dy=sgn(ty-y);
   		
   		if(dx==0)
   			if(m_allow(x,y+dy))
   				y=y+dy;
   		if(dy==0)
   			if(m_allow(x+dx,y))
   				x=x+dx;
   		if(dx!=0 && dy!=0)
   			if(n_rand(0,1)==0)
   				if(m_allow(x+dx,y))
   					x=x+dx;
   			else
   				if(m_allow(x,y+dy))
   					y=y+dy;
   				
   				



   	}

   	bool Agent::m_allow(int tx,int ty){
   		return 1;
   		
   		for(int n=0;n<Agents_list.size();n++)
   			if(Agents_list[n].x==tx && Agents_list[n].y==ty)

   				return 0;
   			

   		for(int n=0;n<Resources_list.size();n++)
   			if(Resources_list[n].x==tx && Resources_list[n].y==ty)

   				return 0;
   			


   		return 1;




   	}

   	Resource* Agent::search_res(){

   		vector <float> u_list;
   		vector <Resource*> u_re;
   		
   		
   		for(int n=0;n<Resources_list.size();n++){
   			
   				Resource* re=&Resources_list[n];
   				float d=dist(x,y,re->x,re->y);
   				if(d<vision){
   					int b=50;
   					int r1=n_rand(-b,b);
   					int r2=n_rand(-b,b);
   					
   					float u=get_welfare(w1+re->c1-4*d+r1,w2+re->c2-4*d+r2);
   					
   					if(isnan(u)==0){
   						u_list.push_back(u); 
   						u_re.push_back(re); }

   				}
   		}


   		

   		if(u_list.size()!=0){
   			int maxIndex = max_element(u_list.begin(),u_list.end()) - u_list.begin();
   			return u_re[maxIndex];
   		}

   		else
   			return nullptr;



   	}
   	void Agent::reset(){
   		x=n_rand(0,Lx);
   		y=n_rand(0,Ly);
		w1=n_rand(50,maxw);
		w2=n_rand(50,maxw);
   	}

   	void Agent::move(){

   		
   		Resource* re=search_res();
   		
   		if(re!=nullptr){

   			float rx=re->x;
   			float ry=re->y;
 
   			float d= dist(rx,ry,x,y);
		

			if(d>1)
				
   				move_tow(rx,ry);
			
   			
   			else{
			

				if(re->c1>0){
					if(re->c1==1){
						re->c1=re->c1-1;
						w1=w1+1;

					}
					else{
						re->c1=re->c1-4;
						w1=w1+4;}
				}

				if(re->c2>0){
					if(re->c2==1){
						re->c2=re->c2-1;
						w2=w2+1;}
					else{
						re->c2=re->c2-4;
						w2=w2+4;
					}
				}
			}

			if(re->c1 <= 0 && re->c2 <= 0)
				re->reset();

   		}

   		else
   			switch(n_rand(0,0)) {
   				case 0:
   				x=x+1;
   				break;
   				case 1:
   				x=x-1;
   				break;
   				case 2:
   				y=y+1;
   				break;
   				case 3:
   				y=y-1;
   				break;
   				
					}



		w1=w1-m1;
		w2=w2-m2;

		if(w1 <= 0 || w2 <= 0)	
			reset();

			
	

	

	}

	void Agent::save_hist(){
   		save_hist_pos();
   		hist_w1.push_back(w1); 
   		hist_w2.push_back(w2); 
   		hist_wellfare.push_back(get_welfare(w1,w2));

   	}
     




void trade(int step){
	float sum;
	int N_trades=0;

	for(int i=0;i<Agents_list.size();i++)
		for(int j=i;j<Agents_list.size();j++)
				if(i!=j){

   			
   				Agent* A=&Agents_list[i];
   				Agent* B=&Agents_list[j];

   				vector <float> u_list;
   				vector <Agent*> u_ag;

   				float d=dist(A->x,A->y,B->x,B->y);

   				if(d<A->vision){


   					float MRSa=A->m1*A->w2/(A->m2*A->w1);
   					float MRSb=B->m1*B->w2/(B->m2*B->w1);
   					float price=sqrt(MRSa*MRSb);
   					int s=sgn(MRSa-MRSb);
   					float ua;
   					float ub;



   					if(price>1){
   						float nw1a=A->w1+s*price;
   						float nw1b=B->w1-s*price;


   						float nw2a=A->w2-s;
   						float nw2b=B->w2+s;

   						ua=A->get_welfare(nw1a-2*d,nw2a-2*d);
   						ub=B->get_welfare(nw1b-2*d,nw2b-2*d);
						}

					else{
   						float nw1a=A->w1+s/price;
   						float nw1b=B->w1-s/price;


   						float nw2a=A->w2-s;
   						float nw2b=B->w2+s;

   						ua=A->get_welfare(nw1a-2*d,nw2a-2*d);
   						ub=B->get_welfare(nw1b-2*d,nw2b-2*d);
						}

   					
   					
   					if(isnan(ua)==0 && isnan(ub)==0){
   							u_list.push_back(ua*ub); 
   							u_ag.push_back(B); 
   					}
   				}

   			

			if(u_list.size()!=0){

   				int maxIndex = max_element(u_list.begin(),u_list.end()) - u_list.begin();
   				Agent* re=u_ag[maxIndex];
   				float d=dist(A->x,A->y,B->x,B->y);
			

			if(d>=1){
				A->move_tow(B->x,B->y);
				B->move_tow(A->x,A->y);
			}
			
   			
   			else{

   				float MRSa=A->m1*A->w2/(A->m2*A->w1);
   				float MRSb=B->m1*B->w2/(B->m2*B->w1);
   				//cout<<"MRSa:"<<MRSa<<endl;
   				//cout<<"MRSb:"<<MRSb<<endl;

   				float price=sqrt(MRSa*MRSb);
   				int s=sgn(MRSa-MRSb);

   				//cout<<"price:"<<price<<"  s:"<<s<<endl;
   				
   				if(price>1){
   					
   					A->w1=A->w1+s*price;
   					B->w1=B->w1-s*price;

   					A->w2=A->w2-s;
   					B->w2=B->w2+s;
   				}
   				else{

   					A->w1=A->w1+s/price;
   					B->w1=B->w1-s/price;

   					A->w2=A->w2-s;
   					B->w2=B->w2+s;
   					}
   				sum=sum+price;
   				N_trades=N_trades+1;
				
			}

   				}
   		}
   	prices_list.push_back(sum/N_trades);
   	

}



int main(){
	
	
	int N_steps=50000;
	int N_agents=10;
	int N_resources=40;
	int FPS=5;
	int jf=40;
	int Lx=100;
	int Ly=100;

	string main_folder=check_name("asim_out/asim_",0);
	mkdir(main_folder.c_str(),0777);
	cout<<main_folder<<endl;
	std::ofstream fS((main_folder+"/prm.txt").c_str());
	fS << N_steps<< endl<< N_agents<<endl<<N_resources<<endl<<FPS<<endl<<Lx<<endl<<Ly<<endl<<jf<<endl;
	


	for (int n=0;n<N_agents;n++){
		Agent a(Lx,Ly);
		Agents_list.push_back(a); 
	}
	
	
	for (int n=0;n<N_resources;n++){
		Resource r(Lx,Ly);
		Resources_list.push_back(r); 

	}
	


	
	for(int step=0;step<N_steps;step++){

		cout<<endl<<endl<<"step:"<<step<<endl;
		trade(step);


		for (int i=0;i<N_agents;i++)
			Agents_list[i].move();


		for (int i=0;i<N_agents;i++)
			Agents_list[i].save_hist();

		for (int i=0;i<Resources_list.size();i++)
			Resources_list[i].save_hist();

	}
	
	
	

	// std::ofstream::out);


	ofstream fS1((main_folder+"/agents_dat.txt").c_str());
	ofstream fS2((main_folder+"/resources_dat.txt").c_str());
	ofstream fS3((main_folder+"/prices_dat.txt").c_str());
	for (int n=0;n<N_steps;n++){

	for (int i=0;i<N_agents;i++){
		fS1 << Agents_list[i].hist_x[n] <<" "<< Agents_list[i].hist_y[n]<<" ";
		fS1 << Agents_list[i].hist_w1[n] <<" "<< Agents_list[i].hist_w2[n] << " ";
		fS1 << Agents_list[i].hist_wellfare[n] <<endl;	
	}
	
	for (int i=0;i<Resources_list.size();i++){
		fS2 << Resources_list[i].hist_x[n] <<" "<< Resources_list[i].hist_y[n]<<" ";
		fS2 << Resources_list[i].hist_c1[n] <<" "<< Resources_list[i].hist_c2[n] << endl;}
	}

	for (int i=0;i<prices_list.size();i++)
		fS3 << prices_list[i] << endl;
	
	
	fS1.close();
	fS2.close();
	fS3.close();
	
	//system(("python3 p.py "+main_folder).c_str());
}