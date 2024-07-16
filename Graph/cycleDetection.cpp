//-------------------------------Undirected Graph-------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
  public:
    //--------------Detect cycle using BFS-----------------------------

    bool detectCycleBfs(int src, vector<int> adj[], vector<int>& vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it)
                    return true;
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycleBfs(i, adj, vis)) return true;
            }
        }
        
        return false;
    }

    //-----------------------Detect cycle using DFS-----------------------------

    bool detectCycleDfs(int src, int parent, vector<int> adj[], vector<int>& vis){
        vis[src] = 1;
        
        for(auto it: adj[src]){
            if(!vis[it]){
                bool res = detectCycleDfs(it, src, adj, vis);
                if(res) return true;
            }
            else if(it != parent)  return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycleDfs(i, -1, adj, vis)) return true;
            }
        }
        
        return false;
    }

    //------------------------------------------------------------------
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[1000];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

//-------------------------------Directed Graph-----------------------------------------

