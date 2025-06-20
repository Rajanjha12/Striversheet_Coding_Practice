//By dfs
class Solution {
  public:
void topological(int node, stack<int> &s, vector<bool> &visited,  unordered_map<int,list<int>> &ad) {
    visited[node] = true;
    for (int neighbor : ad[node]) {
        if (!visited[neighbor]) {
            topological(neighbor, s, visited, ad);
        }
    }
    s.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &edges) {
    unordered_map<int,list<int>> ad(V);  // corrected adjacency list

    // build the graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        ad[u].push_back(v);
    }

    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topological(i, s, visited, ad);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;


    }
};// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E) for the adjacency list and the visited array.