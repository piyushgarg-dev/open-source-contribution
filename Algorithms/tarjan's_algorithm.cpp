#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Tarjan's Algorithm is used to find all the bridges in a graph.
// A bridge is an edge removing which increases the number of connected components in the graph.
// This algorithm is based on DFS traversal of the graph.


// Working:-
// 1. Perform a DFS traversal of the graph.
// 2. For each node, maintain the discovery time and the low time.
// 3. If the low time of the adjacent node is greater than the discovery time of the current node, then the edge connecting the current node and the adjacent node is a bridge.
// 4. The low time of a node is the minimum of the low time of all the adjacent nodes and the discovery time of the current node.
// 5. The discovery time of a node is the time at which the node was discovered during the DFS traversal.

// TC: O(V+E)
// SC: O(V+E)


class Solution {
public:
    int timer=1;

    void dfs(int node, int parent, vector<int>&tin, vector<int>&vis, vector<int>&low, vector<vector<int>>&graph, vector<vector<int>>&bridges){

        vis[node]=1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it: graph[node]){
            if(it==parent)continue;

            if(vis[it]==0){
                dfs(it, node, tin, vis, low, graph, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);

        for(auto it: connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1, 0);
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>bridges;
        dfs(0, -1, tin, vis, low, graph, bridges);
        return bridges;
    }
};

int main(){
    Solution s;
    vector<vector<int>>connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>>ans = s.criticalConnections(4, connections);
    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}