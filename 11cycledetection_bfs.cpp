#include<bits/stdc++.h>
using namespace std;

bool detectcycle_bfs(int i,int n,vector<vector<int>>& graph,vector<int>& vis)
{
    queue<pair<int,int>> q;
    q.push({i,-1});

    vis[i] = 1;

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(auto it: graph[node])
        {
            if(vis[it]==0)
            {
                q.push({it,node});
                vis[it] = 1;
            }
            else if(parent!=it)
            {
                return true;
            }
        }
    }

    return false;
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
    
    
    vector<int> vis(n,0);
    
    bool cycle_found = false;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (detectcycle_bfs(i, n, graph, vis)) {
                cycle_found = true;
                break;
            }
        }
    }

    if (cycle_found)
        cout << "cycle detected : yes\n";
    else
        cout << "cycle detected : no\n";
        
    return 0;
}