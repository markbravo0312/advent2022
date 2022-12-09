#include <iostream>
#include <fstream>
#include <string>
#include <deque>
using namespace std;



int main () {
    string filename {"input.txt"};
    fstream input{filename};

    if (!input.is_open()) {
        cerr << "Error couldn't open file" << filename << endl;

    }


    string line{};
    int directory{0};
    deque<char> current_directories{};
    


    while (getline(input, line)) {
        
    }


    input.close();
}