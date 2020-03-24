
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main()

{

	int i1;
	int i2;
	int v;
  	
	cout << "Please enter the first integer value: ";
	cin >> i1;
	cout << "Please enter the second integer value: ";
  	cin >> i2;
	if(i1<i2) //Por ejemplo X <= 10
	{
		cout << "The interval you entered is (" << i1 <<","<< i2<< ").\n";
		
        }
  
        int S=0;
	for(int j = i1; j <= i2; j = j + 1)
	{
 		S=S+j;      
	}
	cout << "Do you want the sum on the 1 screen or in 2 archive: ";
	cin >> v;
	
	if(v==1) //Por ejemplo X <= 10
	{
		cout << "The sum is:" << S << ".\n";
		
        }
	if(v==2) //Por ejemplo X <= 10
	{
		ofstream myfile;
  		myfile.open ("example.txt");
  		myfile << "The sum is:" << S << ".\n";
  		myfile.close();
		
        }


 

	

return 0;

}
