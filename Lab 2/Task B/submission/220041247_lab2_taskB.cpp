#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t; 
        while(t--){
        ll n ,    ans=0; cin >> n ;
        vector<ll>v(n),e(n);
        for(int i=0;i< n;i++) cin >> v[i];
        for(int i=0;i< n;i++) cin >> e[i];
        sort(v.begin(), v.end());
        sort(e.begin(), e.end(), greater<ll>());
        for(int i=0;i<n;i++){
            ans+=v[i]*e[i];
        }
        cout << ans << endl;
    }
}