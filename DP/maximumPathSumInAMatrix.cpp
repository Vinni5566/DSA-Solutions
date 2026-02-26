//link: https://www.geeksforgeeks.org/problems/path-in-matrix3805/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++) {
            dp[0][i] = mat[0][i];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(j == 0) {
                    dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                } else if(j == m-1) {
                    dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = mat[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
                }
            }
        }
        
        int maximumPathSum = *max_element(dp[n-1].begin(), dp[n-1].end());
        
        return maximumPathSum;
        
    }
};