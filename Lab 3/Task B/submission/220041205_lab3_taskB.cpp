#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void dfsVisit(vector<vector<int>>& adjList, vector<bool>& visited, int node, int& count) {
    visited[node] = true;
    count++;
    for (int vertex: adjList[node]) {
        if (!visited[vertex]) {
            dfsVisit(adjList, visited, vertex, count);
        }
    }
}

void solve(int tc)
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);
    vector<int> sizes;


    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfsVisit(adjList, visited, i, count);
            sizes.push_back(count);
        }
    }

    for (int size: sizes) {
        cout << size << "\n";
    }
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