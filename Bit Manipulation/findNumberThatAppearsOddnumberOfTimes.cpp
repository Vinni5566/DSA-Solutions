//Problem link: https://leetcode.com/problems/single-number/submissions/1841009904/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for(int i : nums ) {
            res = res ^ i;
        }

        return res;
    }
};