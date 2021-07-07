#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
bool isBipartite(vector<pair<int,int>> adj[],int visited[],int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    while(!q.empty()){
      auto num=q.front();
      q.pop();
      if(visited[num.first]==-1){
          if(visited[num.second]!=num.second)
            return false;
          
      }
        else{
            visited[num.first]=num.second;
        }
        for(auto it: adj[num.first]){
            if(visited[it.first]==-1)
              q.push({it.first,num.second+1});
        }
    }
    return true;
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
    bool bipartite=true;
    int visited[v]={-1};
    for(int i=0;i<v;i++){
        if(visited[v]==false){
             bipartite=isBipartite(adj,visited,i);
             if(bipartite==false)
              bipartite=false;
            break;
             }
        
  
   
        }
          std::cout << bipartite << std::endl;
	return 0;
}
