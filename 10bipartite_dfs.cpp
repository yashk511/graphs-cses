#include<bits/stdc++.h>
using namespace std;

bool isbipartite_dfs(int i,vector<vector<int>>& graph,vector<int>& color,int c)
{
    color[i] = !c;

    for(auto it: graph[i])
    {
        if(color[it]==-1)
        {
            if(isbipartite_dfs(it,graph,color,color[i])==false) return false;
        }
        else if(color[it]==color[i]) return false;
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        u--,v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    bool ans = 0;
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
      if(color[i]==-1)
      ans = isbipartite_dfs(i,graph,color,1);
      if(ans==0) break;
    }
    cout<<ans<<endl;

    return 0;
}