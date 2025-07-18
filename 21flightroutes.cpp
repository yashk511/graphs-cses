#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,long long>>> graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        long long wt;
        cin>>u>>v>>wt;

        u--,v--;

        graph[u].push_back({v,wt});
    }

    vector<long long> dis(n,LLONG_MAX);
    dis[0] = 0;

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    priority_queue<long long> cost[n];
    pq.push({0,0});
    cost[0].push(0);

    while(!pq.empty())
    {
        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d>cost[node].top()) continue;

        for(auto it: graph[node])
        {
            int adjnode = it.first;
            long long wt = it.second;

            if(cost[adjnode].size()<k)
            {
                dis[adjnode] = d+wt;
                cost[adjnode].push(dis[adjnode]);
                pq.push({dis[adjnode],adjnode});
            }
            else if(cost[adjnode].top()>d+wt)
            {
                cost[adjnode].pop();
                cost[adjnode].push(d+wt);
                dis[adjnode] = d+wt;
                pq.push({dis[adjnode],adjnode});
            }
        }
    }
    
    vector<long long> ans;
    priority_queue<long long> temp = cost[n-1];
    while (!temp.empty()) {
        ans.push_back(temp.top());
        temp.pop();
    }
    
    reverse(ans.begin(),ans.end());
    for(auto it: ans) cout<<it<<" ";
    
    return 0;
}