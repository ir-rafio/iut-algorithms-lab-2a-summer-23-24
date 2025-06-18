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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<LL,LL>>> list(n+1);
    vector<LL> delay(n+1,INT_MAX);
    delay[1] = 0;
    while(m--){
        LL a, b, c;
        cin >> a >> b >> c;
        list[a].push_back({b,c});
        

    }
    for(int i=1; i<=n; i++){
        for(int itr: list[i]){
            LL alt_delay = delay[i]+delay[itr];
            if(alt_delay<delay[itr])
                delay[itr] = alt_delay;
        }
    }
    for(int i=1; i<=n; i++){
        cout << delay[i] << " ";
    }
    cout << endl;
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