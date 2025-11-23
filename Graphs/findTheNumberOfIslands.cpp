#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int IslandCount = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        //up, roght, down, left, up-left diagonal, up-right diagonal, down-left diagonal, down-right diagonal
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'L' && visited[i][j] == false) {
                    
                    IslandCount++;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        q.pop();
                        
                        for(auto& d: dir) {
                            int dx = d.first;
                            int dy = d.second;
                            
                            int nx = x + dx;
                            int ny = y + dy;
                            
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 'L' && visited[nx][ny] != true) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return IslandCount;
    }
};