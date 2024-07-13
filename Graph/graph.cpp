#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template<typename T>

class Graph{

public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);
        if(direction == 0)
            adj[v].push_back(u);
    }

    void print(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n,m,d;
    Graph<char> g;

    cout<<"Enter the no. of nodes - ";
    cin>>n;

    cout<<"Enter the no. of edges - ";
    cin>>m;

    cout<<"Enter the direction - ";
    cin>>d;

    cout<<"Enter the edges ->"<<endl;
    for(int i=0; i<m; i++){
        char u,v;
        cin>>u>>v;

        g.addEdge(u,v,d);
    }

    g.print();
    return 0;
}