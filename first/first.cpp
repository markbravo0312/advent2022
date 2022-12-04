#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string filename{"input.txt"};
    //int number;
    


    // ERROR HANDLING FOR INPUT
    ifstream instream(filename);
    if (!instream.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }  


    int max1{0};
    int max2{0};
    int max3{0};
    int current{0};
    string line{};

    while (getline(instream, line)) {
      if (line.empty())  {
        if (current > max1) {
            max3 = max2;
            max2 = max1;
            max1 = current;
        } else if (current > max2) {
            max3 = max2;
            max2 = current;
        } else if (current > max3) {
            max3 = current;
        }
        current = 0;
      } else {
        int num = stoi(line);
        current += num;
      }
    }

    cout << "in total the top 3 are carrying: " << max1 + max2 + max3 << endl;

    
    instream.close();

    return EXIT_SUCCESS;
}