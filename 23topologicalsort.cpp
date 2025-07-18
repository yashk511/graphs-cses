#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>& graph_list,vector<int>& vis,stack<int>& st,vector<int>& pathvis)
{
    if(vis[node]!=0) return false;

    pathvis[node] = 1;
    vis[node] = 1;

    for(auto vertex: graph_list[node])
    {
        if(vis[vertex]==0){
            if(dfs(vertex,graph_list,vis,st,pathvis)) return true;
        } else if(pathvis[vertex]) {
            return true;
        }
    }

    pathvis[node] = 0;
    st.push(node);
    
    return false;
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
        
        u--,v--;
        
        graph_list[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n,0),pathvis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0){
            if(dfs(i,graph_list,vis,st,pathvis)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    vector<int> topological_order;
    while(!st.empty())
    {
        topological_order.push_back(st.top()+1);
        st.pop();
    }

    for(auto it: topological_order) cout<<it<<" ";

    return 0;
}
