#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

//const int INF = numeric_limits<int> :: max();
#define INF 1e16



void pre()
{
    fastio;


}

void solve()
{

}

void dijkstra(int n, const vector<vector<pair<int, int>>> &graph, vector<int>& delays)
{
   priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<LL, int>>> pq;
   delays[1] = 0;
   pq.push({0, 1});

   while(!pq.empty())
   {
       int currentDelay = pq.top().first;
       int currentOutpost = pq.top().second;
       pq.pop();

       if(currentDelay > delays[currentOutpost])
       {
           continue;
       }

       for (const auto& neighbour : graph[currentOutpost])
       {
           int nextOutpost = neighbour.first;
           int signalDelay = neighbour.second;

           if(delays[currentOutpost] + signalDelay < delays[nextOutpost])
           {
               delays[nextOutpost] = delays[currentOutpost] + signalDelay;
               pq.push({delays[nextOutpost], nextOutpost});
           }
       }
   }
}

signed main()
{
    pre();

    LL n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (LL i = 0; i < m; i++)
    {
     int a,b,c;
     cin >> a >> b >> c;
     graph[a].emplace_back(b,c);
    }
    vector<int> delays(n + 1, INF);
    dijkstra(n, graph,delays);

    for (LL i = 1; i <= n; i++)
    {
     cout << delays[i] << " ";
    }
    cout << endl;

    return 0;
}
