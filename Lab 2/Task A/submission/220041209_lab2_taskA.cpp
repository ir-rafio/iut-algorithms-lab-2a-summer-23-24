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
        int n,c;
        cin >> n >> c;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int j=0;
        while(j<n && c-arr[j]>=0){
            c-=arr[j];
            j++;
        }
        cout << j ;
    
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