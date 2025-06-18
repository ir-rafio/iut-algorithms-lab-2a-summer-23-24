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
    cin >>n;
    vector <LL> arr(n);
    vector <LL> arr2(n);
    for(LL i=0;i<n;i++){
        cin >> arr[i];
    }
    for (LL i=0;i<n;i++){
        cin >> arr2[i];
    }
    sort(arr.begin(), arr.end());
    sort(arr2.rbegin(), arr2.rend());
    LL dotproduct=0;
    for(LL i=0;i<n;i++){
        dotproduct += arr[i]*arr2[i];
    }
    cout << dotproduct;
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