#include <iostream>
#include <iomanip>


/*
For the sake of modularity, the calculation of geometrical measurements
are wrapped into functions, then if the formulas for such calculations
change, only will be necessary to change one line
*/


float get_perimeter(float length, float width){
    return 2 * (length + width);
}


float get_volume(float length, float width, float depth){
    return length * width * depth;
}


float get_area(float length, float width, float depth){
    return 2 * (length + width) * depth + length * width;
}


/*
For make test the user input is used
*/
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


void print_horizontal_line(){
    std::cout << "---------" << "--------" << "--------------" << "------------" <<
        "----------" << "---------------------------------" << '\n';
}

void default_values(){
    float width[8] = {25, 25, 25, 25, 30, 30, 30, 30};
    float length[8] = {10, 10, 10, 10, 12, 12, 12, 12};
    float depth[8] = {5.0, 5.5, 6.0, 6.5, 5.0, 5.5, 6.0, 6.5};

    print_horizontal_line();

    std::cout << "| Largo |" << " Ancho |" << " Profundidad |" << " Perimetro |" <<
        " Volumen |" << " Area de superficie subterranea |" << '\n';

    print_horizontal_line();

    for(int i = 0; i < 8; i++){
        std::cout << "|" << std::setw(9 - 4) << length[i] <<
            "  |" << std::setw(8 - 3) << width[i] <<
            "  |" << std::setw(14 - 3) << depth[i] <<
            "  |" << std::setw(12 - 3) << get_perimeter(length[i], width[i]) <<
            "  |" << std::setw(10 - 3) << get_volume(length[i], width[i], depth[i]) <<
            "  |" << std::setw(34 - 4) << get_area(length[i], width[i], depth[i]) <<
            "  |\n";
    }

    print_horizontal_line();
}


int main(){
    int option;

    std::cout << "Si desea los calculos para valores por defecto ingrese 1"
        " y 0 para probar valores propios: ";
    std::cin >> option;
    std::cout << '\n';

    if(option == 0){
        user_input();
    }else{
        default_values();
    }
    return 0;
}
