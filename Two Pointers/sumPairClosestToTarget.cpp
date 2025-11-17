//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week7/problem/pair-in-array-whose-sum-is-closest-to-x1124

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        
        if(arr.size() == 1) return {};
        
        sort(arr.begin(), arr.end());
        
        int s = 0;
        int e = arr.size()-1;
        int minDist = INT_MAX;
        int maxDiff = 0;
        
        vector<int> res(2);
        bool found = false;
        
        while(s < e) {
            int sum = arr[s] + arr[e];
            int dist = abs(target - sum);
            int diff = abs(arr[s] - arr[e]);
            
            if(dist < minDist) {
                minDist = dist;
                maxDiff = diff;
                
                res[0] = arr[s];
                res[1] = arr[e];
                
                found = true;
            }
            
            if(dist == minDist) {
                if(diff > maxDiff) {
                    maxDiff = diff;
                    
                    res[0] = arr[s];
                    res[1] = arr[e];
                    
                    found = true;
                }
            }
            
            if(sum > target) e--;
            else s++;
        }
        
        if(!found) return {};
        
        return res;
        
    }
};