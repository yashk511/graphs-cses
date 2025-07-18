#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
          
        a--,b--;
       
        edges[i] = {a,b,c};
    }

    vector<long long> dis(n,1e18);
    dis[0] = 0;

    for(int i=1;i<n;i++)
    {
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dis[u]!=1e18 && dis[u]+wt < dis[v])
            {
                dis[v] = dis[u]+wt;
            }
        }
    }

    int f = 0;
    for(auto it: edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dis[u]!=1e18 && dis[u]+wt < dis[v])
        {
            f = 1;
            break;
        }
    }

    if(f) cout<<"negative cycle detected\n";
    else
    {
        for(auto it: dis)
        {
            if(it!=1e18)
            cout<<it<<" ";
            else
            cout<<"INF"<<" ";
        }
    }

    return 0;
}