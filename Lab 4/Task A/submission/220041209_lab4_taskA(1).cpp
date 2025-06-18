#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}



void dijkstra(int n, vector<vector<pair<LL, LL>>>& graph) {
    vector<LL> dist(n + 1, LLONG_MAX);
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        LL d = pq.top().first;
        LL u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            LL v = edge.first;
            LL weight = edge.second;
            LL newDist = dist[u] + weight;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == LLONG_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<LL, LL>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        LL a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(n, graph);
}


signed main()
{
    pre();
    solve();
    cout << '\n';

    return 0;
}