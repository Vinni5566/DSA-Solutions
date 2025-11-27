//Problem link: https://takeuforward.org/plus/dsa/problems/check-if-a-number-is-odd-or-not

#include <iostream>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        if((n & 1) != 0) return true;
        return false;
    }
};