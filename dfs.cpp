#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void dfs(vector<pair<int,int>> adj[],bool visited[],int s,string path)
{
    
    visited[s]=true;
    std::cout << path << std::endl;
    for(auto i:adj[s])
    {
        if(visited[i.first]==false)
        {
            dfs(adj,visited,i.first,path+to_string(i.first));
            
        }
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
    int s,d;
    cin>>s;
    bool visited[v];
    memset(visited,false,sizeof(visited));
    string path=to_string(s);
    dfs(adj,visited,s,path);
    return 0;
}
