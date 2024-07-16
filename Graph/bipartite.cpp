#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:

    //--------------------------BFS------------------------------------------

    bool bfs(int start, vector<int>& c, vector<int>adj[]){
        c[start] = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(c[it] == -1){
                    c[it] = !c[node];
                    q.push(it);
                }
                else if(c[it] == c[node])
                    return false;
            }
        }
        
        return true;
    }

    bool isBipartite(int V, vector<int>adj[]){
	    vector<int> c(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(c[i] == -1){
	            bool ans = bfs(i, c, adj);
	            if(!ans) return false;
	        }
	    }
	    
	    return true;
	}

    //--------------------------DFS------------------------------------------
    
    bool dfs(int node, int prev, vector<int>& c, vector<int>adj[]){
        c[node] = prev;
        
        for(auto it: adj[node]){
            if(c[it] == -1){
                bool ans = dfs(it, !prev, c, adj);
                if(!ans) return false;
            }
            else if(c[it] == prev)
                return false;
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> c(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(c[i] == -1){
	            bool ans = dfs(i, 0, c, adj);
	            if(!ans) return false;
	        }
	    }
	    
	    return true;
	}

    //----------------------------------------------------------------------
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
