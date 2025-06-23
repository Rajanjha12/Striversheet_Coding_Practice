
// Problem: Detect Cycle in an Undirected Graph
#include <bits/stdc++.h>
using namespace std;
//DFS approach
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space Complexity: O(V) for the visited array and the recursion stack

class Solution {
  public:
  bool solve( unordered_map<int,vector<int>>&mp,int u,vector<bool>&visited, int parent){
        visited[u]=true;
        for(int&v :mp[u]){
             if (!visited[v]) {
                if (solve(mp, v, visited, u)) return true;
            } else if (v != parent) {
                return true;  // found a back edge, hence cycle
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>mp;
        for(auto&e:edges){
            int u =e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i =0;i<V;i++){
            if(!visited[i] && solve(mp,i,visited,-1))
                return true;
            
        }
        return false;

        
    }
};
//