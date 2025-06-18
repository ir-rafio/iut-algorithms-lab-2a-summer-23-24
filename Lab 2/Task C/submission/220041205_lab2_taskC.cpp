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
    vector<pair<LL, LL>> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> activities[i].first;
    }

    sort(activities.begin(), activities.end());
    int count = 0;
    int prevEnd = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].second >= prevEnd) {
            count++;
            prevEnd = activities[i].first;
        }
    }
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