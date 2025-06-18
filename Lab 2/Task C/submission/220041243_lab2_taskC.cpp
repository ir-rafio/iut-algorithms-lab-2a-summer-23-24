#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

bool compare(const pair<LL, LL> &a, const pair<LL, LL> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

void pre()
{
    fastio;
}

void solve(int tc)
{
    LL noOfActivities, answer = 0, lastFinish = -1;

    cin >> noOfActivities;

    vector<pair<LL, LL>> activities(noOfActivities);

    for (LL i = 0; i < noOfActivities; i++) {
        cin >> activities[i].first;
    }

    for (LL i = 0; i < noOfActivities; i++) {
        cin >> activities[i].second;
    }

    sort(activities.begin(), activities.end(), compare);

    for (const auto &act : activities) {
        if (act.first >= lastFinish) {
            answer++;
            lastFinish = act.second;
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