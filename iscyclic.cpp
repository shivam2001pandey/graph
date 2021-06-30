//Program to check whether the graph is acyclic
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
bool bfs(vector<pair<int,int>> adj[],bool visited[],int src){
    queue<pair<int,string>> q;
    q.push({src,to_string(src)});
    while(!q.empty()){
        auto num=q.front();
        q.pop();
        if(visited[num.first]==true)
          return true;
        visited[num.first]=true;
       
        for(auto it:adj[num.first]){
            if(visited[it.first]==false)
              {   string path=num.second+to_string(it.first);
                  q.push({it.first,path});
              }
        }
    }
    return false;
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
    bool cycle=true;
    bool visited[v]={false};
    for(int i=0;i<v;i++){
        if(visited[v]==false){
             cycle=bfs(adj,visited,i);
             if(cycle==false)
              cycle=false;
            break;
             }
        }
    std::cout << cycle << std::endl;
	return 0;
}
