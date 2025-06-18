#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t; 
        while(t--){
        ll n , k ,  r=0, ans=0; cin >> n >> k;
        vector<ll>v(n),q;
        for(int i=0;i< n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        int i;        
        for(i=1; i <= n;i++){
            r+= v[i-1];
            if(r>k) break;
            ans++;
        }
        cout << ans << endl;
    }
}

