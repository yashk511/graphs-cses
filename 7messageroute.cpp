#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n,vector<vector<int>> graph)
{
    vector<int> ans,vis(n,0);

    queue<int> q;
    q.push(0);

    vector<int> parent(n,-1);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it: graph[node])
        {
            if(vis[it]==0)
            {
                q.push(it);
                vis[it] = 1;
                parent[it] = node;
            }
        }
    }
    
    if(vis[n-1]==0) return {};

    int curr = n-1;
    while(curr)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(curr);
    
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

    vector<int> ans = solve(n,graph);
    
    if(ans.size()==0) cout<<"IMPOSSIBLE";
    else
    {
      cout<<ans.size()<<endl;
      reverse(ans.begin(),ans.end());
      for(auto it: ans) cout<<it+1<<" "; 
    }

    return 0;
}