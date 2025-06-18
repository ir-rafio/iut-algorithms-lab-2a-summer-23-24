#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

struct Activity {
    int start;
    int end;
};

bool cmp(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

void pre() {
    fastio;
}

void solve(int tc) {
    int n;
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start;
    }
    for (int i = 0; i < n; i++) {
        cin >> activities[i].end;
    }

    sort(activities.begin(), activities.end(), cmp);

    int cnt = 0, lastEndTime = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEndTime) {
            cnt++;
            lastEndTime = activities[i].end;
        }
    }

    cout << cnt;
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
