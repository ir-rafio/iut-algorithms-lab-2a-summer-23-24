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
    int n;
    cin >> n;
    vector<pair<LL,LL>> act(n);
    for(int i=0; i<n; i++){
        cin >> act[i].second;
    }
    for(int i=0; i<n; i++){
        cin >> act[i].first;
    }
    sort(act.begin(), act.end());
    int count = 0;
    int last_event = 0;
    for(int i=0; i<n; i++){
        if(act[i].second>=last_event){
            count++;
            last_event = act[i].first;
        }
    }
    cout << count << endl;
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