#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
#define vll vector<ll>
const ll INF = 1e18;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        graph[u].emplace_back(v, d);
    }

    vll dist(n, INF);
    vll routes(n, 0);
    vector<int> minFlights(n, INT_MAX);
    vector<int> maxFlights(n, INT_MIN);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0] = 0;
    routes[0] = 1;
    minFlights[0] = 0;
    maxFlights[0] = 0;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        auto d = pq.top().first; 
        auto node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto it : graph[node]) {
            int adj = it.first;
            ll wt = it.second;
            if (dist[adj] > dist[node] + wt) {
                dist[adj] = dist[node] + wt;
                routes[adj] = routes[node];
                minFlights[adj] = minFlights[node] + 1;
                maxFlights[adj] = maxFlights[node] + 1;
                pq.push({dist[adj], adj});
            }
            else if (dist[adj] == dist[node] + wt) {
                routes[adj] = (routes[adj] + routes[node]) % MOD;
                minFlights[adj] = min(minFlights[adj], minFlights[node] + 1);
                maxFlights[adj] = max(maxFlights[adj], maxFlights[node] + 1);
            }
        }
    }

    cout << dist[n - 1] << " ";
    cout << routes[n - 1] << " ";
    cout << minFlights[n - 1] << " " << maxFlights[n - 1] << '\n';

    return 0;
}
