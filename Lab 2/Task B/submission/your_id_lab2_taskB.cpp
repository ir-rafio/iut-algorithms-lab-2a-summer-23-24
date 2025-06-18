#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
typedef long long ll;


void pre()
{
    fastio;

    
}

void solve(int tc)
{
    ll n ; cin >> n ;
    vector<ll>v(n);
    vector<ll>v1(n);
    
    for(ll i = 0 ; i < n ; i++)
    {
    	cin >> v[i];
    }
    for(ll i = 0 ; i < n ; i++)
    {
    	cin >> v1[i];
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end(),greater<ll>());
    
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++)
    {
    	sum += v[i]*v1[i];
    }
    cout << sum <<endl;
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
