#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const LL INF = 100000000000000;

void dijkstra(LL start, const vector<vector<pair<LL, LL>>> &adj, vector<LL> &delay) {
    LL n = adj.size();
    delay.assign(n, INF);
    delay[start] = 0;

    // Min-heap : (delay, node)
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        LL currDelay = pq.top().first;
        LL u = pq.top().second;
        pq.pop();

        
        if (currDelay > delay[u]) continue;

        for (const auto &edge : adj[u]) {
            LL v = edge.first;
            LL weight = edge.second;

            if (delay[u] + weight < delay[v]) {
                delay[v] = delay[u] + weight;
                pq.push({delay[v], v});
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
    LL n ,m;
    cin >> n >> m;

    vector<vector<pair<LL, LL>>> adj(n+1);

    for(LL i=1;i<=m;i++){
        LL a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c}); //b=node c=weight
    }


    vector<LL> delay;
    LL start = 1;
    dijkstra(start, adj, delay);

    for(LL i=1;i<=n;i++){
        if (delay[i] == INF)
            cout << "-1";
        else
            cout << delay[i] << " ";
    }
}

signed main()
{
    pre();

    LL tc, tt = 1;
    //cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}