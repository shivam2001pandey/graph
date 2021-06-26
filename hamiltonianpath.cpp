//Program to print all hamiltonian path or cycle
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void hamiltonian(unordered_set<int> visited,vector<pair<int,int> > adj[],string path,int src,int osrc){
    if(visited.size()==adj.size()-1){
        std::cout << path;
        bool hamiltonianCycle=false;
        for(auto i:adj[src]){
            if(i.first==osrc)
             hamiltonianCycle=true;
        }
        if(hamiltonianCycle==true)
          cout<<"*"<<endl;
        else
          cout<<"."<<endl;
    }
    
    visited.insert(src);
    for(auto it: adj[src]){
        if(visited.count(it.first)==0){
            hamiltonian(visited,adj,path+to_string(it.first),it.first,osrc);
        }
    }
    visited.erase(src);
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
     unordered_set<int> visited;
    int src;
    cin>>src;
    string path=to_string(src);
    hamiltonian(visited,adj,path,src,src);
    return 0;
}
