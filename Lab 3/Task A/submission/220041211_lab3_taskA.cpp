#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int total;
bool visited[100000] = {false};
vector <int> adj[100000], country;

void pre()
{
    fastio;


}

int BFS(int src){
    int count = 1;
    queue <int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                count++;
            }
        }
    }
    return count;
}

signed main()
{
    pre();

    int t, n, m, u, v;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        total = 0;
        int money[1001];

        for(int j = 1; j <= n; j++){
            cin >> money[j];
            total += money[j];
        }
        for(int j = 0; j < m; j++){
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(total%n){
            cout << "Case " << i << ": No" << endl;

        }
        else{
            int avg = total / n;
        }


    }
    return 0;
}
