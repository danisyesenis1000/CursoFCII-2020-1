#include <iostream>
#include <iomanip>


float get_perimeter(float length, float width){
    return 2 * (length + width);
}


float get_volume(float length, float width, float depth){
    return length * width * depth;
}


float get_area(float length, float width, float depth){
    return 2 * (length + width) * depth + length * width;
}

void user_input(){
    float width;
    float length;
    float depth;

    // get user input
    std::cout << "Ingrese el largo de la alberca: ";
    std::cin >> length;
    std::cout << '\n';

    std::cout << "Ingrese el ancho de la alberca: ";
    std::cin >> width;
    std::cout << '\n';

    std::cout << "Ingrese la profundidad promedio de la alberca: ";
    std::cin >> depth;
    std::cout << '\n';

    std::cout << "El perimetro de la alberca es: " << get_perimeter(length, width);
    std::cout << '\n';

    std::cout << "El volumen de la alberca es: " << get_volume(length, width, depth);
    std::cout << '\n';

    std::cout << "El area de superficie subterranea de la alberca es: " <<
        get_area(length, width, depth);
    std::cout << '\n';
}

void default_values(){
    float width[8] = {25, 25, 25, 25, 30, 30, 30, 30};
    float length[8] = {10, 10, 10, 10, 12, 12, 12, 12};
    float depth[8] = {5.0, 5.5, 6.0, 6.5, 5.0, 5.5, 6.0, 6.5};

    std::cout << "---------" << "--------" << "--------------" << "------------" <<
        "----------" << "---------------------------------" << '\n';

    std::cout << "| Largo |" << " Ancho |" << " Profundidad |" << " Perimetro |" <<
        " Volumen |" << " Area de superficie subterranea |" << '\n';

    std::cout << "---------" << "--------" << "--------------" << "------------" <<
        "----------" << "---------------------------------" << '\n';

    for(int i = 0; i < 8; i++){
        std::cout << '|' << std::setw(9 - 2) << length[i] << '|' << std::setw(8 - 1) << width[i] << '|' << std::setw(14 - 2) << depth[i] << "|\n";
    }

    std::cout << "---------" << "--------" << "--------------" << "------------" <<
        "----------" << "---------------------------------" << '\n';
}


int main(){
    // user_input();
    default_values();
    return 0;
}
