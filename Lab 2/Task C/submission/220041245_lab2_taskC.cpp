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
    vector<pair<long long,long long>>v(n);
    
    for(int i=0;i<n;i++){
    	cin>>v[i].second;
    }
    for(int i=0;i<n;i++){
    	cin>>v[i].first;
    }
    

    sort(v.begin(),v.end());
    long long last=v[0].first;
    long long cnt=1;
    for(long long i=0;i<n;i++){
    	if(v[i].second>last){
    		last=v[i].first;
    		cnt++;
    	}
    }
    cout<<cnt;	
    
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
