#include <iostream>
#include <string>

void replace(std::string &text, std::string source, std::string target, bool more_than_one=true);
void exercise10();
void exercise11();
void exercise12();


int main(){
    int option;
    while(true){
        std::cout << "Que punto desea ver?(0 para 10, 1 para 11, 2 para 12 y 3 para salir): ";
        std::cin >> option;

        std::cin.ignore();

        std::cout << "-----------------------------------------------------------------------\n";
        switch (option){
            case 0:
                exercise10();
                break;
            case 1:
                exercise11();
                break;
            case 2:
                exercise12();
                break;
            case 3:
                return 0;
                break;
            default:
                break;
        }
        std::cout << "-----------------------------------------------------------------------\n";
    }
}


void get_user_input(std::string message, std::string &user_input){
    std::cout << message;

    std::getline(std::cin, user_input);
}


void replace(std::string &text, std::string source, std::string target, bool more_than_one){
    int position = text.find(source);

    while(position != std::string::npos){
        text.replace(position, source.length(), target);

        position = text.find(source);

        if(!more_than_one){
            break;
        }
    }
}


void exercise10(){
    std::string user_message;

    get_user_input("Ingresa una frase por favor: ", user_message);

    replace(user_message, "e", "x");

    std::cout << "Despues de realizar el reemplazo, se obtuvo: ";
    std::cout << user_message << std::endl;
}


void exercise11(){
    std::string user_message;
    std::string source;
    std::string target;

    get_user_input("Ingresa una frase por favor: ", user_message);
    get_user_input("Ingresa la secuencia de caracteres que quieres reemplazar: ", source);
    get_user_input("Ingresa la secuencia de caracteres por la que quieres reemplazar: ", target);

    replace(user_message, source, target, false);

    std::cout << "Despues de realizar el reemplazo, se obtuvo: ";
    std::cout << user_message << std::endl;
}


void exercise12(){
    std::string user_message;
    std::string source;
    std::string target;

    get_user_input("Ingresa una frase por favor: ", user_message);
    get_user_input("Ingresa la secuencia de caracteres que quieres reemplazar: ", source);
    get_user_input("Ingresa la secuencia de caracteres por la que quieres reemplazar: ", target);

    replace(user_message, source, target);

    std::cout << "Despues de realizar el reemplazo, se obtuvo: ";
    std::cout << user_message << std::endl;
}
