#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

struct State {
    int city;
    int best_s;
    ll time;
    
    bool operator>(const State& other) const {
        return time > other.time;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    
    vector<vector<ll>> dist(n + 1, vector<ll>(1001, LLONG_MAX));
    priority_queue<State, vector<State>, greater<State>> pq;
    
    dist[1][s[1]] = 0;
    pq.push({1, s[1], 0});
    
    ll ans = LLONG_MAX;
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        int u = current.city;
        int current_s = current.best_s;
        ll time_u = current.time;
        
        if (u == n) {
            ans = time_u;
            break;
        }
        
        if (time_u > dist[u][current_s]) {
            continue;
        }
        
        int new_s = min(current_s, s[u]);
        if (time_u < dist[u][new_s]) {
            dist[u][new_s] = time_u;
            pq.push({u, new_s, time_u});
        }

        for (auto& [v, w] : adj[u]) {
            ll new_time = time_u + w * current_s;
            if (new_time < dist[v][current_s]) {
                dist[v][current_s] = new_time;
                pq.push({v, current_s, new_time});
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}