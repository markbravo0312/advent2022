#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <unordered_map>
#include <boost/functional/hash.hpp>


using namespace std;





struct position {
    int x;
    int y;
    
    position (int x, int y) : x(x), y(y) {}

    position() =  default;
    

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    bool operator == (const position& s) {
        return x == s.x && y == s.y;
    }

};


struct position_hasher {
    size_t operator()(const position& ps) const {
        size_t seed = 0;
        boost::hash_combine(seed, ps.x);
        boost::hash_combine(seed, ps.y);
        return seed;
    }
};

position operator *(const position& lhs, int val) {
        return {lhs.x*val, lhs.y*val}; 
    }

position operator +(const position& lhs, const position& rhs) {
    return {lhs.x+ rhs.x, lhs.y + rhs.y};
}

position operator -(const position& lhs, const position& rhs) {
    return {lhs.x- rhs.x, lhs.y - rhs.y};
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}


position move_head(const position& head, char dir) {
    const static unordered_map<char, position> dir_to_delta = {
        {'U', {0,1}}, {'R', {1,0}}, {'D', {0,-1}}, {'L', {-1,0}}
    };
    return head + dir_to_delta.at(dir);
}

// position move_knot(const position& prev, const position& link) {
//     auto delta = prev - link;
//     return 
//         (std::max(std::abs(delta.x), std::abs(delta.y)) <= 1) ?
//             link : link + position{ sgn(delta.x), sgn(delta.y) };
// }





    

int main () {
    

    
    


}