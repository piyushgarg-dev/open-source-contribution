#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Kruskal's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph.
// It finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

// Working:-
// 1. Sort all the edges in non-decreasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
// 3. Repeat step 2 until there are (V-1) edges in the spanning tree.

// Time Complexity: O(ElogE + ElogV) = O(ElogE) or O(ElogV) (E = number of edges, V = number of vertices)
// Space Complexity: O(V) (V = number of vertices)

class Solution
{
	public:
	
	class Disjoint{
	    vector<int> parent, rank;
	    
	    public:
	    Disjoint(int n){
	        parent.resize(n);
	        rank.resize(n, 0);
	        for (int i = 0; i < n; i++) parent[i] = i;
	    }
	    
	    int findUlp(int node){
	        if (node == parent[node]) return node;
	        return parent[node] = findUlp(parent[node]);
	    }
	    
	    void Union(int u, int v){
	        u = findUlp(u);
	        v = findUlp(v);
	        
	        if (u == v) return;
	        
	        if (rank[u] < rank[v]) {
	            parent[u] = v;
	        } else if (rank[v] < rank[u]) {
	            parent[v] = u;
	        } else {
	            parent[u] = v;
	            rank[v]++;
	        }
	    }
	};
	
	int spanningTree(int V, vector<vector<int>> adj[])
	{
	    Disjoint ds(V);
	    priority_queue<pair<int, pair<int, int>>, 
	                   vector<pair<int, pair<int, int>>>, 
	                   greater<pair<int, pair<int, int>>>> pq;
	                   
	    for (int i=0;i<V;i++) {
	        for (auto neighbor : adj[i]) {
	            int adjNode = neighbor[0];
	            int weight = neighbor[1];
	            pq.push({weight, {i, adjNode}});
	        }
	    }
	    
	    int mstWeight = 0;
	    int edgesUsed = 0;
	    

	    while (!pq.empty() && edgesUsed<V-1) {
	        int wt = pq.top().first;
	        int u = pq.top().second.first;
	        int v = pq.top().second.second;
	        pq.pop();
	        
	        if (ds.findUlp(u) != ds.findUlp(v)) {
	            ds.Union(u, v);
	            mstWeight += wt;
	            edgesUsed++;
	        }
	    }
	    
	    return mstWeight;
	}
};

int main(){
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 7});
    
    Solution obj;
    cout << obj.spanningTree(V, adj) << endl;
    
    return 0;
}
