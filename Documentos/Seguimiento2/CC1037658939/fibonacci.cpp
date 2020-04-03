#include <iostream>
#include <vector>

using namespace std;

/*
 * fibonacci.cpp
 * 
 * Prints first N Fibonacci numbers using two
 * different functions.
 * 
 * Carolina Herrera S.
 * 
 * */


int fibonacci_array( int );
int fibonacci_vector( int );

int main() {
    int fib_num, N=12;
    
    cout << "Sucesión de Fibonacci con arreglos: " << endl;
    
    for ( int n=0; n<=N; n++) {
        fib_num = fibonacci_array( n );
        cout << fib_num << ", ";
    }
    
    cout << "..." << endl;
    cout << endl;
    cout << "Sucesión de Fibonacci con vectores: " << endl;
    
    for ( int n=0; n<=N; n++) {
        fib_num = fibonacci_vector( n );
        cout << fib_num << ", ";
    }
    
    cout << "..." << endl;
    
    return 0;
}


// Find nth fibonacci number using arrays
int fibonacci_array( int n ) {
    int fib[] = {0, 1};
    int next_fib;
    
    if ( n==0 or n==1 ) return fib[n];
    
    else {
        for ( int i=2; i<=n; i++ ) {
            // Find ith fibonacci number
            next_fib = fib[0] + fib[1];
            
            // Replace the (i-2)th fib number with the (i-1)th and 
            // put the ith at the end
            fib[0] = fib[1];
            fib[1] = next_fib;
        }
    }
    
    return fib[1];
}


// Find nth fibonacci number using vectors
int fibonacci_vector( int n ) {
    vector< int > fib;
    
    fib.push_back( 0 );
    fib.push_back( 1 );
    
    if ( n==0 or n==1 ) return fib[n];
    
    else {
        for ( int i=2; i<=n; i++ ) {
            // Push ith fib number at the end and erase the (i-2)th
            fib.push_back(fib[0]+fib[1]);
            fib.erase( fib.begin() );
        }
    }
    
    return fib.back();
}

