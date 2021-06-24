#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
bool dfs(vector<pair<int,int>> adj[],bool visited[],int s,int d)
{
    if(s==d)
    {
        return true;
    }
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(visited[i.first]==false)
        {
            bool hasPath=dfs(adj,visited,i.first,d);
            if(hasPath==true)
              return true;
        }
    }
    return false;
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
    if(dfs(adj,visited,s,d)==true) cout<<"true";
    else cout<<"false";
    return 0;
}
