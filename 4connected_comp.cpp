#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& ans,vector<vector<int>>& edge,vector<int>& vis)
{
    if(vis[node]==1) return;
    
    vis[node] = 1;
    ans.push_back(node);
    
    for(auto it: edge[node])
    {
        if(vis[it]==0)
        dfs(it,ans,edge,vis);
    }
}
  
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) 
{
    vector<vector<int>> graph(V);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0){
            vector<int> comp;
            dfs(i,comp,graph,vis);
            ans.push_back(comp);
        }
    }
    
    return ans;
}

int main()
{
    int ver,edges;
    cin>>ver>>edges;

    vector<vector<int>> ed(edges, vector<int> (2,0));
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;

        ed[i][0] = u;
        ed[i][1] = v;
    }

    vector<vector<int>> ans = getComponents(ver,ed);
    
    int cnt = 1;
    for(auto it: ans)
    {
      cout<<"component : "<<cnt++<<endl;
      for(auto i:it)
      cout<<i<<" ";
      
      cout<<endl;
    }

    return 0;
}

