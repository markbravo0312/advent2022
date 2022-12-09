#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;
using instruction = std::tuple<int,int,int>; // 1 - how many values, 2 - from , 3 - to
using stacks_t = array<deque<char>,9>;


int main () {
    string filename{"input.txt"};
    
    ifstream input{filename};
    if (!input.is_open()) {
        cerr << "Failed to open file" << filename << endl;
    }

    string startingpos{};
    string line{};
    stacks_t stacks;
    

    while(getline(input, line)) {
            
    }

    for(int i = 0; i < 9; i++) {
        line += stacks[i].front();
    }

    input.close();

}