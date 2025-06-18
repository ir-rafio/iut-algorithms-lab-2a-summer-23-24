#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

int find(vector<int>&parent,int x){
    if(parent[x]<0) return x;
    return parent[x]=find(parent,parent[x]);
}

void unite(vector<int>&parent, int a,int b){
    int ra=find(parent,a);
    int rb=find(parent,b);
    if(ra==rb) return;

    if(parent[ra]<parent[rb]){
        parent[ra]+=parent[rb];
        parent[rb]=ra;
    }
    else{
        parent[rb]+=parent[ra];
        parent[ra]=rb;
    }
}

void solve(int tc)
{
    int n,p;
    cin>>n>>p;

    vector<int>parent(n,-1);
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        unite(parent,a,b);
    }
    
    vector<int>gsize;
    for(int i=0;i<n;i++){
        if(parent[i]<0)
        gsize.push_back(-parent[i]);
    }

    long long res=0,sum=0;

    for(int size:gsize){
        res+=sum*size;
        sum+=size;
    }
    cout<<res<<endl;

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