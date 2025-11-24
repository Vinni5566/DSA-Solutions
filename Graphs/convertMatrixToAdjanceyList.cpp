//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week16/problem/convert-adjacency-matrix-to-adjacency-list

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> matToAdj(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
               
                if(i != j && mat[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        return adj;
        
    }
};