#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

typedef pair<int, int> Edge;

void dijkstra(const vector<vector<Edge>>& adjList, vector<int>& distances, int source, vector<int>& unitTime) {
    int n = adjList.size();
    distances[source] = 0;
    int bike = source;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > (distances[u] * unitTime[u])) continue;

        for (const Edge& edge: adjList[u]) {
            int v = edge.second;
            int distV = edge.first;

            if (distances[u] + distV < distances[v]) {
                distances[v] = distances[u] + distV;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adjList(n + 1);
    vector<int> distances(n + 1, numeric_limits<int>::max());
    vector<int> unitTime(n + 1);
    int source = 1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back(make_pair(w, v));
        adjList[v].push_back(make_pair(w, u));
    }

    for (int i = 1; i <= n; i++) {
        cin >> unitTime[i];
        for (Edge& edge: adjList[i]) {
            edge.first *= unitTime[i];
        }
    }

    dijkstra(adjList, distances, source, unitTime);

    cout << distances[n];
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