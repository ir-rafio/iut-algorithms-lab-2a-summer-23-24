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

void dijkstra(int source, vector<pair<int,int>>g[],vector<int>&visited,vector<int>&dist)
{
    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0)
    {
        auto it=*st.begin();
        int v=it.second;
        int distance=it.first;
        st.erase(st.begin());
        if(visited[v])
            continue;
        visited[v]=1;
        for(auto &[child,wt] : g[v])
        {
            if(distance+wt<dist[child])
            {
                dist[child]=dist[v]+wt;
                st.insert({dist[child],child});
            }
        }
    }
}

void solve(int tc)
{
    int n , m ;
    cin >> n >> m ;
    vector<pair<int,int>>g[n+1];
    for(int i=0;i<m;i++)
    {
        int x , y , d ;
        cin >> x >> y >> d;
        g[x].push_back({y,d});
    }
    int source=1;
    vector<int>visited(n+1,0);
    vector<int>dist(n+1,inf);
    dijkstra(source,g,visited,dist);
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    

}
        
    
    


signed main()
{
    pre();

    int tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        //cout << "Case " << tc << ": \n";
        solve(tc);
        //cout << '\n';
    }

    return 0;
}