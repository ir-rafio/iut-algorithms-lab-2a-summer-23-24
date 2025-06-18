#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, vector<int>&group){
    visited[node] = true;
    group.push_back(node);

    for (int neighbor:graph[node]){
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, group);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int i= 1; i<= T; i++) {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        for (int i=0; i<n; i++) {
            cin>>money[i];
        }

        vector<vector<int>> graph(n);
        for (int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool>visited(n,false);
        bool ok=true;

        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                vector<int> group;
                dfs(i,graph,visited,group);

                LL total=0;
                for (int j:group) {
                    total += money[j];
                }

                if (total% group.size() !=0) {
                    ok = false;
                    break;
                }
            }
        }

        cout << "Case " << i << ": " << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}
