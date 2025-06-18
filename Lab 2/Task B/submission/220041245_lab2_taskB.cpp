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
    long long n;
    cin>>n;
    vector<long long>v1;
    vector<long long>v2;
    
    for(long long i=0;i<n;i++){
    	long long x;
    	cin>>x;
    	v1.push_back(x);
    }
    
    for(long long i=0;i<n;i++){
    	long long x;
    	cin>>x;
    	v2.push_back(x);
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.rbegin(),v2.rend());
    
    long long dp=0;
    
    for(long long i=0;i<n;i++){
	dp+= (v1[i]*v2[i]);
    }
    
    cout<<dp;
    
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
