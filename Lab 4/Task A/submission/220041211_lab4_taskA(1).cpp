#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

vector <pair<int, LL>> adj[100001];
bool visited[100001] = {false};
LL delay[100001];


void pre()
{
    fastio;
}

void dijkstra(int n)
{
    int src = 1;
    delay[src] = 0;

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> pq;

    pq.push({delay[src], src});

    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();

        if(!visited[u]){
            visited[u] = true;

            for (auto [v, value] : adj[u]){
                // Either undefined or smaller delay found
                if (delay[v] == -1 || delay[v] > delay[u] + value){
                    delay[v] = delay[u] + value;
                    pq.push({delay[v], v});
                }
            }
        }
    }

}

signed main()
{
    pre();

    int n, m, a, b, c;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        delay[i] = 1000000001;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(n);
    for(int i = 1; i <= n; i++){
        cout << delay[i] << " ";
    }

    return 0;
}
