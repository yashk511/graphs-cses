#include<bits/stdc++.h>
using namespace std;

bool isbipartite_bfs(int i,int n,vector<vector<int>>& graph,vector<int>& color)
{
    queue<int> q;
    q.push(i);

    color[i] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it: graph[node])
        {
            if(color[it]==-1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
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
      ans = isbipartite_bfs(i,n,graph,color);
      if(ans==0) break;
    }
    cout<<ans<<endl;

    return 0;
}