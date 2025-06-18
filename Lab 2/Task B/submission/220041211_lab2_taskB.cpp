#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

LL minDot(LL* a, LL* b, int n){
    LL vproduct = 0;
    for(int i = 0; i < n; i++){
        vproduct += (a[i] * b[i]);
    }
    return vproduct;
}


signed main()
{
    pre();

    int t, n, x;
    cin >> t;

    while(t--){
        cin >> n;
        LL a[100000], b[100000];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n, greater<LL>());
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(b, b + n);
        cout << minDot(a, b, n) << endl;
    }
    

    return 0;
}