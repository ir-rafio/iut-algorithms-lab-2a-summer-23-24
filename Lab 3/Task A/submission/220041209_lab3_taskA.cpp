#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


void pre()
{
    fastio;

    
}

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> group;


void DFS(int node) {
    visited[node] = true;
    group.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<int> money;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }

    money.resize(n + 1);  
    LL total = 0;

    for (int i = 1; i <= n; i++) {
        cin >> money[i];
        total += money[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (total % n != 0) {
        cout << "Case " << tc << ": No";
        return;
    }

    int targetmoney = total / n;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            group.clear();
            DFS(i);

            LL sum = 0;
            for (int node : group) {
                sum += money[node];
            }

            if (sum % group.size() != 0 || sum / group.size() != targetmoney) {
                cout << "Case " << tc << ": No";
                return;
            }
        }
    }

    cout << "Case " << tc << ": Yes";
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}

