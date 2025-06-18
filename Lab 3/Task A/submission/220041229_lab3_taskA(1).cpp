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
        // matrix.resize(n, vector<int>(n, 0)); // 0 based indexing
        matrix.resize(n + 1, vector<int>(n + 1, 0)); // 1 based indexing
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

    void DFS(int node, set<int> &visited, vector<int> &components, int &sum, vector<int> &coins)
    {
        components.push_back(node);
        visited.insert(node);
        sum += coins[node - 1];

        for (auto n : adj[node])
        {
            if (visited.find(n) == visited.end())
            {
                DFS(n, visited, components, sum, coins);
            }
        }
    }

    // Function to get a vector containing all of the components
    vector<vector<int>> DFS_result(vector<int> &components_sum, vector<int> coins)
    {
        set<int> visited;
        vector<vector<int>> ans;

        for (int i = 1; i < n + 1; i++)
        {
            if (visited.find(i) == visited.end())
            {
                int sum = 0;
                vector<int> components;
                DFS(i, visited, components, sum, coins);
                ans.push_back(components);
                if (sum % components.size() == 0)
                {
                    components_sum.push_back(sum/components.size());
                }
                else
                    components_sum.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    int caseNo = 1;
    while (t--)
    {
        
        int n, m;
        // cout << "Enter number of nodes and edges: ";
        cin >> n >> m;
        vector<int> coins(n);
        vector<int> components_sum;
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        // cout << "Coins Vector" << endl;
        // for (auto x : coins)
        //     cout << x << " ";
        // cout << endl;

        Graph g(n);

        // cout << "Choose Graph Representation:\n1. Adjacency List\n2. Adjacency Matrix\n";

        // cout << "Enter edges (u v):" << endl;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge_AdjList(u, v, 0);
        }

        // g.printAdjList();

        // Perform DFS traversal from node 0 and print the result
        vector<vector<int>> components = g.DFS_result(components_sum, coins);
        // Looping thorugh the components
        bool ans = true;
        if (components_sum[0] == -1)
            ans = false;

        // for(int i = 0; i< components.size(); i++){
        //     cout<<"Component: "<<i+1<<endl;
        //     for(auto x: components[i]){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        //     cout<<"Sum of the shared amount : "<<components_sum[i]<<endl;
        // }
        for (int i = 1; i < components_sum.size(); i++)
        {
            if (components_sum[i] != components_sum[i - 1])
                ans = false;
        }
        if (ans){
            cout << "Case " << caseNo << ": Yes" << endl;
            caseNo++;
        }
        else{
            cout << "Case " << caseNo << ": No" << endl;
            caseNo++;
        }
    }

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