#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void bfs(int i, vector<bool>& visited, vector<vector<int>>& adj, vector<int> &money, int &total, int &count)  {
    int V = adj.size();
    
    queue<int> q;  
    visited[i] = true;
    q.push(i);
    total = money[i];
    count = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
                total += money[x];
                count++;
            }
        }
    }
}


void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n+1);
    vector<int> money;

    money.push_back(0);
    // cout << "money: ";
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        money.push_back(x);
    }
    // cout << "\nconnection: ";
    for (int i = 0; i < m; i++) {
        int rel1, rel2;
        cin >> rel1 >> rel2;
        adjList[rel1].push_back(rel2);
        adjList[rel2].push_back(rel1);
    }

    // cout << "connection end\n";

    vector<bool> visited(n+1, false);
    int flag = 1;
    int total = 0;
    int count = 0;
    for (int i = 1; i <=n; i++) {
    if (visited[i] != true) {
        bfs(i, visited, adjList, money, total, count);
        // cout << "Total: " << total << endl;
        // cout << "Count: " << count << endl;
        if (total % count != 0) {
            flag = 0;
                break;
        }
    }

    }
        
    if (flag == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
return;
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}