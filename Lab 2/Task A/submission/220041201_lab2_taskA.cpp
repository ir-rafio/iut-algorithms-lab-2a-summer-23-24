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
    
        int n,x, c=0, j=0;
        cin >> n >> x;

        vector<int> b(n);

        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        while(j<=n && x>=b[j]){
            x -= b[j];
            j++;
          
        }
        cout << j;
        
    
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
