#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre()
{
    fastio;

    
}

typedef pair<LL, int> Edge;

void dijkstra(const vector<vector<Edge>>& adjList, vector<LL>& distances, int source) {
    int n = adjList.size();
    distances[source] = 0;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distances[u]) continue;

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
    vector<LL> distances(n + 1, numeric_limits<LL>::max());

    int source = 1;
    while (m--) {
        int a, b;
        LL c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(c, b));
    }

    dijkstra(adjList, distances, source);

    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
}

signed main()
{
    pre();

    int tc, tt = 1;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}