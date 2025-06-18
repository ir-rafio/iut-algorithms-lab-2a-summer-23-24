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
    LL n;
    cin>>n;
    vector<pair<LL, LL>>events(n);

    for(int i=0;i<n;i++)
    {
        cin>>events[i].second;

        for(int i=0;i<n;i++)
        {
            cin>>events[i].first;
        }

        sort(events.begin(),events.end());

        LL lastEnd=events[0].first;
        LL count =1;

        for (int i=0;i<n;i++)
        {
            if(events[i].second>lastEnd)
            {
            lastEnd=events[i].first;
            count++;
            }
        }

cout<<count;

}    }


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