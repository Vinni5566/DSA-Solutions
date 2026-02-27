//Problem link: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {

        int l1 = s1.length();
        int l2 = s2.length();
        
        if(s1 == s2) return l1; //base case, both equal

        //build dp table to find length of lcs
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));

        for(int i = 1; i < l1+1; i++) {
            for(int j = 1; j < l2+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return l1+l2-dp[l1][l2];  //len of min super seq
        
    }
};