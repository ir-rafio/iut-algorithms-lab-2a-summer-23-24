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
    vector<pair<LL,LL>> v1(n);
    for(LL i=0;i<n;i++)
        cin>>v1[i].second;
    for(LL i=0;i<n;i++)
        cin>>v1[i].first;
    sort(v1.begin(),v1.end());
    int end=0;
    int mx=0;
    for(int i=0;i<n;i++){
        if(v1[i].second>end){
            mx++;
            end=v1[i].first;
        }
    }
     cout<<mx<<endl;    
     
        
    
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