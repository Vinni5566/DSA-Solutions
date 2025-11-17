//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week7/problem/move-all-zeroes-to-end-of-array0751

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        int l = arr.size();
        
        if(l == 1) return;
        
        int j = 0;
        
        
        for(int i = 0; i < l; i++) {
            if(arr[i] != 0) {
                arr[j] = arr[i];
                j++;
            }
        }
        
        for(int i = j; i < l; i++) {
            arr[i] = 0;
        }
        
    }
};