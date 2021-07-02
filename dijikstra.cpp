#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> q1;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void shortestpath( vector<pair<int,int>> adj[],int V,int src)
{

    priority_queue< q1, vector <q1> , greater<q1> > pq;

    vector<int> dist(V, INT_MAX);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty())
    {
        
        int u = pq.top().second;
        pq.pop();
  
        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i:adj[u])
        {
           
            int v = i.first;
            int weight = i.second;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
  
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
       cout<<i<<" @ "<<dist[i]<<endl;
}
int main() {
	int v,e;
	cin>>v>>e;
  vector<pair<int,int>> adj[v];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        addEdge(adj,s,d,w);
    }
   
    int src;
    cin>>src;
    shortestpath(adj,v,src);
    
   
	return 0;
}
