#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const int N=1e5+9;
const long long INF=1e18;
vector<pair<long long,long long>>adj[N];
vector<long long>dist(N,INF);
vector<long long>vis(N,0);

void pre()
{
    fastio;


}

void dijkstra(int source){
     set<pair<long long,long long>>st;
     st.insert({0,source});

     dist[source]=0;

     while(st.size()>0){
        auto node=*st.begin();
        long long v=node.second;
        st.erase(st.begin());

        if(vis[v]){
            continue;
        }
        vis[v]=1;

        for(auto& u:adj[v]){
            long long wt=u.second;
            int child=u.first;

            if((wt+dist[v])<dist[child]){
                st.erase({dist[child],child});
                dist[child]=dist[v]+wt;
                st.insert({dist[child],child});
            }
        }

     }

}

void solve(int tc)
{
   int n,m;
   cin>>n>>m;

   int x,y,wt;
   for(int i=0;i<m;i++){
    cin>>x>>y>>wt;
    adj[x].push_back({y,wt});
   }

   dijkstra(1);

   for(int i=1;i<=n;i++){
    cout<<dist[i]<<" ";
   }

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
