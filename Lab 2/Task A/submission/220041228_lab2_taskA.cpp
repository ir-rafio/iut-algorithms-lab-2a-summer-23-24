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

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    int c=0;
    for(int i=0; i<n; i++){
        if(x>=v[i]){
            x-=v[i];
            c++;

        }
        else break;
    }
    cout<<c<<endl;
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
