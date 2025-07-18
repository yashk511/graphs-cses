#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n - nodes/vertex, m - edges
    int n, m;       
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Validate input
    if (n <= 0 || m < 0) {
        cout << "Invalid input: Number of nodes must be positive and edges must be non-negative\n";
        return 1;
    }

    // Adjacency Matrix (Space Complexity: O(n²))
    // Each cell graph_mat[i][j] represents if there's an edge between node i and j
    vector<vector<int>> graph_mat(n, vector<int>(n, 0));
    
    // Adjacency List (Space Complexity: O(n + m))
    // Each vector graph_list[i] contains all neighbors of node i
    vector<vector<int>> graph_list(n);

    cout << "\nEnter " << m << " edges (u v format, where u and v are node numbers):\n";
    // Input edges once and build both matrix and list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Validate node numbers
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid node numbers. Nodes must be between 0 and " << n-1 << "\n";
            return 1;
        }

        // For undirected graph, add edge in both directions
        graph_mat[u][v] = 1;
        graph_mat[v][u] = 1;

        graph_list[u].push_back(v);
        graph_list[v].push_back(u);
    }

    // Print Adjacency Matrix
    cout << "\nAdjacency Matrix (1 indicates edge, 0 indicates no edge):\n";
    cout << "   ";
    for (int i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << graph_mat[i][j] << " ";
        }
        cout << endl;
    }

    // Print Adjacency List
    cout << "\nAdjacency List (shows neighbors for each node):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " -> ";
        for (int j = 0; j < graph_list[i].size(); j++)
        {
            cout << graph_list[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
