#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> graph = buildGraph(V, edges);
        vector<int> inDegree(V, 0);
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                inDegree[graph[i][j]]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        int count = 0;  //var to count processed nodes
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            
            for(int v : graph[u]) {
                inDegree[v] -= 1;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return V != count;
   
        
    }
    
    vector<vector<int>> buildGraph(int V,vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(V);
        
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        return graph;
    }
};