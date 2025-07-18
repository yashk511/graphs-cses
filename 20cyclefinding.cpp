#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    // Add a super source node 'n', connect to all nodes with 0 weight
    int super_source = n;
    for (int i = 0; i < n; i++) {
        edges.push_back({super_source, i, 0});
    }

    vector<long long> dis(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dis[super_source] = 0;

    int x = -1;
    for (int i = 0; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            if (dis[u] != INF && dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int y = x;
        for (int i = 0; i <= n; i++) y = parent[y];

        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
                cout << node + 1 << " ";
        cout << "\n";
    }

    return 0;
}
