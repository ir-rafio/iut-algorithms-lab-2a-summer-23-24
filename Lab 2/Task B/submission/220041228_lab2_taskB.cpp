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
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>rb(n);
    for(int i=0; i<n; i++){
        cin>>a[i];

    }
    for(int i=0; i<n; i++){
        cin>>b[i];

    }

    sort(a.begin(),a.end());

    sort(b.begin(),b.end());

    reverse(b.begin(),b.end());

    // for(int i=0; i<n; i++){
    //     cout<<b[i];

    // }
    LL ans=0;
    for(int i=0; i<n;i++){
      
        ans+=a[i]*b[i];
        
    }

    cout<<ans<<endl;
   
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
