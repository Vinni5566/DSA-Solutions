#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        
        vector<vector<int>> copy = matrix;
        
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
        queue<pair<int, int>> q; 
        
        for(int i = 0; i < n; i++) { 
            for(int j= 0; j < m; j ++) { 
                if(matrix[i][j] == 0) { 
                    q.push({i, j}); 
                } 
            } 
        } 
        
        while(!q.empty()) { 
            int x =q.front().first; 
            int y = q.front().second; 
            
            q.pop(); int sum = 0; 
            
            for(auto& d : dir) { 
                int dx = d.first; 
                int dy = d.second; 
                
                int nx = x + dx; 
                int ny = y + dy; 
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) { 
                    sum += copy[nx][ny]; 
                    matrix[nx][ny] = 0; 
                } 
            } 
            
            matrix[x][y] = sum; 
        } 
        
        return;
        
    }
};