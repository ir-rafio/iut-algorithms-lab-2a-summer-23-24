#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector<vector<int>> adj;
vector<bool> visited;

LL value = 0;

void pre()
{
    fastio;
}

void dfs(int node)
{
    visited[node] = true;
    value++;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

void solve(int tc)
{
    int n, p;
    cin >> n >> p;

    adj.clear();
    visited.clear();
    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < p; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LL answer = 0, pre_value = 0;

    for (int j = 0; j < n; j++)
    {
        if (!visited[j])
        {
            value = 0;
            dfs(j);
            answer += pre_value * value;
            pre_value += value;
        }
    }

    cout << answer;
}

signed main()
{
    pre();

    int tt;
    cin >> tt;

    for (int tc = 1; tc <= tt; tc++)
    {
        solve(tc);
        cout << '\n';
    }

    return 0;
}
