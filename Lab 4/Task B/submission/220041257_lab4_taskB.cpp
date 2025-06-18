#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    while (T--){
        int n,m; cin>>n>>m;

        vector<vector<pair<int,int>>>g(n+1);
        while(m--){
            int u , v , w;
            cin >> u >> v >> w;

            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }

        vector<int> s(n+1);

        for (int i=1; i<=n; ++i) cin>>s[i];

        vector<vector<ll>> d(n+1, vector<ll>(n+1,INF));


        priority_queue<tuple<ll , int , int> , vector <tuple<ll , int , int>>,greater<>> q;
        d[1][1] = 0;

        q.emplace(0,1,1);

        while(!q.empty()){
            auto[t,u,b] = q.top(); q.pop();

            if(t>d[u][b]) continue;

            if(d[u][u] > t){
                d[u][u] = t;

                q.emplace(t,u,u);
            }

            for (auto[u,w]:g[u]){
                ll nt = t + 1LL * w * s[b];

                if (d[v][b]>nt){
                    d[v][b] = nt;
                    q.emplace(nt,v,b);
                }
            }
        }

        ll res = INF;

        for (int i=1;i<=n; ++i){
            res = min(res, d[n][i]);

            cout << res<<'\n';
        }
    }
}

