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
    vector<LL>v1;
    vector<LL>v2;
    for(LL i=0;i<n;i++){
        LL x;
        cin>>x;
        v1.push_back(x);
    }
        
        
    for(LL i=0;i<n;i++){
        LL x;
        cin>>x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.rbegin(),v2.rend());

    LL dot=0;
    for(LL i=0;i<n;i++){
        dot+=v1[i]*v2[i];
    }
    cout<<dot<<endl;
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