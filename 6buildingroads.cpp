#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& graph,vector<int>& comp,vector<int>& vis)
{
    if(vis[node]==1) return;

    vis[node] = 1;
    comp.push_back(node);

    for(auto it: graph[node])
    {
        if(vis[it]==0)
        dfs(it,graph,comp,vis);
    }
}

vector<vector<int>> solve(int n,vector<vector<int>>& graph)
{
    vector<vector<int>> ans;
    vector<int> vis(n,0);

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            vector<int> comp;
            dfs(i,graph,comp,vis);
            ans.push_back(comp);
        }
    }

    return ans;
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

    vector<vector<int>> ans = solve(n,graph);
    
    cout<<ans.size()-1<<endl;

    if(ans.size()-1!=0)
    {
        for(int i=1;i<ans.size();i++)
        {
            cout<<ans[i-1][0]+1<<" "<<ans[i][0]+1<<endl;
        }
    }

    return 0;
}

