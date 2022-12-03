#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>


using namespace std;




unordered_set<char> getSet(string line) {
    unordered_set<char> s;
    for (int i = 0; i < line.length(); i++) {
        auto r = s.insert(line.at(i));
    }
    return s;
}

int getPriority(unordered_set<char> set, string line) {
    int priority{0};
    unordered_set<char> prev;
    for (int i = 0; i < line.length(); ++i) {
        char c = line.at(i);
        if (set.contains(c)) {
            if (!prev.contains(c))
            priority += isupper(c) ? c - '&' : c - '`';
            prev.insert(c);
        }
    }
    return priority;
}


int main () {
    string filename{"input.txt"};


    ifstream input(filename);

    if (!input.is_open()) {
        cerr << "Error: " << filename << " could not be opened" << endl;
        return EXIT_FAILURE;
    }


/* EXERCISE 1    
    string line{};  
    int priority{0};

    while (getline(input, line)) {
        unsigned long length{line.size()};
        string line1{line.substr(0, length / 2)};
        string line2{line.substr(length / 2)};
        cout << "1st Compartment: " << line1 << endl << "2nd Compartment: " << line2 << endl;
        unordered_set<char> s{getSet(line1)};
        for (const auto& r : s) {
            cout << "set has char: " << r << ", " <<endl;
        }
        priority += getPriority(s, line2);
        
    }
    cout << "prio of a is " << 'a' - '`' << endl;
    cout << "Priority: " << priority << endl;
*/




}