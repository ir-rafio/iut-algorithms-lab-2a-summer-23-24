#include <iostream>
#include <vector>

using namespace std;
void dfs(int u, vector<vector<int>> &g, vector<bool> &vis, int &cnt) {
    vis[u] = true;
    cnt++;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, cnt);
        }
    }
}
int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> g(n);
    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n, false);
    vector<int> sizes;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            int cnt = 0;
            dfs(i, g, vis, cnt);
            sizes.push_back(cnt);
        }
    }
    long long res = 0, sum = 0;
    for (int sz : sizes) {
        res += sum * sz;
        sum += sz;
    }
    cout << res << endl;
    return 0;
}
