#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        
        int IslandCount = 0;
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if((i == 0 || i == N-1 || j == 0 || j == M-1) && (matrix[i][j] == 1)) {
                    q.push({i, j});
                    matrix[i][j] = 2;
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto& d: dir) {
                int dx = d.first;
                int dy = d.second;

                int nx = x + dx;
                int ny = y + dy;

                if((nx >= 0 && nx < N && ny >= 0 && ny < M) && (matrix[nx][ny] == 1)) {
                    matrix[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == 1 && visited[i][j] == false) {
                    
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
                            
                            if(nx >= 0 && nx < N && ny >= 0 && ny < M && matrix[nx][ny] == 1 && visited[nx][ny] != true) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
            
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == 2) {
                    matrix[i][j] = 1;
                }
            }
        }
        
        
        return IslandCount;
    }
};