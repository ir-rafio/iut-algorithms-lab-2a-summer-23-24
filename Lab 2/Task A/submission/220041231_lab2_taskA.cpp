#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void solve(int tc)
{
    int n, x, count = 0;
    cin >> n >> x;
    vector<int> bottle(n);

    for (int i = 0; i < n; i++)
    {
        cin >> bottle[i];
    }

    sort(bottle.begin(), bottle.end());

    for(int i = 0; i < n && x >= 0; i++) 
    {
        if (bottle[i] <= x)
        {
            x = x - bottle[i];
            count++;
        }
    }

    cout << count;
}

signed main()
{
    pre();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve(t);
        cout << '\n';
    }
    return 0;
}
