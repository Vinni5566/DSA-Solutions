#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        set<vector<pair<int, int>>> uniqueIslands;
        

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> island;
                    bfs(grid, visited, i, j, island, dir, m, n);
                    uniqueIslands.insert(island);
                }
            }
        }

        return uniqueIslands.size();
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int sr, int sc, vector<pair<int, int>>& island, vector<pair<int, int>>& dir, int m, int n) {
        
        int baseX = sr;
        int baseY = sc;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
                        
            q.pop();
            
            island.push_back({x - baseX, y - baseY});
                        
            for(auto& d : dir) {
                int dx = d.first;
                int dy = d.second;
                            
                int nx = x + dx;
                int ny = y + dy;
                            
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && visited[nx][ny] != true) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            
            sort(island.begin(), island.end());
        }
        
    }
};
