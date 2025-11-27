//Problem link: https://takeuforward.org/plus/dsa/problems/count-the-number-of-set-bits

#include <iostream>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n > 0) {
            n = n | (n-1);
            count++;
        }

        return count;
    }
};