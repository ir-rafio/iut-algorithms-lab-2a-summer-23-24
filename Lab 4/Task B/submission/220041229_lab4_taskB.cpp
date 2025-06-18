#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<pair<int, int>>> adj; // Adjacency List
    int n;                              // Number of nodes

    Graph(int nodes)
    {
        n = nodes;
    }

    void addEdge_AdjList(int u, int v, int w, bool direction)
    {
        adj[u].push_back({v, w});
        if (!direction)
            adj[v].push_back({u, w});
    }

    void printAdjList()
    {
        cout << "Adjacency List:" << endl;
        for (auto &node : adj)
        {
            cout << node.first << " -> ";
            for (auto &neighbor : node.second)
            {
                int element = neighbor.first;
                int weight = neighbor.second;
                cout << " " << element << "[" << weight << "]";
            }
            cout << endl;
        }
    }

    void DFS(int node, set<int> &visited, vector<int> &components)
    {
        components.push_back(node);
        visited.insert(node);

        for (auto n : adj[node])
        {
            if (visited.find(n.first) == visited.end())
            {
                DFS(n.first, visited, components);
            }
        }
    }

    vector<vector<int>> DFS_result()
    {
        set<int> visited;
        vector<vector<int>> ans;
        // CHANGE #1: Loop runs from 1 to n (instead of 0 to n-1)
        for (int i = 1; i <= n; i++)
        {
            if (visited.find(i) == visited.end())
            {
                vector<int> components;
                DFS(i, visited, components);
                ans.push_back(components);
            }
        }
        return ans;
    }

    // Dijkstra member function
    vector<int> dijkstra(int source)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << "Vector" << endl;
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        // CHANGE #2: Times vector size is n+1 for 1-based indexing
        vector<int> Times(n + 1, INT_MAX);
        Times[source] = 0;

        set<pair<int, int>> st;
        st.insert({0, source});

        while (!st.empty())
        {
            auto top = *(st.begin());
            cout << "Top of the Stack is: " << top.second;
            cout << endl;
            cout<<"Top Second is: "<<top.second; cout<<endl;
            cout << "Correspoding 1/Speed => " << v[top.second-1];
            cout << endl;
            int nodetime = top.first * v[0];
            int node = top.second;
            st.erase(st.begin());

            for (auto &neighbor : adj[node])
            {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (nodetime + (weight * v[neighbor.first-1]) < Times[adjNode])
                {
                    auto record = st.find({Times[adjNode], adjNode});
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    Times[adjNode] = nodetime + (weight * v[neighbor.first-1]);
                    st.insert({Times[adjNode], adjNode});
                }
            }
        }

        return Times;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge_AdjList(u, v, w, 0);
    }

    g.printAdjList();

    // CHANGE #3: Source node in 1-based indexing is typically 1
    vector<int> dist = g.dijkstra(1); // source = 0

    cout << "Distances from source 0:\n";
    // CHANGE #4: Loop to print Times runs from 1 to n (instead of 0 to n-1)
    for (int i = 1; i <= dist.size() - 1; i++)
    {
        cout << "Node " << i << " : ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
