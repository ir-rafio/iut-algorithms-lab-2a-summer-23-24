#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

int non_overlap(vector<LL>& starttime, vector<LL>& endtime) {
    int n = starttime.size();
    vector<pair<LL, LL>> activities;

    for (int i = 0; i < n; ++i)
        activities.push_back({endtime[i], starttime[i]});

    sort(activities.begin(), activities.end());

    int count = 0;
    LL last_end = -1;
    for (auto& act : activities) {
        if (act.second >= last_end) {
            ++count;
            last_end = act.first;
        }
    }
    return count;
}


void solve(int tc)
{
    LL n;
    cin >> n;
    vector <LL> starttime(n);
    vector <LL> endtime(n);
    for(LL i=0;i<n;i++){
        cin >> starttime[i];
    }
    for (LL i=0;i<n;i++){
        cin >> endtime[i];
    }
    cout << non_overlap(starttime,endtime);

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