#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size();

        //max element
        int maximum = *max_element(nums.begin(), nums.end());

        //frequency vector
        vector<int> freq(maximum+1, 0);

        for(int num : nums) {
            freq[num]++;
        }

        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] > 1) return i;  //return element repeating n times
        }

        return 0;

    }
};