#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //------------------------Function to find no. of brdiges in a graph-----------------------------------
    // Means, no. of edges upon removal of which the graph will be divided into multiple components

    // time of insertion which increases for each new node
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &t, vector<int> &low, vector<vector<int>> &ans){
        vis[node] = 1;
        t[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]){
            // if the adjacent node is parent, do nothing
            if (it == parent)
                continue;

            if (!vis[it]){
                dfs(it, node, vis, adj, t, low, ans);
                // after returning back, update the low array of current node
                // by comparing with the low array of the adjacent nodes i.e children
                // it indicates that how much lower can the node go via adjacent nodes
                low[node] = min(low[node], low[it]);

                // if low of child is more than time insertion of parent
                // means, it can never reach the parent if this edge gets removed
                // So, its a bridge
                // Eg:- low[it] = 6 and t[node] = 10 means
                //"node" is inserted at time 10 and the lowest time at which "it" can reach a node is the node whose
                // time of insertion is 6 i.e it can also reach "node" as its time of insertion is more than 6
                // So, not a bridge

                // Eg:- low[it] = 10 and t[node] = 6 means
                //"node" is inserted at time 6 and the lowest time at which "it" can reach a node is the node whose
                // time of insertion is 10 i.e it cannot reach "node" as its time of insertion is less than 10
                // So, its a bridge
                if (low[it] > t[node])
                    ans.push_back({node, it});
            }
            else{
                // if adjacent node already visited, so don't call dfs
                // just update the node's low array
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &c){
        int m = c.size();
        vector<int> adj[1000];

        // creating adjacency list
        for (int i = 0; i < m; i++){
            int u = c[i][0];
            int v = c[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //answer vector
        vector<vector<int>> ans;
        // visited array
        vector<int> vis(n, 0);
        // time insertion array of nodes i.e the time at which the node is visited
        vector<int> t(n);
        // lowest time array among all the adjacent nodes of a node
        vector<int> low(n);

        dfs(0, -1, vis, adj, t, low, ans);

        return ans;
    }

    //-----------------------------------------------------------------------------------------------
};