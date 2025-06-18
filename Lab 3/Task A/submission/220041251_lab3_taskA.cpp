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

void dfs(int node, vector<vector<int>>&graph, vector<bool>visited, long long totalMoney,
    int& count, const vector<int>& money)
{
    visited[node] = true;
    totalMoney += money[node];
    count++;

    for(int neighbor : graph[node])
    {
     if(!visited[neighbor])
        {
            dfs(neighbor, graph , visited, totalMoney, count, money);
        }
    }

}

signed main()
{
    pre();

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        for (int i = 0; i < n; i++) {
            cin >> money[i];
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; // Convert to 0-based index
            v--; // Convert to 0-based index
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool canEqualize = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long totalMoney = 0;
                int count = 0;
                dfs(i, graph, visited, totalMoney, count, money);

                // Check if the total money can be evenly distributed
                if (totalMoney % count != 0) {
                    canEqualize = false;
                    break;
                }
            }
        }

        cout << "Case " << t << ": " << (canEqualize ? "Yes" : "No") << endl;
    }

    return 0;
}
