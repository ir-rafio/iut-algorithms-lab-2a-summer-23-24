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
    cin >> n;
    vector<LL> vec1;
    vector<LL> vec2;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        vec1.push_back(num);
    }
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        vec2.push_back(num);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.rbegin(), vec2.rend());
    LL sum = 0;
    for(int i=0; i<n; i++){
        sum += (vec1[i]*vec2[i]);
    }
    cout << sum << endl;
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