#include <bits/stdc++.h>
using namespace std;

void dijkstra_algo(int st, vector<vector<pair<int, int>>>& graph, vector<long long>& dis, vector<int>& parent)
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
                parent[adjnode] = node;
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
        graph[v].push_back({u, d});
    }

    vector<int> parent(n,-1);
    vector<long long> dis(n, 1e18); 
    dijkstra_algo(0, graph, dis, parent);

    // for (auto it : dis) cout << it << " ";
    // cout << endl;

    // for (auto it : parent) cout << it << " ";
    // cout << endl;

    if(parent[n-1]==-1)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> shortest_path;
    
    int st = 0;
    int end = n-1;
    shortest_path.push_back(end+1);
    while(st!=end)
    {
      end = parent[end];
      shortest_path.push_back(end+1);
    }
    
    reverse(shortest_path.begin(),shortest_path.end());
    
    cout<<shortest_path.size()<<endl;
    for(auto it: shortest_path) cout << it <<" ";
    
    return 0;
}
