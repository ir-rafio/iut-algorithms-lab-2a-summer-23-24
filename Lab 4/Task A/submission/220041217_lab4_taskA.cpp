#include <bits/stdc++.h>
using namespace std;
#define SONIC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ln '\n'
#define yes cout << "YES" << ln;
#define no  cout << "NO" << ln;
using ll = long long;
typedef pair<ll, ll> pii;
const ll INF  = 1e15;

vector<ll>dijkstra(ll n,vector<vector<pii>>& adj, ll src){
    vector<ll>dist(n+1,INF);
    dist[src]=0;

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if(d>dist[u]) continue;

        for(auto& edge : adj[u]){
            ll v = edge.second;   //destination
            ll weight = edge.first; //weight

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);

    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});  //store(weight, destination)
    }

    ll src = 1;
    vector<ll>shortestPaths = dijkstra(n, adj, src);

    for(ll i = 1; i <= n; i++){
        cout << (shortestPaths[i] == INF ? -1 : shortestPaths[i]) << " ";
    }
    cout << endl;
}

signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    SONIC;
//    ll t;
//    cin>>t;
//    while(t--){
        solve();
//    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}
