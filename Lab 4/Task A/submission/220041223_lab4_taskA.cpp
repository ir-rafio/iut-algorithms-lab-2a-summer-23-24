#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
vector<pair<int, LL>> adj[100005];
LL d[100005];
bool visited[100005]={false};


void pre()
{
    fastio;


}

void dijkstra(int n)
{
    int source =1;
    for(int i =1; i<=n; i++)
    {
        d[i] = -1;
    }
    d[source] = 0;

    priority_queue<pair<int, LL>, vector<pair<int, LL>>, greater<>> pq;

    pq.push({source, 0});

    while(!pq.empty())
    {
        LL sdist = pq.top().second;
        int s = pq.top().first;
        pq.pop();

        if(!visited[s])
        {
            visited[s] = true;
            if(sdist>d[s]) continue;
            for(int i =0; i<adj[s].size();i++)
            {
                auto v = adj[s][i].first;
                if((d[v]=-1|| d[s]+adj[s][i].second)<d[v])
                {
                    d[v] = d[s]+adj[s][i].second;
                    pq.push({v, d[v]});
                }
            }
        }


    }

}

signed main()
{
    int n, m, a, b, c;
    cin>>n>>m;

    for(int i =0; i<m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});

    }

    dijkstra(n);

    for(int i=1; i<=n; i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;


    return 0;
}
