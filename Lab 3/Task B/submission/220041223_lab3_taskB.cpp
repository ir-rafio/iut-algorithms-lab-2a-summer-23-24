#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


vector<vector<int>> adj(100000);
vector<bool> visited(100000, false);
vector<int>country;


void pre()
{
    fastio;


}

int dfs(int n){
    visited[n]= true;
    int count =1;

    for(auto k : adj[n]){
        if(visited[k]==false){
            count+= dfs(k);
        }
    }
    return count;
}

signed main()
{
    pre();


    int n, p, u, v;

    cin>>n>>p;



    for(int i =0; i<p; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i =0; i<n; i++){
        if(visited[i]==false){
            int s = dfs(i);
            country.push_back(s);
        }
    }

    long long total = 0;

    for(int s : country){
        total += s*(n-s);
    }


    cout<<total/2<<endl;


    return 0;
}
