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
    LL n,ans=0;
    cin>>n;
    vector<LL>smaller(n),bigger(n),original(n);
    for(int i=0;i<n;i++)
    {
        cin>>smaller[i];
    }
     for(int i=0;i<n;i++)
    {
        cin>>bigger[i];
    }
    sort(bigger.begin(),bigger.end(),greater<int>());
    sort(smaller.begin(),smaller.end());
     for(int i=0;i<n;i++)
    {
        ans+=(smaller[i]*bigger[i]);
    }
    cout<<ans<<endl;
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