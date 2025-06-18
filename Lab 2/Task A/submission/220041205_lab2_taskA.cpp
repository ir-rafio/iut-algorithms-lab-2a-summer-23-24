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
    LL x;
    cin >> n >> x;
    vector<LL> bottles(n);

    for (int i = 0; i < n; i++) {
        cin >> bottles[i];
    }

    sort(bottles.begin(), bottles.end());
    
    int count;
    for (count = 0; count < n && bottles[count] <= x; x -= bottles[count], count++);

    cout << count;
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