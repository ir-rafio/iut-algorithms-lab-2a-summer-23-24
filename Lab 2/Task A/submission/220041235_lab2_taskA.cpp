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
    int n , x; 
    cin >> n >> x ;
    vector<int>v(n);
    for(auto &a:v)
    {
        cin >> a ;
    }
    sort(v.begin(),v.end());
    int count=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>x)
            break;
        count++;
    }
    cout<<count<<endl;
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
        //cout << '\n';
    }

    return 0;
}