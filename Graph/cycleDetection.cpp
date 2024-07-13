//-------------------------------Undirected Graph-------------------------------------

// #include<iostream>
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

//     bool isCyclicBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node){
//         unordered_map<int, bool> parent;
//         queue<int> q;

//         parent[node] = -1;
//         visited[node] = true;

//         q.push(node);
//         while(!q.empty()){
//             int frontNode = q.front();
//             q.pop();

//             for(auto neighbours: adj[frontNode]){
//                 if(visited[neighbours] == 1 && neighbours!=parent[frontNode])
//                     return true; //cycle present

//                 else if(!visited[neighbours]){
//                     q.push(neighbours);
//                     visited[neighbours] = 1;
//                     parent[neighbours] = frontNode;
//                 }
//             }
//         }

//         return false;
//     }

//     bool isCyclicDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int parent){
//         visited[node] = 1;

//         for(auto neighbours: adj[node]){
//             if(!visited[neighbours]){
//                 bool cycleDetected = isCyclicDFS(adj, visited, neighbours, node);
//                 if(cycleDetected)
//                     return true;
//             }

//             else if(neighbours != parent)
//                 return true; //cycle present
//         }

//         return false;
//     }

//     bool checkCycle(int node, vector<pair<int, int>> &edges){
//         unordered_map<int, bool> visited;

//         for(int i=1; i<=node; i++){
//             //-----------BFS----------------

//             if(isCyclicBFS(adj, visited, i))
//                 return true;
//             else
//                 return false;

//             //-----------DFS------------------

//             // if(isCyclicDFS(adj, visited, i, -1))
//             //     return true;
//             // else
//             //     return false;

//         }
//     }
// };

// int main(){
//     int n,m,d;
//     Graph g;
//     vector<pair<int,int>> edges;

//     cout<<"Enter the no. of nodes - ";
//     cin>>n;

//     cout<<"Enter the no. of edges - ";
//     cin>>m;

//     //adjacency list creation
//     cout<<"Enter the edges ->"<<endl;
//     for(int i=0; i<m; i++){
//         int u,v;
//         cin>>u>>v;

//         edges.push_back({u,v});

//         g.addEdge(u,v,0);
//     }

//     g.printAdjList();

//     bool ans = g.checkCycle(n, edges);

//     if(ans)
//         cout<<"Cycle is present in the graph";
//     else
//         cout<<"Cycle is absent in the graph";

//     return 0;
// }

//-------------------------------Directed Graph-----------------------------------------

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

    // bool isCyclicBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node){
        
    // }

    bool isCyclicDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int node){
        visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto neighbours: adj[node]){
            if(!visited[neighbours]){
                bool cycleDetected = isCyclicDFS(adj, visited, dfsVisited, neighbours);
                if(cycleDetected)
                    return true;
            }

            else if(dfsVisited[neighbours])
                return true;
        }

        dfsVisited[node] = false;
        return false;
    }

    bool checkCycle(int node, vector<pair<int, int>> &edges){
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for(int i=0; i<node; i++){
            //-----------BFS----------------

            // if(isCyclicBFS(adj, visited, i))
            //     return true;
            // else
            //     return false;

            //-----------DFS------------------

            if(isCyclicDFS(adj, visited, dfsVisited, i))
                return true;
            else
                return false;

        }
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

    //adjacency list creation
    cout<<"Enter the edges ->"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        edges.push_back({u,v});

        g.addEdge(u,v,1);
    }

    g.printAdjList();

    bool ans = g.checkCycle(n, edges);

    if(ans)
        cout<<"Cycle is present in the graph";
    else
        cout<<"Cycle is absent in the graph";

    return 0;
}