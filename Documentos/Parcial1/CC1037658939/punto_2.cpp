#include <iostream>

/*
 * punto_2.cpp
 * 
 * Prints all perfect numbers between 1 and 10000
 * and their divisors.
 * 
 * Carolina Herrera S.
 * 
 * */


using namespace std;

bool perfecto( int );

int main(){
    
    for ( int number=6; number<=10000; number++ ){
        
        // If number is a perfect number, print divisors
        if ( perfecto( number ) ){
            
            cout << number << " = 1";
            
            for ( int i=2; i<=number/2; i++ ){
                
                if ( number%i == 0 ) cout << " + " << i;
            }
        
        cout << endl;
        cout << endl;
        }
    }
    return 0;
}


bool perfecto( int numero ){
    int sum_div = 1;
    
    // If div divides numero, we add it to the sum of all divisors
    for ( int div=2; div<=numero/2; div++ ){
        
        if ( numero%div == 0 ) sum_div += div;
    }
    
    // If the sum of all divisors is equal to numero, it is a perfect number, returns true
    if ( numero == sum_div ) return true;
    
    // Otherwise, returns false
    return false;
}
