#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& graph_list,vector<int>& vis,vector<int>& ans)
{
    if(vis[node]!=0) return;

    vis[node] = 1;
    ans.push_back(node);

    for(auto vertex: graph_list[node])
    {
        if(vis[vertex]==0)
        dfs(vertex,graph_list,vis,ans);
    }
}

void bfs(int node,vector<vector<int>>& graph_list,vector<int>& vis,vector<int>& ans)
{
    queue<int> q;
    q.push(node);

    vis[node] = 1;
    ans.push_back(node);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto it: graph_list[x])
        {
            if(!vis[it])
            {
                q.push(it);
                ans.push_back(it);
                vis[it] = 1;
            }
        }
    }
}

int main()
{
    int n, m;       
    cin >> n >> m;

    vector<vector<int>> graph_list(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph_list[u].push_back(v);
        graph_list[v].push_back(u);
    }

    // dfs
    vector<int> vis1(n,0);
    vector<int> ans_dfs;
    dfs(0,graph_list,vis1,ans_dfs);

    cout<<"dfs : ";
    for(auto it: ans_dfs) cout<<it<<" ";

    // bfs
    vector<int> vis2(n,0);
    vector<int> ans_bfs;
    bfs(0,graph_list,vis2,ans_bfs);

    cout<<"\nbfs : ";
    for(auto it: ans_bfs) cout<<it<<" ";

    return 0;
}
