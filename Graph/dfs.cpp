#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    //-----------------------------------------------------------------------

    //recursive function
    void dfs(int node, vector<int> vis, vector<int> adj[], vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, vis, adj, ans);
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        int start = 0;
        
        vector<int> ans;
        
        dfs(start, vis, adj, ans);
        return ans;
    }

    //-----------------------------------------------------------------------
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[1000];
        
        //undirected graph
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
