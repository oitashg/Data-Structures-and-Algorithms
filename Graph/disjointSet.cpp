#include <iostream>
#include <vector>
using namespace std;

//---------------------------TC is O(4alpha)----------------------------------------------
//-------------------Almost constant as alpha is close to 1-------------------------------

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 

        //At first, every node is itself its parent
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    //To find the ultimate parent of each node
    //By applying path compression, the work is done in less time
    //T.C - O(4alpha)
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    //Union means joining 2 nodes i.e creating edges
    //union(u,v) -> joining u and v 
    //T.C - O(4alpha)

    //Find ultimate parents of nodes u and v
    //Then check their ranks
    //The node with the upper rank will be at the top
    //If ranks are same, anyone can be at top
    //Update the rank of higher one by increasing by 1

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    //Find ultimate parents of nodes u and v
    //Then check their sizes
    //The node with the higher size will be at the top
    //If size are same, anyone can be at top
    //Update the size of higher one with the original size + size of lower one

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

//-----------------------------------------------------------------------

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}