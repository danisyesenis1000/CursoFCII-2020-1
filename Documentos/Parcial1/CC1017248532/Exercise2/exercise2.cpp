#include <iostream>
#include <iomanip>

using namespace std;

void CheckIfItsPerfect(int); //Check if a number is perfect integer

int main(){

  cout << "The numbers that will be printed are perfect integers." << endl;
  
  for (int j = 1; j <= 10000; j++){ 
    
    CheckIfItsPerfect(j);
  }

  
  return 0;
}

void CheckIfItsPerfect(int n){

  int total = 0; //For storing the sume of all its divisors

  for (int i = 1; i < n; i++){

    if (n%i == 0){ //If it's a divisor of n
      total += i; //sume it to the total
    }
  }

  if (total == n){ //if this happens, then the integer is perfect
    cout << n << endl; //Print the number
  }
}
