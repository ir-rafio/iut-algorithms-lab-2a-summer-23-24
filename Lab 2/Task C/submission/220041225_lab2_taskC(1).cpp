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
    cin>>n;

    vector<int>arr(n);
    vector<int>brr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cin>>brr[i];
    }

    vector<pair<int,int>>v(n);


    for(int i=0;i<n;i++){
        v[i].first=arr[i];
        v[i].second=brr[i];
    }

    sort(v.begin(),v.end());

    int c=0;
    int last=0;

    for(int i=0;i<n;i++){
        if(v[i].first>last){
            c++;
            last=v[i].second;
        }
    }
    cout<<c<<"\n";
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
