#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const ll inf = 1e18;


void pre()
{
    fastio;
}

void Dijkstra(ll source, vector<vector<pair<ll,ll>>> &adj, vector<ll> &dist, vector<ll> &speed) 
{
    ll n = adj.size();
    dist.assign(n, inf);
    dist[source] = 0;


    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push(tuple<ll, ll, ll>(0, 1, speed[1]));
    
    while (!pq.empty()) 
    {
        tuple<ll, ll, ll> t = pq.top();
        pq.pop();
        ll curr_time = get<0>(t);
        ll u = get<1>(t);
        int curr_speed = get<2>(t);

        if (curr_time > dist[u]) 
        {
            continue;
        }

        for (size_t i = 0; i < adj[u].size(); ++i) 
        {
            ll v = adj[u][i].first;
            ll w = adj[u][i].second;
            ll next_time = curr_time + 1LL * w * curr_speed;

            if (next_time < dist[v]) 
            {
                dist[v] = next_time;
                pq.push(tuple<ll, ll, ll>(next_time, v, min(curr_speed, (int)speed[v]))); 
            }
        }
    }
}

void solve(int tc)
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; ++i) 
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> speed(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> speed[i];
    }

    ll source = 1;
    vector<ll> dist(n + 1);
    Dijkstra(source, adj, dist, speed);

    cout << dist[n];
}

int main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for (tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
