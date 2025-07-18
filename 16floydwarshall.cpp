#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e15;
    vector<vector<long long>> graph(n, vector<long long>(n, INF));

    for (int i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        
        a--, b--;
        
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c); 
    }

    for (int i = 0; i < n; i++) graph[i][i] = 0;

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        
        a--, b--;
        
        if (graph[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << graph[a][b] << "\n";
    }

    return 0;
}
