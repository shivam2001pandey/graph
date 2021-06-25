#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
string max_psf;
    string min_psf;
    int max_wsf=INT_MIN;
    int min_wsf=INT_MAX;
    string fpath;
    string cpath;
    int cweight=INT_MAX;
    int fweight=INT_MIN;
void dfs(vector<pair<int,int>> adj[],bool visited[],int s,int d,string path,int wsf,int criteria)
{
    
    if(s==d)
    {
        if(wsf>max_wsf)
          {
              max_psf=path;
              max_wsf=wsf;
          }
        if(wsf<min_wsf)
          {
              min_psf=path;
              min_wsf=wsf;
          }
        if(wsf<criteria && fweight<wsf)
           {
               fweight=wsf;
               fpath=path;
           }
           
        if(wsf>criteria && wsf<cweight)
           {
               cweight=wsf;
               cpath=path;
           }
        return;
    }
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(visited[i.first]==false)
        {
            dfs(adj,visited,i.first,d,path+to_string(i.first),wsf+i.second,criteria);
            
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
    int wsf=0;
    int criteria;
    cin>>criteria;
    dfs(adj,visited,s,d,path,wsf,criteria);
    std::cout << "maximum path:" <<max_psf<<"with max weight"<<max_wsf<<endl;
    std::cout << "minimum path:" <<min_psf<<"with min weight"<<min_wsf<<endl;
    std::cout << "floor path:" <<fpath<<"with  weight"<<fweight<<endl;
    std::cout << "ceil path:" <<cpath<<"with  weight"<<cweight<<endl;
    return 0;
}
