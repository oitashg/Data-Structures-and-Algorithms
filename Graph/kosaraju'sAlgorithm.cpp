#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//-------------------------This algorithm is valid only for directed graphs-------------------------------
//----------------------It is used to find no. of strongly connected components---------------------------

class Solution
{
	public:
    //----------------------Kosaraju's Algorithm-----------------------------------

	void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it, vis, adj, st);
	        }
	    }
	    
	    st.push(node);
	}
	
	void dfs3(int node, vector<int>& vis, vector<int> adjT[]){
	    vis[node] = 1;
	    
	    for(auto it: adjT[node]){
	        if(!vis[it]){
	            dfs3(it, vis, adjT);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        
        //dfs and storing the nodes in order of finishing time in stack
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        //reversing the graph..i.e...reversing all the edges
        vector<int> adjT[1000];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                //first--- i->it
                //now---- it->i
                adjT[it].push_back(i);
            }
        }
        
        //again doing dfs to get the no. of strongly connected components
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        
        return scc;
    }

    //------------------------------------------------------------------------
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}