#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
vector<vector<int>> adj(1000);




void addEdge(int u,int v,vector<vector<int>>& adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &money, long long &total, int &count)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        total += money[node];
        count++;
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int option;
    cin >> option;

    for (int search= 1; search <= option; search++)
    {
        int a, b;
        cin >> a >> b;

        vector<int> arr(a);
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }

        vector<vector<int>> adj(a);
        for (int i = 0; i < b; i++)
        {
            int u, v;
            cin >> u >> v;
           addEdge(u - 1, v - 1, adj);

        }

        vector<bool> visited(a, false);
        bool possible = true;

        for (int i = 0; i < a && possible; ++i)
        {
            if (!visited[i])
            {
                long long total = 0;
                int count = 0;
                bfs(i, adj, visited, arr, total, count);
                if (total % count != 0)
                {
                    possible = false;
                }
            }
        }
}
        cout << "Case " << search << ": " << (possible ? "Yes" : "No") << "\n";


    return 0;
}
