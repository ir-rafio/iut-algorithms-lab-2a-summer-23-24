#include<bits/stdc++.h>

using namespace std;



class Edge{
    public: 
        int to, weight;
        Edge(int t, int w) : to(t), weight(w){}
};


void dijkstra(int n, const vector<vector<Edge>>& graph) {
    vector<long long> dist(n + 1, 99999999999999999999999999999999999999); 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[1] = 0;  
    pq.push({0, 1});  
    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        
        if (d > dist[u]) continue;
        
        
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            long long newDist = dist[u] + edge.weight;
            
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }


    for (int i = 1; i <= n; ++i) {
        if (dist[i] == 99999999999999999999999999999999999999) {
            cout << -1 << " ";  
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}


int main() {
    int n, m;
    cin >> n >> m;
    
    
    vector<vector<Edge>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
    }
    
    dijkstra(n, graph);
    
    return 0;
}
