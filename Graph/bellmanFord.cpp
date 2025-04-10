#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//-------------------------Only applicable for directed graphs---------------------------
//If graph is undirected, then convert it to directed graph by giving arrows both side with same edge weight

//-----------------------Single source shortest path algorithm---------------------------
//--------------------Applicable to negative edges or negative cycle---------------------
//----------------------------------TC- O(VxE)-------------------------------------------

class Solution {
  public:
    //---------------------------------------------------------------------------

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        //relaxation for n-1 times
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // A negative cycle is a cycle whose edges are such that the sum of their weights is a negative value
        
        //Nth relaxation for checking negative cycle
        //If no -ve cycle present, then the dist vector should be filled in n-1 iterations
        //The logic behind (n-1) is we have to pass atmost (n-1) edges to move from one node to other if n vertices are there
        //But after n-1 iterations, if the dist vector changes still that means negative cycle present

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
                
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                //value still updating means negative cycle present
                return {-1};
            }
        }
        
        return dist;
    }

    //----------------------------------------------------------------------------
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}