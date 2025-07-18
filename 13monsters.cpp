#include<bits/stdc++.h>
using namespace std;
 
bool solve(int n, int m,pair<int,int> ini,vector<vector<int>>& dist,vector<vector<char>>& adj,vector<vector<pair<int,char>>>& dist_a,string& ans)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{ini},0});
 
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[ini.first][ini.second] = 1;
 
    dist_a[ini.first][ini.second] = {0,'I'};
 
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
 
        int row = node.first.first;
        int col = node.first.second;
        int d = node.second;
 
        dist_a[row][col].first = d;
 
        if(row==0 || row==n-1 || col==0 || col==m-1)
        {
            if(adj[row][col]=='.' && dist_a[row][col].first<dist[row][col])
            {
                char c = dist_a[row][col].second;
                while(c!='I')
                {
                  ans += c;
                  
                  if(c=='R') col-=1;
                  if(c=='L') col +=1;
                  if(c=='U') row +=1;
                  if(c=='D') row -=1;
                  
                  c = dist_a[row][col].second;
                }
                reverse(ans.begin(),ans.end());
                
                return true;
            }
        }
 
        if(col-1>=0 && adj[row][col-1]=='.' && vis[row][col-1]==0)
        q.push({{row,col-1},d+1}),vis[row][col-1] = 1,dist_a[row][col-1].second = 'L';
 
        if(col+1<m && adj[row][col+1]=='.' && vis[row][col+1]==0)
        q.push({{row,col+1},d+1}),vis[row][col+1] = 1,dist_a[row][col+1].second = 'R';
 
        if(row-1>=0 && adj[row-1][col]=='.' && vis[row-1][col]==0)
        q.push({{row-1,col},d+1}),vis[row-1][col] = 1,dist_a[row-1][col].second = 'U';
 
        if(row+1<n && adj[row+1][col]=='.' && vis[row+1][col]==0)
        q.push({{row+1,col},d+1}),vis[row+1][col] = 1,dist_a[row+1][col].second = 'D';
    }
 
    return false;
}
 
void cal_dist(int n, int m, vector<pair<int,int>>& mons, vector<vector<int>>& dist, vector<vector<char>>& adj)
{
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
 
    for(auto& ini : mons)
    {
        q.push(ini);
        vis[ini.first][ini.second] = 1;
        dist[ini.first][ini.second] = 0;
    }
 
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
 
    while(!q.empty())
    {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && adj[nx][ny] == '.')
            {
                dist[nx][ny] = dist[x][y] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    pair<int,int> st = {-1,-1};
    vector<pair<int,int>> mons;
    vector<vector<char>> graph(n, vector<char> (m,'.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
 
            if(graph[i][j]=='A')
            {
                st.first = i;
                st.second = j;
            }
            if(graph[i][j]=='M')
            {
                mons.push_back({i,j});
            }
        }
    }
 
    vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
    cal_dist(n,m,mons,dist,graph);
    
    
    string ans = "";
    vector<vector<pair<int,char>>> dist_a(n,vector<pair<int,char>> (m,{INT_MAX,'.'}));
    bool flag = solve(n,m,st,dist,graph,dist_a,ans);
    
    if(flag || st.first==0 || st.second==m-1 || st.first==n-1 || st.second==0)
    {
      cout<<"YES\n"<<ans.size()<<endl<<ans;
    }
    else cout<<"NO";
 
    return 0;
}