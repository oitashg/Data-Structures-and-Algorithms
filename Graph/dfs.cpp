#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, vector<int> &ans){
        ans.push_back(node);
        visited[node] = 1;

        for(auto neighbours: adj[node]){
            if(!visited[neighbours]){
                dfs(adj, visited, neighbours, ans);
            }
        }
    }

    vector<int> dfsTraversal(int node, vector<pair<int, int>> &edges){
        unordered_map<int, bool> visited;
        vector<int> ans;

        //for disconnected graph
        for(int i=1; i<=node; i++){
            if(!visited[i])
                dfs(adj, visited, i, ans);
        }

        cout<<"The DFS traversal is -> "<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }

        return ans;
    }
};

int main(){
    int n,m,d;
    Graph g;
    vector<pair<int,int>> edges;

    cout<<"Enter the no. of nodes - ";
    cin>>n;

    cout<<"Enter the no. of edges - ";
    cin>>m;

    cout<<"Enter the direction - ";
    cin>>d;

    //adjacency list creation
    cout<<"Enter the edges ->"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        edges.push_back({u,v});

        g.addEdge(u,v,d);
    }

    g.printAdjList();
    g.dfsTraversal(n, edges);

    return 0;
}