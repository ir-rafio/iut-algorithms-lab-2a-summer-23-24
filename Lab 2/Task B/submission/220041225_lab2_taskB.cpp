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
    cin>>n;

    vector<long long >arr(n);
    vector<long long>brr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cin>>brr[i];
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end(),greater<int>());

    long long sum=0;

    for(int i=0;i<n;i++){
        sum+=(arr[i]*brr[i]);
    }

    cout<<sum;
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
