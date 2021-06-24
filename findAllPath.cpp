#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void dfs(vector<pair<int,int>> adj[],bool visited[],int s,int d,string path)
{
    if(s==d)
    {
        std::cout << path << std::endl;
        return;
    }
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(visited[i.first]==false)
        {
            dfs(adj,visited,i.first,d,path+to_string(i.first));
            
        }
    }
    visited[s]=false;
  
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
    cin>>s>>d;
    bool visited[v];
    memset(visited,false,sizeof(visited));
    string path=to_string(s);
    dfs(adj,visited,s,d,path);
    return 0;
}
