#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adj = constructAdj(edges, V);
        
        vector<int> visited(V, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        
        int sum = 0;
        
        while(!pq.empty()) {
            
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(visited[node]) continue;
            visited[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                
                if(!visited[adjNode]) {
                    pq.push({weight, adjNode});
                }
            }
        }
        
        return sum;
        
    }
    
    vector<vector<pair<int, int>>> constructAdj(vector<vector<int>>& edges, int V) {
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto it : edges) {
            
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            
        }
        
        return adj;
        
    }
};