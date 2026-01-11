//Link: https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minDeletions(string s) {
        
        int l = s.length();
        
        //reverse of s
        string r = s;
        reverse(r.begin(), r.end());
        
        if(s == r) return 0;
        
        //stores length of longest palindromic subsequence till i
        vector<vector<int>> dp(l+1, vector<int>(l+1, 0));

        for(int i = 1; i <= l; i++) {
            for(int j = 1; j <= l; j++) {

                //both are equal
                if(s[i-1] == r[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  //skip i or skip j
                }
            }
        }
        
        //dp[l][l] is longest palindromic subsequence
        
        return l - dp[l][l]; //min characters need to be removed to make string palindrome
        
    }
};