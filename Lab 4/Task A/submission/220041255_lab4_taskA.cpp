#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using LL = long long;
#define INF 1e16

vector<vector<pair<int, int>>> adj;
vector<LL> dist;

void pre() {
    fastio;
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.resize(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        int cur = u.second;
        if (u.first > dist[cur])
            continue;

        for (auto v : adj[cur]) {
            int to = v.first;
            int len = v.second;

            if (dist[to] > dist[cur] + len) {
                dist[to] = dist[cur] + len;
                pq.push(make_pair(dist[to], to));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    pre();

    solve();

    return 0;
}
