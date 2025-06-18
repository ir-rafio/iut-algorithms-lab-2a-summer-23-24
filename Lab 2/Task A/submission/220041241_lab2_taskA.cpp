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
    LL n,x,y=0,ans_ind,ans;
    cin>>n>>x;
    vector<LL>bottle(n),prefix(n);
    for(int i=0;i<n;i++)
    {
        cin>>bottle[i];
    } 
     sort(bottle.begin(),bottle.end());
     for(int i=0;i<n;i++)
    {
        prefix[i]=bottle[i]+y;
        y=prefix[i];
        if(prefix[i]>x)
        {
           ans_ind=i-1;
           ans=ans_ind+1;
           break;
        }
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