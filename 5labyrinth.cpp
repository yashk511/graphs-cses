#include<bits/stdc++.h>
using namespace std;

pair<string,string> solve(pair<int,int> st,vector<vector<char>> adj,vector<vector<int>> vis,int n,int m)
{
    queue<pair<int,int>> q;
    q.push(st);

    vis[st.first][st.second] = 1;

    vector<vector<pair<pair<int,int>,char>>> dir(n,vector<pair<pair<int,int>,char>> (m,{{-1,-1},'.'}));
    
    pair<int,int> end = {-1,-1};
    
    int f = 0;
    while(!q.empty())
    {
        pair<int,int> pos = q.front();
        q.pop();

        int col = pos.second;
        int row = pos.first;

        if(adj[row][col]=='B')
        {
            end = pos;
            f = 1;
            string path = "";
            auto curr = end;
            while(curr!=st)
            {
              path += dir[curr.first][curr.second].second;
              curr = dir[curr.first][curr.second].first;
            }
            
            reverse(path.begin(),path.end());
            
            return {"YES",path};
        }

        if(col-1>=0 && (adj[row][col-1]=='.' || adj[row][col-1]=='B')  && vis[row][col-1]==0)
        {
            q.push({row,col-1});
            vis[row][col-1] = 1;
            dir[row][col-1] = {{row,col},'L'};
        }

        if(col+1<m && (adj[row][col+1]=='.' || adj[row][col+1]=='B') && vis[row][col+1]==0)
        {
            q.push({row,col+1});
            vis[row][col+1] = 1;
            dir[row][col+1] = {{row,col},'R'};
        }

        if(row-1>=0 && (adj[row-1][col]=='.' || adj[row-1][col]=='B') && vis[row-1][col]==0)
        {
            q.push({row-1,col});
            vis[row-1][col] = 1;
            dir[row-1][col] = {{row,col},'U'};
        }

        if(row+1<n && (adj[row+1][col]=='.' || adj[row+1][col]=='B') && vis[row+1][col]==0)
        {
            q.push({row+1,col});
            vis[row+1][col] = 1;
            dir[row+1][col] = {{row,col},'D'};
        }
    }
    
    return{"NO",""};
}

int main()
{
    int n,m;
    cin>>n>>m;

    pair<int,int> st;
    vector<vector<char>> graph(n,vector<char> (m,'.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;

            graph[i][j] = c;

            if(c=='A'){
            st.first = i;
            st.second = j;
            }
        }
    }

    vector<vector<int>> vis(n,vector<int> (m,0));
    pair<string,string> ans = solve(st,graph,vis,n,m);
    
    if(ans.first=="YES")
    cout<<ans.first<<endl<<ans.second.size()<<endl<<ans.second;
    else cout<<"NO";

    return 0;
}