#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int main() {
    fastio;
    int it;
    cin >> it;

    for (int i = 0; i < it; i++) {
        int n, x;
        cin >> n >> x;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (x >= v[j]) {
                x -= v[j];
                count++;
            } else {
                break;
            }
        }

        cout << count << endl;
    }

    return 0;
}

