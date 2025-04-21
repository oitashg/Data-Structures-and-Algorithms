#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    //------------------------Function to find no. of articulation points in a graph-----------------------------------
    // Means, no. of nodes upon removal of which the graph will be divided into multiple components

    int timer = 1;
    
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], vector<int>& t, vector<int>& low, vector<int>& marked){
        vis[node] = 1;
        int child = 0;
        t[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node]){
            if(it == parent) continue;
            
            if(!vis[it]){
                dfs(it, node, vis, adj, t, low, marked);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= t[node] && parent != -1) marked[node] = 1;
                
                child++;
            }
            else{
                low[node] = min(low[node], t[it]);
            }
        }
        
        if(child > 1 && parent == -1) marked[node] = 1;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> marked(V,0);
        vector<int> vis(V,0);
        vector<int> t(V);
        vector<int> low(V);
        
        dfs(0, -1, vis, adj, t, low, marked);
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(marked[i]) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[1000];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}