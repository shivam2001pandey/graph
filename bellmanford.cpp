#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> q1;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    
}
void bellman_ford(vector<pair<int,int> > adj[],int src,int v){
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int v=it.first;
            int wt=it.second;
            if(dist[v]>dist[i]+wt){
                dist[v]=dist[i]+wt;
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" @ "<<dist[i]<<endl;
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
    
    
    int src;
    cin>>src;
    bellman_ford(adj,src,v);
   
	return 0;
}
