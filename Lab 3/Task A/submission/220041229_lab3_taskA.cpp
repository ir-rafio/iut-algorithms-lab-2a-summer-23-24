#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adj;    // Adjacency List
    vector<vector<int>> matrix; // Adjacency Matrix
    int n;                      // Number of nodes

    Graph(int nodes)
    {
        n = nodes;
        matrix.resize(n, vector<int>(n, 0)); // 0 based indexing
        // matrix.resize(n+1, vector<int>(n+1, 0)); // 1 based indexing
    }

    void addEdge_AdjList(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
            adj[v].push_back(u);
    }

    void addEdge_AdjMatrix(int u, int v, bool direction)
    {
        matrix[u][v] = 1;
        if (!direction)
            matrix[v][u] = 1;
    }

    void printAdjList()
    {
        cout << "Adjacency List:" << endl;
        for (auto &node : adj)
        {
            cout << node.first << " -> ";
            for (auto &neighbor : node.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix()
    {                                        // Convert the loop from 1 to equal to n for 1 based indexing
        cout << "Adjacency Matrix:" << endl; // loop from 1 to n-1 for 1 based indexing
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
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
            if (visited.find(n) == visited.end())
            {
                DFS(n, visited, components);
            }
        }
    }

    // Function to get a vector containing all of the components
    vector<vector<int>> DFS_result()
    {
        set<int> visited;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
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
};

int main()
{
    int n, m;
    // cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    Graph g(n);

    // cout << "Choose Graph Representation:\n1. Adjacency List\n2. Adjacency Matrix\n";

    // cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge_AdjList(u, v, 0);
    }

    g.printAdjList();

    // Perform DFS traversal from node 0 and print the result
    vector<vector<int>> componenets = g.DFS_result();
    // Looping thorugh the components
    int ans = 0;
    for (int i = 0; i < componenets.size(); i++)
    {
        cout<<"size of the component: "<<componenets[i].size()<<endl;
        
    }
    cout<<ans<<endl;

    return 0;
}

/*
// Test inputs
5 4 1
0 3
1 2
1 3
1 4
*/

/*
GIT CLONE =>
git clone https://github.com/Farhan41229/CPP_Notes.git
*/