#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Approach - 1
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    int up = dp[i-1][j];
                    int left = (j > 0)? dp[i-1][j-1] : INT_MAX;
                    int right = (j < n-1)? dp[i-1][j+1] : INT_MAX;

                    dp[i][j] = matrix[i][j] + min(min(up, left), right);
                }
            }
        }

        int minPath = dp[m-1][0];
        for(int i = 1; i < m; i++) {
            if(dp[m-1][i] < minPath) minPath = dp[m-1][i];
        }

        return minPath;
    }
};

//Approach - 2
class Solution { 
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {

                if(i == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    if(j == 0) {
                        dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                    } else if(j == n-1) {
                        dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                    } else {
                        dp[i][j] = matrix[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
                    }
                }
            }
        }

        int minPath = dp[m-1][0];
        for(int i = 1; i < m; i++) {
            if(dp[m-1][i] < minPath) minPath = dp[m-1][i];
        }

        return minPath;
    }
};