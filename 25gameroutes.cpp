/* AUTHOR - YASH KULKARNI */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#define pri pair<int, int>
#define prll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define mapi map<int,int>
#define mapll map<ll,ll>
#define vpri vector<pri>
#define vprll vector<prll>

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb emplace_back

#define yes "YES"
#define no "NO"

const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;
const ll M = 1e9+7;

ll dfs(int n,int node,vector<vector<int>>& graph,vector<ll>& dp)
{
    if(node==n-1) return dp[n-1] = 1;

    if(dp[node]!=-1) return dp[node];

    dp[node] = 0;
    for(auto it: graph[node]){
      dp[node] = (dp[node]+dfs(n,it,graph,dp))%M;
    }
    
    return dp[node];
}

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph_list(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph_list[u].push_back(v);
    }
    
    vector<ll> dp(n,-1);
    cout<<dfs(n,0,graph_list,dp)<<endl;
    
    return 0;
}
