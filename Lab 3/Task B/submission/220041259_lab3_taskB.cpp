#include <bits/stdc++.h>
using namespace std;


using ll=long long;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int&count){
    vis[node]=true;
    count++;
    for(int neighbor:adj[node]){
        if(!vis[neighbor]){
            dfs(neighbor,adj,vis,count);
        }
    }
}

int main(){
    int n,p;
    cin>>n>>p;
    vector<vector<int>>adj(n);
    vector<bool>vis(n,false);

    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>country_sizes;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            int count=0;
            dfs(i,adj,vis,count);
            country_sizes.push_back(count);
        }
    }

    ll total=(ll)n*(n-1)/2;
    for(int size:country_sizes){
        total-=(ll)size*(size-1)/2;
    }

    cout<<total<<endl;
    return 0;
}