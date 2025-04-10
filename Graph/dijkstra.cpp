#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

//------------------------Dijkstra TC - ElogV(E = no. of edges and V = no. of nodes)------------------------
//------------------------Not applicable to negative edges or negative cycle--------------------------------

class Solution
{
public:
    //---------Function to find the shortest distance of all the vertices from the source vertex-------
    //----------------------------Dijkstra using priority queue---------------------------------

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }

    //---------------------Dijkstra using set---------------------------------

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it: adj[node]){
                int edgeW = it[1];
                int adjNode = it[0];
                
                if(dis + edgeW < dist[adjNode]){
                    //check if already visited/reached by someone or not
                    //if the node has been already been visited by someone, the entry must be prrsent in set
                    //now, when we can reach the node in a smaller distance, there is no need of keeping that {distance,node} pair in set
                    //that's why, we remove that and it can't be done in priority queue
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }

    //-----------------------------------------------------------------------
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[1000];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}