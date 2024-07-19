//---------------Topological Sort is only valid in DAG(Directed Acyclic Graph)---------------------------

#include <iostream>
#include <vector>
#include <stack>
#include<queue>
using namespace std;

class Solution
{
	public:
    //------------------Topological sort using DFS----------------------------------

	void dfs(int node, stack<int>& s, vector<int>& vis, vector<int> adj[]){
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it])
	            dfs(it, s, vis, adj);
	    }
	    
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> s;
	    vector<int> vis(V, 0);
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i])
	            dfs(i, s, vis, adj);
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}

    //-------------------------------------------------------------------------

    //------------------Topological sort using BFS(Kahn's Algorithm)----------------------------------

    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V);
	    
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i])
	            indegree[it]++;
	    }
	    
	    vector<int> ans;
		queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it);
	        }
	    }
	    
	    return ans;
	}

    //-------------------------------------------------------------------
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[1000];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
