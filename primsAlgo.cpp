#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> q1;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void prims(vector<pair<int,int>> adj[],bool visited[],int src,int v){
   priority_queue< q1, vector <q1> , greater<q1> > pq;
   vector<int> key(v, INT_MAX);
    vector<int> parent(v, -1);
    pq.push({0, src});
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(visited[u] == true){
            continue;
        }
       
        visited[u] = true;  // Include vertex in MST
 
        
        for (auto i:adj[u])
        {
            int v = i.first;
            int weight = i.second;
            if (visited[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for(int i=1;i<v;i++){
        cout<<i<<" "<<parent[i]<<" @ "<<key[i]<<endl;
    }
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
    bool visited[v]={false};
    
    int src;
    cin>>src;
    vector<int> key(v, INT_MAX);
 
    // To store parent array which in turn store MST
    vector<int> parent(v, -1);
    prims(adj,visited,src,v);
   
	return 0;
}
