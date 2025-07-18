#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        u--, v--;

        graph[u].push_back({v, d});
        // graph[v].push_back({u, d});
    }

    vector<long long> dis(n, 1e18); 
    dijkstra_algo(0, graph, dis);

    for (auto it : dis) cout << it << " ";
    cout << endl;

    return 0;
}
