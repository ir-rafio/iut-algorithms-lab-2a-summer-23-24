#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Graph
{
public:
    vector<vector<pair<ll, ll>>> adj;
    ll n;

    Graph(ll nodes)
    {
        n = nodes;
        adj.resize(n + 1);
    }

    void addEdge_AdjList(ll u, ll v, ll w, bool direction)
    {
        adj[u].push_back({v, w});
        if (!direction)
        {
            adj[v].push_back({u, w});
        }
    }

    vector<ll> dijkstra(ll source)
    {
        const ll INF = 1e15;
        vector<ll> distances(n + 1, INF);
        distances[source] = 0;

        set<pair<ll, ll>> st;
        st.insert({0, source});

        while (!st.empty())
        {
            auto top = *(st.begin());
            ll nodeDist = top.first;
            ll node = top.second;
            st.erase(st.begin());

            for (auto &neighbor : adj[node])
            {
                ll adjNode = neighbor.first;
                ll weight = neighbor.second;

                if (nodeDist + weight < distances[adjNode])
                {
                    auto record = st.find({distances[adjNode], adjNode});
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    distances[adjNode] = nodeDist + weight;
                    st.insert({distances[adjNode], adjNode});
                }
            }
        }
        return distances;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    Graph g(n);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g.addEdge_AdjList(u, v, w, 1);
    }

    vector<ll> dist = g.dijkstra(1);

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
