#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>



using namespace std;
using Pair = std::pair<int,int>;



tuple<Pair, Pair> parse_pairs(const std::string& line) {
    string substring{};
    istringstream is{line};
    int pairs[4];
    int i{0};
    while (getline(is, substring, ',')) {
        string substring2 {};
        istringstream is2{substring};
        while (getline(is2, substring2, '-')) {
            pairs[i] = stoi(substring2);
            ++i;
        }
    }
    return {{pairs[0], pairs[1]}, {pairs[2], pairs[3]}};
}

int main () {
    string filename{"input.txt"};
    fstream input{filename};


    if (!input.is_open()) {
        cerr << "Error file " << filename << " could not be opened" << endl; 
    }

    string line{};
    int total1{0};
    int total2{0};
    

    while (getline(input, line)) {
        
        string substring{};
        auto pairs = parse_pairs(line);
        Pair pair1 = get<0> (pairs);
        Pair pair2 = get<1> (pairs);

        if ((pair1.first >= pair2.first && pair1.second <= pair2.second) ||
         (pair2.first >= pair1.first && pair2.second <= pair1.second)) {
            ++total1;
        }   

        if (pair1.first <= pair2.second && pair2.first <= pair1.second) {
            ++total2;
        }

    }

    cout << "Solution of part 1 is: " << total1 << endl << "Solution of part2 is: " << total2 << endl;
    input.close();
    
}
