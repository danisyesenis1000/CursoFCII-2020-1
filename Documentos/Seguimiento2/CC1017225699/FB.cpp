#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    cout << "ingrese cuantos terminos quiere ver en pantalla:" << endl;
    int N;
    cin >> N;

    //arrays
    int SFB[N]={0};
    SFB[0]=0;
    SFB[1]=1;
    int i=2;

    vector<int> VFB;
    VFB.push_back(0);
    VFB.push_back(1);
  
    for (int k = 2; k <= N; k++)
    { 
        VFB.push_back(VFB.at(k-1)+VFB.at(k-2)); 

    }
       
    for(int j=0;j<N;j++)
    {
        cout<<VFB.at(j)<<",";

    }
    cout<<"\n";
    while (i<N)
    {
	    SFB[i] = SFB[i-1] + SFB[i-2];
        i=i+1;	
    }
    
    for(int j=0;j<N;j++)
    {
        cout<<SFB[j]<<",";

    }
    cout<<"\n";
                  
   
    return 0;
}





