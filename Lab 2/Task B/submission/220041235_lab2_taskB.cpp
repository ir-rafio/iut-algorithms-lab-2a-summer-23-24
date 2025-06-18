#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long 
using LL = long long;



void pre()
{
    fastio;

    
}

bool cmp(int a , int  b)
{
    return a>b;
}

void solve(int tc)
{
    int n ;  cin >> n ;
    vector<int>v(n),b(n);
    for(auto &a:v)
    {
        cin >> a ;
    }
    for(auto &a:b)
    {
        cin >> a ;
    }
    sort(v.begin(),v.end());
    sort(b.begin(),b.end(),cmp);
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=v[i]*b[i]*1LL;
    }
    cout<<res<<endl;
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