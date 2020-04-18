//wap to implement BFS in graph (undirected and weighted graph)
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight)
{
	adj[snode].push_back(make_pair(enode,weight));
	adj[enode].push_back(make_pair(snode,weight));
}

bool isCyclic(int vertices,vector<pair<int,int> >adj[],int src)
{
	int temp=0;
	vector<int> flag(vertices,-1);
	
	queue<int> q;
	
	q.push(src);
	flag[src]=0;	
	while(!q.empty())
	{
		int num=q.front();
			
		q.pop();
		flag[num]=1;
		for(vector < pair<int,int> >::const_iterator it = adj[num].begin() ; it!=adj[num].end();it++)

		{
		 if(flag[it->first]==-1)
		 {	
		 	q.push(it->first);
		 	flag[it->first]=0;
		 }
		 else if(flag[it->first]==0)
			 return true;
		}
	
	}
		return false;
}
int main()
{	
	int vertices=3;
	vector<pair<int,int> > adj[vertices];
    addEdge(adj, 0, 1, 20); 
    addEdge(adj, 2, 1, 30); 
    cout<<"\nCycle Detection of the graph using BFS Traversal"; 
    if(isCyclic(vertices,adj,0))
		cout<<"\nThe Graph is Cyclic";
	else
		cout<<"\nThe Graph is not Cyclic";	
    
 	return 0;
    
}  
