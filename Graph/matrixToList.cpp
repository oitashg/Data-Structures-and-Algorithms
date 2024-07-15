#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> adjList[V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 and i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
}