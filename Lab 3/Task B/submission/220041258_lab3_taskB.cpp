#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int visited[100];

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count)
{
    visited[node] = true;
    count++;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, count);
        }
    }
}

signed main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> adj(n);
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> component_sizes;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(i, adj, visited, count);
            component_sizes.push_back(count);
        }
    }

    long long total_pairs = (long long)n * (n - 1) / 2;
    long long same_country_pairs = 0;
    for (int size : component_sizes)
    {
        same_country_pairs += (long long)size * (size - 1) / 2;
    }

    cout << total_pairs - same_country_pairs << endl;
    return 0;
}
