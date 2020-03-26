#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>


int get_input_from_user(std::string message, int lowerbound, int upperbound);


int main(){
    srand (time(NULL));

    int number = rand() % 1001;
    int user_input;

    std::cout << "Estoy pensando un numero, puedes adivinarlo?\n";

    bool is_correct = false;
    while (!is_correct){
        user_input = get_input_from_user("Intenta adivinar el numero: ", 1, 1000);

        if(user_input < number){
            std::cout << "Demasiado pequeño, intenta con un numero mayor.\n";
        }else if(number < user_input){
            std::cout << "Demasiado grande, intenta con un numero menor.\n";
        }else{
            std::cout << "Enhorabuena, has adivinado el numero ";

            user_input = get_input_from_user("Quieres seguir jugando?(1 para si, 0 para no): ", 0, 1);

            is_correct = user_input == 1 ? false : true;
        }
    }
    

    return 0;
}


int get_input_from_user(std::string message, int lowerbound, int upperbound){
    int number;
    bool is_correct = false;

    while (!is_correct){
        std::cout << message;
        std::cin >> number;

        if(lowerbound <= number && number <= upperbound){
            is_correct = true;
        }
    }

    return number;
}
