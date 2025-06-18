#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, const vector<int>& money, int& peopleCount, LL& moneySum) {
    
    visited[u] = true;
    peopleCount++;
    moneySum += money[u];

    for (int v : adj[u]) 
    {
        if (!visited[v]) 
        {
            dfs(v, adj, visited, money, peopleCount, moneySum);
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<int> money(n);
    LL totalMoney = 0;
    for (int i = 0; i < n; ++i) {
        cin >> money[i];
        totalMoney += money[i];
    }

    if (totalMoney % n != 0) {
        cout << "No";
        return;
    }

    int expectedPerPerson = totalMoney / n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool possible = true;

    for (int i = 0; i < n; ++i) 
    {
        if (!visited[i])
        {
            int peopleCount = 0;
            LL moneySum = 0;
            dfs(i, adj, visited, money, peopleCount, moneySum);

            if (moneySum != (LL)peopleCount * expectedPerPerson) 
            {
                possible = false;
                break;
            }
        }
    }

    cout << (possible ? "Yes" : "No");
}

signed main() {
    pre();

    int tt;
    cin >> tt;

    for (int tc = 1; tc <= tt; tc++) {
        solve(tc);
        cout << '\n';
    }

    return 0;
}
