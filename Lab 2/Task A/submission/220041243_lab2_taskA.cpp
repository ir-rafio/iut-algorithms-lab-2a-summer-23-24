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
    LL noOfBottles, maxCapacity, answer = 0;

    cin >> noOfBottles >> maxCapacity;

    vector<LL> bottles(noOfBottles);

    for (LL &x : bottles) {
        cin >> x;
    }

    sort(bottles.begin(), bottles.end());

    for (LL i = 0; i < noOfBottles; i++) {
        if (bottles[i] <= maxCapacity) {
            answer++;
            maxCapacity -= bottles[i];
        } else {
            break;
        }
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