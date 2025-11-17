//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week7/problem/two-sum-in-sorted-array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        vector<int> res(2, -1);
        
        int l = arr.size();
        
        int left = 0;
        int right = l-1;
        
        while(left < right) {
            if((arr[left] + arr[right]) == target) {
                res[0] = left+1;
                res[1] = right+1;
                break;
            } else if((arr[left] + arr[right]) > target) {
               right--; 
            } else {
                left++;
            }
        }
        
        return res;
        
    }
};