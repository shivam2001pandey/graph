#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void bfs(vector<pair<int,int>> adj[],bool visited[],int src){
    queue<pair<int,string>> q;
    q.push({src,to_string(src)});
    while(!q.empty()){
        auto num=q.front();
        q.pop();
        if(visited[num.first]==true)
          continue;
        visited[num.first]=true;
        std::cout << num.first<<"@"<<num.second << std::endl;
        for(auto it:adj[num.first]){
            if(visited[it.first]==false)
              {   string path=num.second+to_string(it.first);
                  q.push({it.first,path});
              }
        }
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
    bfs(adj,visited,src);
   
	return 0;
}
