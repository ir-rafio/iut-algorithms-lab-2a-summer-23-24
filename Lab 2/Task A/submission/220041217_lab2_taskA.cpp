#include <bits/stdc++.h>
using namespace std;
#define SONIC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ln '\n'
#define yes cout << "YES" << ln;
#define no  cout << "NO" << ln;
using ll = long long;

void solve(){
    ll n,x; cin>>n>>x;
    vector<ll>v(n,0);
    for(ll i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++)v[i] = v[i-1] + v[i];
    ll ans=0;
    for(int i=0;i<n;i++){
        if(v[i] > x){ans = i;break;}
    }
    cout << ans << endl;
//    for(auto& u: v)cout << u <<' ';
//    cout << endl;
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


