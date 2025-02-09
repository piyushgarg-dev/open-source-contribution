#include<iostream>
#include<vector>

using namespace std;    

// Floyd Warshall Algorithm is used to find the shortest distance between all pairs of vertices in a graph.
// It is an all-pairs shortest path algorithm.
// It works for both directed and undirected graphs.

// Time Complexity: O(V^3), where V is the number of vertices in the graph.
// Space Complexity: O(V^2), where V is the number of vertices in the graph.

// Working:-
// 1. Initialize the shortest distance matrix with the given matrix.
// 2. If there is no edge between two vertices, then the distance between them is set to infinity.
// 3. For each vertex k, we check if the shortest distance between vertex i and vertex j can be minimized by including vertex k.
// 4. If the distance between vertex i and vertex j is greater than the sum of the distance between vertex i and vertex k and the distance between vertex k and vertex j, then we update the distance between vertex i and vertex j.



void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==-1)mat[i][j] = 1e5;
                }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==k||j==k)continue;
                    mat[i][j] = min(mat[i][k]+mat[k][j], mat[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]>=1e5)mat[i][j] = -1;
                }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

int main(){
    int n, m;
    cin >> n >> m;  
    vector<vector<int>> mat(n, vector<int>(n, -1));
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
    }
    cout<<"floyd warshall algorithm:"<<endl;
    shortestDistance(mat);

    

    return 0;
}