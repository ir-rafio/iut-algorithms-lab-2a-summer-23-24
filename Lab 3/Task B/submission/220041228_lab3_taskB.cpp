#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MAXX =100005;

vector<vector<int>>adj(MAXX);
vector<bool>visited(MAXX,false);

int dfs(int node){
    visited[node]=true;
    int size=1;
    for(int p: adj[node]){
        if(!visited[p]){
            size+=dfs(p);
        }
    }
    return size;
}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>sameCtsize;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int size=dfs(i);
            sameCtsize.push_back(size);
        }
    }

    LL total =(LL)n*(n-1)/2;
    LL sameCt=0;

    for(int x:sameCtsize){
        sameCt+=(LL)x*(x-1)/2;
    }

    cout<<total-sameCt<<endl;

}



   
