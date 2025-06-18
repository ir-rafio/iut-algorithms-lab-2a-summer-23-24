#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> start(n), end(n);
        
        for (int i = 0; i < n; i++) {
            cin >> start[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> end[i];
        }
        
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }
        
        sort(activities.begin(), activities.end());
        
        int count = 0;
        int last_end_time = -1;
        
        for (int i = 0; i < n; i++) {
            if (activities[i].second >= last_end_time) {
                count++;
                last_end_time = activities[i].first;
            }
        }
        
        cout << count << endl;
    }

    return 0;
}

