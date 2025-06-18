#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int n, p;
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

LL valid_pairs(){
        LL total = 0, sum = 0;
    for(int size : country){
        total += size * sum;
        sum += size;
    }
    return total;
}

signed main()
{
    pre();
    int u, v;

    cin >> n >> p;

    for(int i = 0; i < p; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            country.push_back(BFS(i));
        }
    }
    cout << valid_pairs() << endl;

    return 0;
}
