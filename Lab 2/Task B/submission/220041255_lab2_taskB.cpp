#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void solve(int tc) {
    int n;
    cin >> n;

    vector<LL> vec1(n), vec2(n);

    for (int i = 0; i < n; i++) {
        cin >> vec1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vec2[i];
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end(), greater<int>());

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += vec1[i] * vec2[i];
    }

    cout << ans;
}

int main() {
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
