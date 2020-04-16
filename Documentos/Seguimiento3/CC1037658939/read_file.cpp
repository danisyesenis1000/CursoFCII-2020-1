#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

/*
 * read_file.cpp
 * 
 * Solution to exercise 7, section 8.2.
 * 
 * Carolina Herrera S.
 * 
 * */

void create_payroll_table( ofstream& );
void calculate_payroll( ifstream& );

int main(){
    // Write file with data for payroll
    ofstream payroll_tab( "payroll.dat", ios::out );
    
    if ( payroll_tab.fail() )   
    {
      cout << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    
    create_payroll_table( payroll_tab );
    
    // Read file and calculate payroll
    ifstream payroll_data( "payroll.dat", ios::in );
    
    if ( payroll_data.fail() )   
    {
      cout << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    
    calculate_payroll( payroll_data );
    
    return 0;
}


// Writes payroll table to file
void create_payroll_table( ofstream& payroll_data ){
    payroll_data << "B Caldwell 555-88-2222 7.32 37\n"
                 << "D Memcheck 555-77-4444 8.32 40\n"
                 << "R Potter 555-77-6666 6.54 40\n"
                 << "W Rosen 555-99-8888 9.80 35" << endl;
}


// Calculates payroll reading data from file
void calculate_payroll( ifstream& payroll_data ){
    string name, lastname, id_number, fullname;
    double hours_worked;
    double pay_per_hour, total_pay;
    
    cout << left << setw(15) << "Nombre"
                 << setw(27) << "Número seguridad social"
                 << setw(15) << "Pago bruto" << endl;
    
    // Reads data from file
    while ( payroll_data >> name >> lastname >> id_number 
                         >> hours_worked >> pay_per_hour ) {
        
        total_pay = hours_worked*pay_per_hour;
        
        // For correct output of name
        fullname = name + ' ' + lastname;
        
        cout << left << setw(15) << fullname << " " 
             << setw(27) << id_number << " " 
             << setw(15) << total_pay << endl;
    }
}
