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

bool dfs(int& n,int& m,int dir,int r,int c,int& cnt,
vector<vector<pair<vector<int>,bool>>>& vis,vector<vector<char>>& graph,int& mir)
{
    if(mir==cnt) return true;
    if(vis[r][c].first[dir]) return false;

    vis[r][c].first[dir] = 1;

    if(graph[r][c]=='.'){
        if(dir==0){
            if(r+1<n && vis[r+1][c].first[dir]==0){
                if(dfs(n,m,dir,r+1,c,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==1){
            if(c-1>=0 && vis[r][c-1].first[dir]==0){
                if(dfs(n,m,dir,r,c-1,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==2){
            if(r-1>=0 && vis[r-1][c].first[dir]==0){
                if(dfs(n,m,dir,r-1,c,cnt,vis,graph,mir)) return true;
            }
        }
        else{
            if(c+1<m && vis[r][c+1].first[dir]==0){
                if(dfs(n,m,dir,r,c+1,cnt,vis,graph,mir)) return true;
            }
        }
    }
    else if(graph[r][c]=='/'){
        mir++;
        if(dir==0){
            dir = 1;
            if(c-1>=0 && vis[r][c-1].first[dir]==0){
                if(dfs(n,m,dir,r,c-1,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==1){
            dir = 0;
            if(r+1<n && vis[r+1][c].first[dir]==0){
                if(dfs(n,m,dir,r+1,c,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==2){
            dir = 3;
            if(c+1<m && vis[r][c+1].first[dir]==0){
                if(dfs(n,m,dir,r,c+1,cnt,vis,graph,mir)) return true;
            }
        }
        else{
            dir = 2;
            if(r-1>=0 && vis[r-1][c].first[dir]==0){
                if(dfs(n,m,dir,r-1,c,cnt,vis,graph,mir)) return true;
            }
        }
    }
    else{
        mir++;
        if(dir==0){
            dir = 3;
            if(c+1<m && vis[r][c+1].first[dir]==0){
                if(dfs(n,m,dir,r,c+1,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==1){
            dir = 2;
            if(r-1>=0 && vis[r-1][c].first[dir]==0){
                if(dfs(n,m,dir,r-1,c,cnt,vis,graph,mir)) return true;
            }
        }
        else if(dir==2){
            dir = 1;
            if(c-1>=0 && vis[r][c-1].first[dir]==0){
                if(dfs(n,m,dir,r,c-1,cnt,vis,graph,mir)) return true;
            }
        }
        else{
            dir = 0;
            if(r+1<n && vis[r+1][c].first[dir]==0){
                if(dfs(n,m,dir,r+1,c,cnt,vis,graph,mir)) return true;
            }
        }
    }
}

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;

    int cnt = 0;
    vector<vector<char>> graph(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;

            graph[i].push_back(c);

            if(c=='\\' || c=='/'){
                cnt++;
            }
        }
    }    

    vector<vector<pair<vector<int>,bool>>> vis(n,vector<pair<vector<int>,bool>> (m,{{0,0,0,0},false}));

    int r = 0;
    int d1 = 0;
    int mir = 0;
    for(int i=0;i<m;i++)
    {
        if(vis[0][i].first[0]==0){
            auto ans = dfs(n,m,d1,r,i,cnt,vis,graph,mir);
        }
    }



    return 0;
}
