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
    int t;
    cin >> t;  
    
    while (t--) {
        int n, x;
        cin >> n >> x;  
        
        vector<int> bottle_capacities(n);
        for (int i = 0; i < n; ++i) {
            cin >> bottle_capacities[i];  
        }
    
        sort(bottle_capacities.begin(), bottle_capacities.end());
        
        int filled_bottles = 0;
        
        
        for (int i = 0; i < n; ++i) {
            if (x >= bottle_capacities[i]) {
                x -= bottle_capacities[i];
                filled_bottles++;
            } else {
                break;  
            }
        }
        
        cout << filled_bottles << endl;  
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
