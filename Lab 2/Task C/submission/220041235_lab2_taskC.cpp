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
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].second;
    }
    for(int i=0;i<n;i++)
    {
        cin >> v[i].first;
    }
    sort(v.begin(),v.end());
    int lastend=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second>lastend)
        {
            count++;
            lastend=v[i].first;
        }
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