#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

}

bool dfs(int &i, int &sum,int &num,int avg ,vector<int>v,vector<vector<int>>&adj ,vector<int>&visited)
{
    
    visited[i]=1;
    sum+=v[i];
    num+=1;
    for(auto child: adj[i])
    {
        if(visited[child]==1)
        {
            continue;
        }
        dfs(child,sum,num,avg,v,adj,visited);
    }
    if(sum%num!=0)
    {
        return false;
    }
    else
    {
        return (sum/num)==avg;
    }
}

void solve(int tc)
{
    int n , m ;
    cin >> n >> m ;
    vector<int>v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    vector<vector<int>>adj(n+1);
    while(m--)
    {
        int x, y ;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(sum%n!=0)
    {
        cout<<"No\n";
        return;
    }
    int avg=sum/n;
    vector<int>visited(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int sum=0,num=0;
        bool ki=true;
        if(visited[i]!=1)
            ki=dfs(i,sum,num,avg,v,adj,visited);
        if(ki==false)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        //cout << '\n';
    }

    return 0;
}