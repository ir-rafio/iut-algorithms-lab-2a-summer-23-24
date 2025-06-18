#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
const ll inf = 1e18;

void Dijkstra(ll source, vector<vector<pair<ll,ll>>> &adj, vector<ll> &dist) 
{
    int n = adj.size();
    dist.assign(n, inf);
    dist[source] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});

    while (!pq.empty()) 
    {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (auto& edge : adj[u]) 
        {
            ll v = edge.first;
            ll w = edge.second;

            if(dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void pre() 
{
    fastio;
}

void solve(int tc) 
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n + 1);
    for (ll i = 0; i < m; ++i) 
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});  
    }

    ll source = 1;
    vector<ll> dist(n + 1);
    Dijkstra(source, adj, dist);

    for (ll i = 1; i <= n; ++i)  
    {
        cout << dist[i] << " ";
    }
}

signed main() {
    pre();
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve(i);
        cout << '\n';
    }
    return 0;
}





