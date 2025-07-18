#include<bits/stdc++.h>
using namespace std;

void dijkstra_algo(int st, vector<vector<pair<int, int>>>& graph, vector<long long>& dis)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, st});
    dis[st] = 0;

    while (!pq.empty())
    {
        long long distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance > dis[node]) continue; 

        for (auto it : graph[node])
        {
            int adjnode = it.first;
            long long edge_wt = it.second;

            if (distance + edge_wt < dis[adjnode])
            {
                dis[adjnode] = distance + edge_wt;
                pq.push({dis[adjnode], adjnode});
            }
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n),radj(n);
    vector<vector<int>>edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
          
        a--,b--;
        
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
        edges[i] = {a,b,c};
    }

    vector<long long> dis1(n, 1e18); 
    dijkstra_algo(0, adj, dis1);

    vector<long long> dis2(n, 1e18); 
    dijkstra_algo(n-1, radj, dis2);

    long long ans = 1e18;
    for(auto it: edges)
    {
        long long wt1 = dis1[it[0]];
        long long wt2 = dis2[it[1]];
        long long ed = it[2]/2; 

        ans = min(ans,wt1+wt2+ed);
    }

    cout<<ans;

    return 0;
}