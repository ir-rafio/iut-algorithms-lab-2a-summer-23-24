#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void pre() {
    fastio;
}

void solve(int tc) {
    int x, n;
    cin >> n >> x;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int sum = 0, cnt;
    for (cnt = 0; cnt < n && arr[cnt] <= x; x -= arr[cnt], cnt++) {

    }

    cout << cnt << "\n";
}

int main() {
    pre();

    int tc, tt = 1;
    cin >> tt;

    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
    }

    return 0;
}
