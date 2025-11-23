//Problem link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<int> res;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < operators.size(); i++) {
            
            int u = operators[i][0];
            int v = operators[i][1];
            
            mat[u][v] = 1;
            
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            
            int numOfIslands = countIslands(mat, n, m, visited, dir);
            res.push_back(numOfIslands);
            
        }
        
        return res;
        
    }
    
    int countIslands(vector<vector<int>>& mat, int n, int m, vector<vector<bool>>& visited, vector<pair<int, int>>& dir) {
        
        int count = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(mat[i][j] == 1 && visited[i][j] == false) {
                    
                    count++;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        q.pop();
                        
                        for(auto& d : dir) {
                            
                            int dx = d.first;
                            int dy = d.second;
                            
                            int nx = x + dx;
                            int ny = y + dy;
                            
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1 && visited[nx][ny] != true) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                
                }
            }
        }
        
        return count;
    }
};


//optimize this sol using disjoint set