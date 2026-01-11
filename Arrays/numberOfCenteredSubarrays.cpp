//link: https://leetcode.com/contest/weekly-contest-484/problems/number-of-centered-subarrays/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//brute force approach : O(N^3)

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 1;

        int count = 0;

        for(int x : nums) count++;

        vector<int> prefixSum(n+1, 0);

        for(int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i != j) {
                    int subArrSum = prefixSum[j+1] - prefixSum[i];
                    for(int k = i; k <= j; k++) {
                        if(nums[k] == subArrSum) {
                            count++;
                            break;
                        }
                    }
                }
                
            }
        }

        return count;
        
    }
};

//optimal approach : O(N^2)

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int n = nums.size();
        
        int count = 0;

        vector<int> prefixSum(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            for(int j = i; j < n; j++) {
                freq[nums[j]]++;
                int subArrSum = prefixSum[j+1] - prefixSum[i];
                if(freq[subArrSum] > 0) count++;
            }
        }

        return count;
        
    }
};