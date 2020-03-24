#include <iostream>
#include <ctime>
#include <stdlib.h>

/*
 * punto1.cpp
 * 
 * Game in which the player guesses a number
 * between 1 and 1000.
 * 
 * Carolina Herrera S.
 * 
 * */


using namespace std;

void game();

int main(){
    int t = 1;
    
    srand(time(NULL));
    
    do { 
        game();
        cout << endl;
        cout << "Do you want to play again? Enter 1 for yes, any other number otherwise: ";
        cin >> t;
        } while ( t == 1 );
    
    return 0;
}


void game(){
    int number;
    int guess=0;
    
    number = 1+rand()%1000;
    
    cout << "Welcome to the game. Guess a number between 1 and 1000." << endl;
    
    // Iterates as long as number is different from guess
    while ( number != guess ){
        cout << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        
        // Gives hint if guess is greater or less than the number
        if ( guess > number ){
            cout << "Wrong. Your guess is greater than the number" << endl;
        }
        
        else if ( guess < number ){
            cout << "Wrong. Your guess is less than the number" << endl;
        }
    }
    
    cout << "You guessed" << endl;
}
