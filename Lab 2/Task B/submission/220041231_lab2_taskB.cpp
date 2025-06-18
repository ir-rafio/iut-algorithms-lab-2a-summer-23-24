#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll ;

void pre() 
{
    fastio;
}

void solve(int tc) 
{

    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (ll &x : a) 
    {
        cin >> x;
    }
    for(ll &x : b) 
    {
        cin >> x;
    }

    sort(a.begin(), a.end());        
    sort(b.rbegin(), b.rend());      

    ll min_sum = 0;
    for (ll i = 0; i < n; i++) 
    {
        min_sum += a[i] * b[i]; 
    }

    cout << min_sum << '\n';
}

signed main()
{
    pre();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) 
    {
        solve(t);
        cout << "\n" ;
    }
    return 0;
}
