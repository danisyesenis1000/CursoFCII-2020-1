#include <iostream>
#include <array>
#include <fstream>
#include <string>

/*
 * maze.h
 * 
 * Prototype for class Maze.
 * 
 * Carolina Herrera S.
 * Last update: april 27, 2020
 * 
 * */

using namespace std;

class Maze{
    
    public:
    void load( string, array<int, 2> );
    void solve();
    
    private:
    array<array<char, 12>, 12> maze;
    array<int, 2> position;
    array<int, 2> position_reset;
    char orientation;
    char orientation_reset;
    
    void go_south();
    void go_north();
    void go_east();
    void go_west();
    void go_right();
    void go_left();
    void go_straight();
    void go_back();
    void reset_state();
    void print_state();
};

