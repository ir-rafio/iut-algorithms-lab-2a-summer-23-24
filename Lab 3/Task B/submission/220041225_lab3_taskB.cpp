#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const int N=1e5+10;
vector<vector<int>>adj(N);
bool visited[N]={false};

void pre()
{
    fastio;


}

int dfs(int x){
    visited[x]=true;
    int c=1;

    for(auto& u:adj[x]){
        if(!visited[u]){
            c+=dfs(u);
        }
    }
    return c;
}

void solve(int tc)
{
    int n,p;
    cin>>n>>p;

    int a,b;
    while(p--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x=0;
    vector<int>con(n);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            con.push_back(dfs(i));
            x++;
        }
    }
    long long sum=0;
     sz=0;
    con.resize(x);
    for(int i=0;i<con.size();i++){
        sz+=(con[i]*sum);
        sum+=con[i];
    }
    cout<<sz;
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
