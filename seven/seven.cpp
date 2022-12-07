#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main () {
    string filename {"input.txt"};
    fstream input{filename};

    if (!input.is_open()) {
        cerr << "Error couldn't open file" << filename << endl;

    }


    string line{};


    while (getline(input, line)) {

    }


    input.close();
}