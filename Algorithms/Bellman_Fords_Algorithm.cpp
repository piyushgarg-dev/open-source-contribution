#include<iostream>
#include<vector>

using namespace std;

// an algorithm for finding shortest path from source to all other vertices
// in a graph with negative edge weights
// Time complexity: O(V*E)
// Space complexity: O(V)

// Working:-
// 1. Initialize dist[] with 1e8 and dist[src] with 0
// 2. Relax all edges V-1 times
// 3. Check for negative weight cycle by relaxing all edges one more time
// 4. If dist[u] + wt < dist[v] then update dist[v] = dist[u] + wt


vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    
    for (int i=0;i<V-1;i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[it[0]] != 1e8 && (dist[u] + wt < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (auto it:edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[it[0]] != 1e8 && (dist[u]+wt<dist[v])) {
                return {-1};
            }
        }
    
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i=0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> res = bellmanFord(n, edges, 0);
    for (int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}