//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week7/problem/count-pairs-with-given-sum--150253

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        
        int l = arr.size();
        
        int pairs = 0;
        
        unordered_map<int, int> map;
        
        for(int i = 0; i < l; i++) {
            
            int need = target - arr[i];
            
            if(map.count(need)) {
                pairs += map[need];
            }
            
            map[arr[i]]++;
        }
        
        return pairs;
        
    }
};