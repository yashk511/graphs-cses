#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int node, vector<vector<int>>& graph, vector<int>& dp, vector<int>& next) {
    if (node == n - 1) return dp[node] = 1;

    if (dp[node] != -1) return dp[node];

    dp[node] = 0; 
    
    for (int it : graph[node]) {
        int res = dfs(n, it, graph, dp, next);
        if (res != 0 && res + 1 > dp[node]) {
            dp[node] = res + 1;
            next[node] = it;
        }
    }

    return dp[node];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph_list(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph_list[u].push_back(v);
    }

    vector<int> dp(n, -1), next(n, -1);
    int ans = dfs(n, 0, graph_list, dp, next);

    if (ans == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans << "\n";

    int i = 0;
    while (i != -1) {
        cout << i + 1 << " ";
        if (i == n - 1) break;
        i = next[i];
    }

    return 0;
}
