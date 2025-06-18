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
    LL noOfElements, answer = 0;

    cin >> noOfElements;

    vector<LL> a(noOfElements), b(noOfElements);

    for (LL &x : a) {
        cin >> x;
    }

    for (LL &x : b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (LL i = 0; i < noOfElements; i++) {
        answer += (a[i] * b[i]);
    }

    cout << answer << endl;
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