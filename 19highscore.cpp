#include<bits/stdc++.h>
using namespace std;
 
bool dfs(int n,int node,vector<vector<pair<int,int>>>& graph_list,vector<int>& vis)
{
    if(node==n-1) return true;
    if(vis[node]!=0) return false;
 
    vis[node] = 1;
 
    for(auto vertex: graph_list[node])
    {
        if(vis[vertex.first]==0)
            if(dfs(n,vertex.first,graph_list,vis)) 
                return true;
    }
 
    return false;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    vector<vector<int>>edges(m);
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
          
        a--,b--;
 
        adj[a].push_back({b,c});
        edges[i] = {a,b,c};
    }
    
    vector<long long> dis(n,-1e18);
    dis[0] = 0;
 
    for(int i=1;i<n;i++)
    {
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dis[u]!=-1e18 && dis[u]+wt > dis[v])
            {
                dis[v] = dis[u]+wt;
            }
        }
    }
 
    int f = 0;
    vector<int> vis(n,0);
    for(auto it: edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
 
        if(dis[u]!=-1e18 && dis[u]+wt > dis[v])
        {
            if(!vis[u])
            f = dfs(n,u,adj,vis);
            if(f) break;
        }
    }

    if(f) cout<<"-1";
    else cout<<dis[n-1];
    
 
    return 0;
}