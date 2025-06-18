#include <bits/stdc++.h>
#include <cstring>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

#define MAX 1005

vector<int> adj[MAX];
bool visited[MAX];
int money[MAX];
int cnt, amount, totalAmount;

void dfs(int node) {
    if (visited[node])
        return;

    visited[node] = true;
    cnt++;
    amount += money[node];

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

void pre() {
    fastio;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    totalAmount = 0;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
        totalAmount += money[i];
        adj[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool flag = true;
    int avg = totalAmount / n;

    if (totalAmount % n) {
        flag = false;
    }
    else {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            amount = 0, cnt = 0;
            if (!visited[i]) {
                dfs(i);

                if (cnt * avg != amount) {
                    flag = false;
                    break;
                }
            }
        }
    }

    cout << (flag ? "Yes" : "No");
}

int main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
