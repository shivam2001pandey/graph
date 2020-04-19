//wap to revise whether a graph contains cycle or not using bfs
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class graph {
		int v;
		vector<int>flag;

	public:
		graph(int vertices) {
			v=vertices;
			for(int i=0; i<v; i++)
				flag[i]=-1;

		}
		void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight) {
			adj[snode].push_back(make_pair(enode,weight));
		}

		bool isCycle(vector<pair<int,int> >adj[],int src) {
			queue<int>q;
			q.push(src);
			flag[src]=0;
			while(!q.empty()) {
				int num=q.front();
				q.pop();
				flag[num]=1;
				for(vector<pair<int,int> >::const_iterator it=adj[num].begin(); it!=adj[num].end(); it++) {
					if(flag[it->first]==-1) {
						q.push(it->first);
						flag[it->first]=0;
					} else if(flag[it->first]==0)

						return true;

				}
			}
			return false;

		}
};
int main() {

	int vertices=5;
	graph g(5);
	vector<pair<int,int> > adj[vertices];
	g.addEdge(adj,0,1,10);
	g.addEdge(adj,0,2,30);
	g.addEdge(adj,1,3,40);
	g.addEdge(adj,3,4,50);
	g.addEdge(adj,4,1,60);
/*
	if(g.isCycle(adj,0)==true)
		cout<<"\nGraph is cyclic";
	else
		cout<<"\nGraph is acyclic";
*/
	return 0;

}
