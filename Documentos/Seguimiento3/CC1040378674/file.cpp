#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


void create_file(std::ofstream &ofs);
void show_payroll_list(std::ifstream &ifs);


int main(){
    std::ofstream ofs("payroll.txt", std::ofstream::out);

    if(ofs.fail()){
        std::cout << "Failed to open the file: payroll.txt";
        exit(1);
    }

    create_file(ofs);

    ofs.close();

    std::ifstream ifs("payroll.txt", std::ifstream::in);

    if(ifs.fail()){
        std::cout << "Failed to open the file: payroll.txt";
        exit(1);
    }

    show_payroll_list(ifs);

    ifs.close();

    return 0;
}


void create_file(std::ofstream &ofs){
    ofs << "B Caldwell" << ' ' << "555-88-2222" << ' '  << 7.32 << ' '  << 37 << '\n';
    ofs << "D Memcheck" << ' '  << "555-88-4444" << ' '  << 8.32 << ' '  << 40 << '\n';
    ofs << "R Potter" << ' '  << "555-88-6666" << ' '  << 6.54 << ' '  << 40 << '\n';
    ofs << "W Rosen" << ' '  << "555-99-8888" << ' '  << 9.80 << ' '  << 35 << '\n';
}


void show_payroll_list(std::ifstream &ifs){
    std::string name;
    std::string lastname;
    std::string social_security_number;
    float hourly_rate;
    float hours_worked;

    std::cout << std::setw(4) << "----------------"
              << std::setw(22) << "-------------------------"
              << std::setw(10) << "------------" << '\n';

    std::cout << std::setw(4) << "|     Name     |"
              << std::setw(22) << " Social Security Number |"
              << std::setw(10) << " Gross Pay |" << '\n';

    std::cout << std::setw(4) << "----------------"
              << std::setw(22) << "-------------------------"
              << std::setw(10) << "------------" << '\n';

    while (!ifs.eof()){
        ifs >> name >> lastname >> social_security_number >> hourly_rate >> hours_worked;

        std::cout << "| " << std::setw(1) << name << std::setw(10) << lastname
                  << "  |" << std::setw(22) << social_security_number
                  << "  |" << std::setw(9) << hourly_rate * hours_worked << "  |\n";
    }

    std::cout << std::setw(4) << "----------------"
              << std::setw(22) << "-------------------------"
              << std::setw(10) << "------------" << '\n';
}