#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void solve(int tc)
{

}

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &count) {
    visited[node] = true;
    count++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

signed main()
{
    pre();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<vector<int>> graph(n);

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<int> country_sizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, graph, visited, count);
            country_sizes.push_back(count);
        }
    }

    // Calculate pairs from different countries
    // sum of all pairs: n*(n-1)/2
    long long total_pairs = (long long)n * (n - 1) / 2;
    long long same_country_pairs = 0;
    for (int size : country_sizes) {
        same_country_pairs += (long long)size * (size - 1) / 2;
    }
    cout << total_pairs - same_country_pairs << "\n";

    return 0;
}
