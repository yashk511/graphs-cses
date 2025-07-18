#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& adj,vector<vector<int>>& vis,int row,int col,int& n,int& m)
{
    if(vis[row][col]==1) return;

    vis[row][col] = 1;

    // left
    if(col-1>=0 && adj[row][col-1]=='.')
    dfs(adj,vis,row,col-1,n,m);

    //right
    if(col+1<m && adj[row][col+1]=='.')
    dfs(adj,vis,row,col+1,n,m);

    // up
    if(row-1>=0 && adj[row-1][col]=='.')
    dfs(adj,vis,row-1,col,n,m);

    // dowm
    if(row+1<n && adj[row+1][col]=='.')
    dfs(adj,vis,row+1,col,n,m);
}

int solve(int n,int m,vector<vector<char>> adj)
{
    vector<vector<int>> vis(n,vector<int> (m,0));

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]=='.' && vis[i][j]==0)
            {
                dfs(adj,vis,i,j,n,m);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>> adj(n,vector<char> (m,'#'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;

            adj[i][j] = c;
        }
    }

    cout<<solve(n,m,adj);

    return 0;
}
