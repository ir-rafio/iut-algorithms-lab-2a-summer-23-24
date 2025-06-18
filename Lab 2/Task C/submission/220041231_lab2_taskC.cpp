#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
using LL = long long;

void pre()
{
    fastio;
}

void solve(int tc)
{
    int n;
    cin >> n;
    int s[n];
    int e[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(e[i], s[i]));
    }
    sort(v.begin(), v.end());

    int count = 0;
    int end = 0;

    for (auto &p : v)
    {
        if (p.second >= end)
        {
            count++;
            end = p.first;
        }
    }
    cout << count << endl;
}


signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;

    for (tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}
