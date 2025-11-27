//Provlem link: https://takeuforward.org/plus/dsa/problems/check-if-the-i-th-bit-is-set-or-not

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
};