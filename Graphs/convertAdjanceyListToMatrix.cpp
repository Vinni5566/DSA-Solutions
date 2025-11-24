//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week16/problem/convert-adjacency-list-to-adjacency-matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> adjToMat(vector<vector<int>>& adj) {
        
        int n = adj.size();
        
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                int u = i; 
                int v = adj[i][j];
                
                if(u != v){
                    mat[u][v] = 1;
                }
            }
        }
        
        return mat;;
        
    }
};