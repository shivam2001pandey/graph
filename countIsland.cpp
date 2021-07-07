#include<bits/stdc++.h>
using namespace std;

void countComponent(int arr[][1001],bool visited[][1001],int i,int j,int n,int m)
{
    if(i<0 or i>=n or j<0 or j>=m or arr[i][j]==1 or visited[i][j]==true) return;
    visited[i][j]=true;
     countComponent(arr,visited,i,j-1,m,n);
    countComponent(arr,visited,i+1,j,m,n);
    countComponent(arr,visited,i-1,j,m,n);
    countComponent(arr,visited,i,j+1,m,n);
   
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[1001][1001];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    bool visited[1001][1001];
    int count=0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==false and arr[i][j]==0)
            {
                countComponent(arr,visited,i,j,m,n);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
