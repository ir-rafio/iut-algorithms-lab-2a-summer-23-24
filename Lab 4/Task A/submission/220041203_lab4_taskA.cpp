#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
#define int long long
const int inf=1e15;



void pre()
{
    fastio;

    
}

void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    vector<int> dist(n+1,inf);
    dist[1]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()){

        int cost=pq.top().first;
        int u=  pq.top().second;
        pq.pop();

        if(cost>dist[u]) continue;

        for(auto i: adj[u]){
            int vertex= i.first;
            int plus_cost=i.second;

            if( dist[vertex]> cost+plus_cost){
                dist[vertex]=cost+plus_cost;
                pq.push({dist[vertex],vertex});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    
}

signed main()
{
    pre();

    int tc, tt = 1;
   // cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}