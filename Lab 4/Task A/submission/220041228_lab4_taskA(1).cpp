#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const int INF= 1000000;
const int MAXX= 1000005;
int n;

vector<pair<int,int>>adj[MAXX];

vector<long long> dijkstra(int start){

    vector<long long> dist(n+1, INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start]=0;
    pq.push(make_pair(0LL,start));

    while(!pq.empty()){
        pair<int,int> tp =pq.top();

        pq.pop();

        int d=tp.first;
        int u= tp.second;

        if(d>dist[u]) continue;

        for(int i=0; i<=adj[u].size(); i++){
            int v=adj[u][i].first;
            int w=adj[u][i].second;

            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));


            }

        }


    }

    return dist;

}


void pre()
{
    fastio;

    
}

void solve(int tc)
{
    int m;
    cin>>n>>m;


    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));

    }
    vector<long long>dist=dijkstra(1);
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
