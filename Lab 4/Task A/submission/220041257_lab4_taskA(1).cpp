#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main()
{

    int n , m;
    cin >>n >>m;

    vector <vector<pair<int , int>>> adj(n+1);
    for (int i=0; i<m; ++i)
        {
            int a , b ,c;
            cin >> a >> b >> c;
            adj[a].emplace_back(b,c);
        }
        vector<long long> dist(n+1,INF);
        dist[1] = 0;

        priority_queue<pair<long long , int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0,1);

        while (!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();

            if (d>dist[u]) continue;

            for (auto[v,w]:adj[u]){
                if(dist[v]>dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        for (int i=1; i<=n; ++i){
            cout << dist[i] <<" ";
        }
        cout <<'\n';

        return 0;

}

