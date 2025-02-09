#include<iostream>
#include<vector>
#include<queue>

using namespace std;  
// Prim's Algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
// This algorithm keeps track of the vertices that have been included in the minimum spanning tree (MST) and the edges that are part of the MST.

// TC: O(V^2) 
// SC: O(V)

// Working:-
// 1. Create a set mstSet that keeps track of vertices already included in MST.
// 2. Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
//    Assign key value as 0 for the first vertex so that it is picked first.
// 3. While mstSet doesn’t include all vertices:
//    a. Pick a vertex u which is not there in mstSet and has minimum key value.
//    b. Include u to mstSet.
//    c. Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices.
//       For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v.


vector<pair<int, int>> spanningTree(int V, vector<vector<int>> adj[]) {
    int span = 0;
    vector<pair<int, int>> edges;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    
    vector<bool> vis(V, false);
    
    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        
        if (vis[u]) continue;
        
        vis[u] = true;
        span += wt;
        
        if (u != v) {
            edges.push_back({u, v});
        }
        
        for (auto it : adj[u]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (!vis[adjNode]) {
                pq.push({edgeWeight, {adjNode, u}});
            }
        }
    }
    
    cout << "Total weight of MST: " << span << endl;
    return edges;
}


int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n];
    
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<pair<int, int>> res = spanningTree(n, adj);
    for (auto it : res) {
        cout << it.first << " - " << it.second << endl;
    }

    return 0;
}