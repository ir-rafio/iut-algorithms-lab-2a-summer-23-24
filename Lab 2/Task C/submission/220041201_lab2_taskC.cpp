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
    int n,c=0, e;
        cin >> n ;

        vector<pair<int,int>> s(n);
        //vector<int> e(n);

        for(int i=0;i<n;i++){
            cin >> s[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> s[i].second;
        }
        sort(s.begin(), s.end(), greater<pair<int,int>>());
        //sort(b.begin(), b.end(), greater<int>());
        e = s[n-1].first;
        for(int i=n;i>0;i--){
            if(e>s[i-1].second){
                c++; e= s[i-1].second;
            }
        }
        cout << c+1;
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
