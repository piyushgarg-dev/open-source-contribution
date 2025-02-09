#include<iostream>
#include<vector>
using namespace std;

// Disjoint set data structure
// Time complexity: O(1) (amortized)
// Space complexity: O(n)

// Working of DisjointSet class:-
// 1. Initially, all elements are in their own set
// 2. Find operation: returns the representative of the set to which the element belongs
// 3. Union operation: merges the sets containing the two elements


class DisjointSet{
    vector<int> parent, rank;

    public:

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n+1, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find_Ulp(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find_Ulp(parent[node]);
    }

    void UnionSet(int u, int v){
        int ulp_u = find_Ulp(u);
        int ulp_v = find_Ulp(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        return;
    }
};

int main(){
    DisjointSet ds(5);
    ds.UnionSet(0, 2);
    ds.UnionSet(4, 2);
    ds.UnionSet(3, 1);
    if(ds.find_Ulp(4)==ds.find_Ulp(0)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}