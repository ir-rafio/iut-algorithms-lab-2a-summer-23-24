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
    int n;
    long long x;
    cin>>n>>x;

    long long bott[n];
    int i;
    for(i=0;i<n;i++)
    { 
        cin>>bott[i];
    }
sort(bott,bott+n);

 int count=0;

for (int j=0;j<n;j++)
 {
    x-=bott[j];
       
     if(x<0)
    {
       break;
    }
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
        cout << '\n';
    }

    return 0;
}