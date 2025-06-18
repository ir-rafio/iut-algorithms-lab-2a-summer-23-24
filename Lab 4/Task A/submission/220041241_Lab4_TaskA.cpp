#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void solve(int tc)
{
     LL n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<LL,LL>>>adj(n+1);
    for(int i=0;i<m;i++)
    {
       cin>>a>>b>>c;
       adj[a].push_back({b,c});
    }
    vector<LL>distance(n+1,1e17);
    distance[1]=0;
   priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>>pq;
   pq.push({0,1});
   while(!pq.empty())
   {
      LL delay=pq.top().first;
      LL node=pq.top().second;
      pq.pop();
      for(auto it:adj[node])
      {
        LL adj_node=it.first;
        LL adj_distance=it.second;
        if((delay+adj_distance)<distance[adj_node])
        {
            distance[adj_node]=delay+adj_distance;
            pq.push({distance[adj_node],adj_node});
        }
      }
   }
  


   for(int i=1;i<=n;i++)
   {
    cout<<distance[i]<<" ";
   }
}

signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}