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
    ll n , target ; cin >> n >> target ;
    
    vector<ll>v(n);
    for(ll i = 0 ; i < n ; i++)
    {
    	cin >> v[i];
    }
    sort(v.begin(),v.end());
    
    ll sum = 0;
    ll cnt  = 0;
    for(ll i = 0 ;i<n ; i++)
    {
    	sum += v[i];
    	if(sum >= target)
    	{
    	    if(sum > target) sum -= v[i];
    	    else cnt++;
    	    break;
    	}
    	cnt++;
    }
    cout << cnt <<endl;
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
