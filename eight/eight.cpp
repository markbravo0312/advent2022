#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

#define SIZE 99




bool checkLeft(char grid[][SIZE + 1], int x, int y, char c) {
    int b{c - '0'};
    for (int t = x - 1; t >= 0; --t) {
        if (grid[y][t] - '0' >= b) {
            return false;
        }
    }
    
    return true;
}

bool checkRight(char grid[][SIZE + 1] , int x, int y, char c, int length) {
    int b{ c - '0'};
    for (int t = x + 1; t < SIZE; ++t) {
        if (grid[y][t] - '0' >= b) {
            return false;
        }
    }
    
    return true;
}

bool checkDown(char grid[][SIZE + 1] , int x, int y, char c) {
    int b{ c - '0'};

    for (int t = y + 1; t < SIZE; ++t) {
        if (grid[t][x] - '0' >= b) {
            return false;
        }
    }

    
    return true;
}

bool checkUp( char grid[][SIZE + 1] , int x, int y, char c) {

    int b {c - '0'};

    for (int t = y - 1; t >= 0; --t) {
        if ( grid[t][x] - '0' >= b) {
            return false;
        }
    }

    
    return true;
}



int main () {
    string filename {"input.txt"};
    fstream input{filename};

    if (!input.is_open()) {
        cerr << "Error couldn't open file" << filename << endl;

    }

    
    string line{};
    input >> line;
    char grid[SIZE][SIZE + 1]; 
    cout << line.length() + 1 << endl;
    long unsigned int rowlength{line.length() + 1};
    line.copy(grid[0], line.length() + 1);
    int i{0};

    while(getline(input, line)) {
        line.copy(grid[i], line.length() + 1);
        ++i;
    }
    int total{0};
    for (i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "currently at char: " << grid[i][j];;
            if (checkUp(grid, j, i, grid[i][j]) || checkDown(grid, j, i, grid[i][j]) 
            || checkLeft(grid, j, i, grid[i][j]) || checkRight(grid, j, i, grid[i][j], SIZE)) {
                ++total;
                cout << " incremented total: "<< total << endl;
            }
        }
    }
    

    cout << "Result for part 1 is: " << total << endl;
    input.close();
}