//---------------------------Topological Sort is only appliacble for Directed Acyclic Graph(DAG)---------------------------------------

// #include<iostream>
// #include<unordered_map>
// #include<list>
// #include<queue>
// #include<stack>
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

//     void topoDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, stack<int> &s){
//         visited[node] = 1;

//         for(auto neighbours: adj[node]){
//             if(!visited[neighbours])
//                 topoDFS(adj, visited, neighbours, s);
//         }

//         //pushing into stack while returning from recursion
//         s.push(node);
//     }

//     void topoSort(int node, vector<pair<int, int>> &edges){
//         unordered_map<int, bool> visited;
//         stack<int> s; //pass it by reference otherwise changes not reflected
//         vector<int> ans;

//         //for disconnected graph
//         for(int i=0; i<node; i++){
//             if(!visited[i])
//                 topoDFS(adj, visited, i, s);
//         }

//         while(!s.empty()){
//             ans.push_back(s.top());
//             s.pop();
//         }

//         cout<<"The topological sorting is -> "<<endl;
//         for(int i=0; i<ans.size(); i++){
//             cout<<ans[i]<<" ";
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

//         g.addEdge(u,v,1);
//     }

//     g.printAdjList();
//     g.topoSort(n, edges);

//     return 0;
// }

//------------------------------Using Kahn's Algorithm(BFS)(output not coming)---------------------------

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
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

    void topoBFS(int node, vector<pair<int, int>> &edges){
        vector<int> indegree(node);

        for(int i=0; i<indegree.size(); i++)
            indegree[i] = 0;

        for(auto i: adj){
            for(auto neighbours: i.second){
                indegree[neighbours]++;
            }
        }

        queue<int> q;
        
        for(int i=0; i<node; i++){
            if(indegree[i] == 0){
                q.push(i); //i equivalent to node
                cout<<q.front();
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto neighbours: adj[frontNode]){
                indegree[neighbours]--;
                if(indegree[neighbours] == 0){
                    q.push(neighbours);
                }
            }
        }

        cout<<"The topological sorting is -> "<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
};

int main(){
    int n,m;
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
    g.topoBFS(n, edges);

    return 0;
}