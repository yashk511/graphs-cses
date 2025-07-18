#include<bits/stdc++.h>
using namespace std;

// cycle detection using dfs directed graph

bool solve(int i,int parent,int n,vector<vector<int>>& graph,vector<int>& vis,vector<int>& path,vector<int>& pathvis,int& st,int& end)
{
    vis[i] = 1;
    path[i] = parent;
    pathvis[i] = 1;

    for(auto it: graph[i])
    {
        if(vis[it]==0)
        {
            if(solve(it,i,n,graph,vis,path,pathvis,st,end)==true) return true;
        }
        else if(pathvis[it]) {
            st = it;
            end = i;
            return true;
        }
    }

    pathvis[i] = 0;
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
        // graph[v].push_back(u);
    }
    
    vector<int> path(n,0),pathvis(n,0);
    vector<int> vis(n,0);
    
    int st = -1;
    int end = -1;
    bool cycle_found = false;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (solve(i ,-1 , n, graph, vis,path,pathvis,st,end)) {
                cycle_found = true;
                break;
            }
        }
    }

    if (cycle_found)
    {
        vector<int> cyc;
        cyc.push_back(st+1);
        while(st!=end)
        {
            cyc.push_back(end+1);
            end = path[end];
        }
        cyc.push_back(end+1);

        reverse(cyc.begin(),cyc.end());
        
        cout<<cyc.size()<<"\n";
        for(auto it: cyc) cout<<it<<" ";
    }
    else cout << "IMPOSSIBLE";
        
    return 0;
}

