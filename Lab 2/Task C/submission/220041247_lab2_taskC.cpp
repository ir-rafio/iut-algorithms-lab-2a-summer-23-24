#include <bits/stdc++.h>
#include <functional>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t; 
        while(t--){
        ll n , l =0,   ans=0; cin >> n ;
        vector<ll>v(n),e(n);
        vector<pair<ll, ll> >vp(2*n);
        for(int i=0;i< n;i++) {
            cin >> vp[i].first;
            vp[i].second=0;
        }
        for(int i=n;i< 2*n;i++) {
            cin >> vp[i].first;
            vp[i].second=1;

        }
        sort(vp.begin(), vp.end());
        for(int i=0;i<2*n;i++){
            if(vp[i].second==0) l++;
            if(vp[i].second==1){
                ans++;
                if(l==n) break;
            }
        }
        cout << ans << endl;
    }
}