#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
#define int long long


void pre()
{
    fastio;

}

int dfs(int &i, int& num,vector<vector<int>>&v ,vector<int>&visited)
{
    
    visited[i]=1;
    num++;
    for(auto child: v[i])
    {
        if(visited[child]==1)
        {
            continue;
        }
        dfs(child,num,v,visited);
    }
    return num;
}

void solve(int tc)
{
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>>v(n);
    vector<int>visited(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int x , y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int res=0;
    vector<int>member(n,1);
    for(int i=0;i<n;i++)
    {
        int num=0;
        if(visited[i]!=1)
        {
            int a=dfs(i,num,v,visited);
            res+=a*(n-a);
        }

    }
    cout<<res/2<<endl;
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        //cout << "Case " << tc << ": ";
        solve(tc);
        //cout << '\n';
    }

    return 0;
}