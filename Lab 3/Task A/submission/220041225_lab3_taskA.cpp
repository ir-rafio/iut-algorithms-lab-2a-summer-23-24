#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void dfs(int x,vector<bool>&visited,vector<vector<long long>>adj,vector<long long>money,long long  &sum,int &count){
    visited[x]=true;
    sum+=money[x];
    count++;

    for(auto& u:adj[x]){
        if(!visited[u]){
            dfs(u,visited,adj,money,sum,count);
        }
    }
}

void solve(int tc)
{
    int n,m;
    cin>>n>>m;

    vector<long long>money(n);
    vector<vector<long long>>adj(n);
    vector<bool>visited(n,false);

    for(int i=0;i<n;i++){
        cin>>money[i];
    }

    int a,b;
    while(m--){
        cin>>a>>b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long sum=0;
    int count=0;

    bool is_possible=true;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            sum=0;
            count=0;
            dfs(i,visited,adj,money,sum,count);
            if(sum%count!=0){
                is_possible=false;
                break;
            }
        }
    }

    if(is_possible){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
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
        cout << '\n';
    }

    return 0;
}
