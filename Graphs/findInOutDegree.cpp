//Problem link: https://www.geeksforgeeks.org/batch/skill-up-dsa/track/su-dsa-topic-wise-week16/problem/degree-of-each-vertices-in-a-graph

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findInOutDegree(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> res(V, vector<int>(2, 0));
        
        for(int i = 0; i < edges.size(); i++) {
            res[edges[i][1]][0]++;
            res[edges[i][0]][1]++;
        }
        
        return res;
    }
};