#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;


class Solution {
  public:
    //----------------For Directed Acyclic Graphs(DAG)(weighted)---------------------

    void topoSort(int node, vector<int>& vis, vector<pair<int,int>> adj[], stack<int>& s){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v])
                topoSort(v, vis, adj, s);
        }
        
        s.push(node);
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& e){
        vector<pair<int,int>> adj[1000];
        
        //creating the adjacency list
        for(int i=0; i<M; i++){
            int u = e[i][0];
            int v = e[i][1];
            int wt = e[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        //do the topo sort
        vector<int> vis(N,0);
        stack<int> s;
        
        for(int i=0; i<N; i++){
            if(!vis[i])
                topoSort(i, vis, adj, s);
        }
        
        //do the distance calculation
        vector<int> dist(N, 1e9);
        
        dist[0] = 0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        
        return dist;
    }

    //-----------------------For undirected weighted graphs----------------------------

    vector<int> shortestPath(vector<vector<int>>& e, int N,int M, int src){
        vector<pair<int,int>> adj[1000];
        
        //creating adjacency list
        for(int i=0; i<M; i++){
            int u = e[i][0];
            int v = e[i][1];
            int wt = 1; //can be any weight
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            int node = q.front().first;
            q.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    q.push({v,dist[v]});
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        
        return dist;
    }

    //----------------------------------------------------------------------------------
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}