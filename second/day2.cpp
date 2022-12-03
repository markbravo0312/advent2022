#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


int main () {
    string filename("input.txt");

    ifstream input_file(filename);
    
    char opponent{};
    char me{};
    int score{0};
    
    // PART 1
    /*
    int outcomes[3][3] = {{4, 1, 7}, {8, 5, 2},{3, 9, 6}};         // Row1 - Rock, Row2 - Paper, Row3 - Scissors    
    while (input_file >> opponent >> me) {
        //cout << "Opponent plays: " << opponent << endl << "you play: " << me << endl;
        score += outcomes[me - 'X'][opponent - 'A'];
    }
    
    cout << "your total score: " << score << endl;
    */


    //PART 2    
    int outcomes[3][3] = {{3, 4, 8}, {1, 5, 9}, {2, 6, 7}};                                       // Row1 - Rock, Row2 - Paper, Row3 - Scissors  || Colums - Loss, Draw, Win
    while (input_file >> opponent >> me) {
        score += outcomes[opponent - 'A'][me - 'X'];
    }

    cout << "your total score: " << score << endl;
    
    input_file.close();
    
}