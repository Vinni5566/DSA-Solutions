#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
         
         int n = matrix.size();
         int m = 3;

         if (n == 1) return max(max(matrix[0][0], matrix[0][1]), matrix[0][2]); // max takes only two arguments
         
         vector<vector<int>> dp(n, vector<int>(m, 0));
         dp[0][0] = matrix[0][0];
         dp[0][1] = matrix[0][1];
         dp[0][2] = matrix[0][2];

         for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int maxPrev = 0;
                for(int k = 0; k < m; k++) {
                    if(k != j) {
                        maxPrev = max(dp[i-1][k], maxPrev);
                    }
                }

                dp[i][j] = matrix[i][j] + maxPrev;
            }
         }

         return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
};