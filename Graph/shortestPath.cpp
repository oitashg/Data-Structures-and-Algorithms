//--------------------For undirected graphs-------------------------

// #include<iostream>
// #include<algorithm> //include this to call the reverse function in vector
// #include<unordered_map>
// #include<list>
// #include<queue>
// using namespace std;

// class Graph{

// public:
//     unordered_map<int, list<int>> adj;

//     void addEdge(int u, int v, bool direction){
//         adj[u].push_back(v);
//         if(direction == 0)
//             adj[v].push_back(u);
//     }

//     void printAdjList(){
//         for(auto i: adj){
//             cout<<i.first<<" -> ";
//             for(auto j: i.second){
//                 cout<<j<<",";
//             }
//             cout<<endl;
//         }
//     }

//     void shortestPath(int src, int dest){
//         unordered_map<int,bool> visited;
//         unordered_map<int,int> parent;
//         queue<int> q;
//         vector<int> ans;

//         q.push(src);
//         visited[src] = 1;
//         parent[src] = -1;

//         while(!q.empty()){
//             int frontNode = q.front();
//             q.pop();

//             for(auto neighbours: adj[frontNode]){
//                 if(!visited[neighbours]){
//                     q.push(neighbours);
//                     visited[neighbours] = 1;
//                     parent[neighbours] = frontNode;
//                 }
//             }
//         }

//         int currentNode = dest;
//         ans.push_back(currentNode);
//         while(currentNode != src){
//             currentNode = parent[currentNode];
//             ans.push_back(currentNode);
//         }

//         reverse(ans.begin(), ans.end());

//         cout<<"The shortest path is - "<<endl;
//         for(int i=0; i<ans.size(); i++){
//             cout<<ans[i]<<" ";
//         }
//     }
// };

// int main(){
//     int n,m,s,t;
//     Graph g;
//     vector<pair<int,int>> edges;

//     cout<<"Enter the no. of nodes - ";
//     cin>>n;

//     cout<<"Enter the no. of edges - ";
//     cin>>m;

//     cout<<"Enter the source node - ";
//     cin>>s;

//     cout<<"Enter the destination node - ";
//     cin>>t;

//     //adjacency list creation
//     cout<<"Enter the edges ->"<<endl;
//     for(int i=0; i<m; i++){
//         int u,v;
//         cin>>u>>v;

//         edges.push_back({u,v});

//         g.addEdge(u,v,0);
//     }

//     g.printAdjList();
//     g.shortestPath(s, t);

//     return 0;
// }

//-----------------------For directed (weighted) acyclic graphs----------------------------

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;

class Graph{

public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"["<<j.first<<" "<<j.second<<"]"<<",";
            }
            cout<<endl;
        }
    }

    void topoSort(int node, unordered_map<int, bool>& visited, stack<int>& s){
        visited[node] = 1;

        for(auto neighbours: adj[node]){
            if(!visited[neighbours.first]){
                topoSort(neighbours.first, visited, s);
            }
        }

        s.push(node);
    }

    void shortestPath(int node, vector<pair<int, pair<int,int>>> &edges, int src){
        unordered_map<int, bool> visited;
        stack<int> s;

        for(int i=0; i<node; i++){
            if(!visited[i]){
                topoSort(i, visited, s);
            }
        }

        //vector<int> dist(INT_MAX);  //don't do this
        vector<int> dist(node);

        for(int i=0; i<node; i++){
            dist[i] = INT_MAX;
        }

        dist[src] = 0;

        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for(auto neighbours: adj[top]){
                    if(dist[top] + neighbours.second < dist[neighbours.first])
                        dist[neighbours.first] = dist[top] + neighbours.second;
                }
            }
        }

        for(int i=0; i<dist.size(); i++){
            cout<<dist[i]<<" ";
        }
    }
};

int main(){
    int n,m,s,t;
    Graph g;
    vector<pair<int,pair<int,int>>> edges;

    cout<<"Enter the no. of nodes - ";
    cin>>n;

    cout<<"Enter the no. of edges - ";
    cin>>m;

    cout<<"Enter the source node - ";
    cin>>s;

    // cout<<"Enter the destination node - ";
    // cin>>t;

    //adjacency list creation
    cout<<"Enter the edges ->"<<endl;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,{v,w}});

        g.addEdge(u,v,w);
    }

    g.printAdjList();
    g.shortestPath(n, edges, s);

    return 0;
}