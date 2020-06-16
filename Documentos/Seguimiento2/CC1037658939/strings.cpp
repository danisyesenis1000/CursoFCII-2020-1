#include <iostream>
#include <string>

using namespace std;

/*
 * strings.cpp
 * 
 * Solution to chapter 7, excercises 10-12.
 * 
 * Carolina Herrera S.
 * 
 **/

void replace_with_x( string& );
void replace_first_instance( string& );
void replace_every_instance( string& );

int main(){
    string str1, str2, str3;
    
    cout << "Ingrese una cadena de caracteres: ";
    getline( cin, str1 );
    
    str2 = str1;
    str3 = str1;
    
    // Exercise 10
    cout << "--- Ejercicio 10 ---" << endl;
    replace_with_x( str1 );
    
    cout << endl;
    cout << str1 << endl;
    cout << endl;
    
    // Excercise 11
    cout << "--- Ejercicio 11 ---" << endl;
    cout << str2 << endl;
    replace_first_instance( str2 );
    
    cout << endl;
    cout << str2 << endl;
    cout << endl;
    
    // Excercise 12
    cout << "--- Ejercicio 12 ---" << endl;
    cout << str3 << endl;
    replace_every_instance( str3 );
    
    cout << endl;
    cout << str3 << endl;
    cout << endl;
    
    return 0;
}


// Exercise 10
void replace_with_x( string& replace_str ){
    int position;
    
    position = replace_str.find("e");
    
    while( position != string::npos ){
        replace_str.replace( position, 1, "x" );
        position = replace_str.find("e");
    }
}

// Exercise 11
void replace_first_instance( string& replace_str ){
    int position;
    string find_seq, replace_seq;
    
    cout << "Introduzca la cadena de caracteres que desea reemplazar: ";
    getline( cin, find_seq );
    
    cout << "Introduzca la cadena de caracteres que desea agregar: ";
    getline( cin, replace_seq);
    
    position = replace_str.find(find_seq);
    replace_str.replace( position, find_seq.length(), replace_seq );
}

// Exercise 12
void replace_every_instance( string& replace_str ){
    int position;
    string find_seq, replace_seq;
    
    cout << "Introduzca la cadena de caracteres que desea reemplazar: ";
    getline( cin, find_seq);
    
    cout << "Introduzca la cadena de caracteres que desea agregar: ";
    getline( cin, replace_seq);
    
    position = replace_str.find(find_seq);
    
    while( position != string::npos ){
        replace_str.replace( position, find_seq.length(), replace_seq);
        position = replace_str.find(find_seq);
    }
}





