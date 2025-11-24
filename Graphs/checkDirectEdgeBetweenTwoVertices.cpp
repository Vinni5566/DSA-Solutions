//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week16/problem/check-if-there-is-a-direct-edge-between-two-vertices

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int checkEdge(vector<vector<int>>& adj, int u, int v) {
        
        for(int i = 0; i < adj[u].size(); i++) {
            if(adj[u][i] == v) return true;
        }
        
        return false;
        
    }
};