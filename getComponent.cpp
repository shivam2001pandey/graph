#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
vector<vector<int>> comps;
void generateGraph(bool visited[],vector<pair<int,int>> adj[],int src,vector<int> &comp){
    visited[src]=true;
    comp.push_back(src);
    for(auto it:adj[src]){
        if(visited[it.first]==false)
          generateGraph(visited,adj,it.first,comp);
    }
}
void getConnectedGraph(bool visited[],vector<pair<int,int>> adj[],int v){
    for(int i=0;i<v;i++){            
         if(visited[i]==false){
             vector<int> comp;
             generateGraph(visited,adj,i,comp);
             comps.push_back(comp);
         }
    }
    for(int i=0;i<comps.size();i++){cout<<endl;
      for(int j=0;j<comps[i].size();j++)
      std::cout << comps[i][j];
}
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        addEdge(adj,s,d,w);
    }
    
    bool visited[v];
    memset(visited,false,sizeof(visited));
    getConnectedGraph(visited,adj,v);
    
    return 0;
}
