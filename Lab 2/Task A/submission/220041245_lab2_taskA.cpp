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
    int n,x;
    cin>>n>>x;
    int ar[n];
    for(int i =0;i<n;i++){
    	cin>>ar[i];
    }
    
    sort(ar,ar+n);
    
    int cnt=0;
    
    for(int i=0;i<n;i++){
    	x-=ar[i];
    	if(x>-1){
    	cnt++;
    	}
    }
    cout<<cnt<<endl;
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
