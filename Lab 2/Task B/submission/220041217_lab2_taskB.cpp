#include <bits/stdc++.h>
using namespace std;
#define SONIC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ln '\n'
#define yes cout << "YES" << ln;
#define no  cout << "NO" << ln;
using ll = long long;

void solve(){
    ll n; cin>>n;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += a[i] * b[i];
    }

    cout << ans << ln;
}


signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    SONIC;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}
