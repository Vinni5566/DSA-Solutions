//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week16/problem/count-number-of-edges-in-an-undirected-graph

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        
        int V = adj.size();
        vector<bool> visited(V, false);
        
        int countEdges = 0;
        
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                countEdges++;
            }
        }
        
        return countEdges/2;
        
    }
};