#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void solve(int tc)
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

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
