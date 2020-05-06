#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "maze.h"

/*
 * main.cpp
 * 
 * Usage of class Maze.
 * Loads maze from file and then solves it.
 * 
 * Requires: functions.cpp and maze.h
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

using namespace std;

int main(){
    Maze maze1;
    
    string filename = "maze1.txt"; // Name of maze file
    array<int, 2> start = {2, 0}; // Starting coordinates {rows, columns}
    
    maze1.load( filename, start );
    
    maze1.solve();
    
    return 0;
}
