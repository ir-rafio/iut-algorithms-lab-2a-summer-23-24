#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

struct Activity {
    int start;
    int end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    int count = 0;
    int lastEndTime = -1;
    for (const auto& activity : activities) {

        if (activity.start >= lastEndTime) {
            count++;
            lastEndTime = activity.end;
        }
    }

    return count;
}



void pre()
{
    fastio;


}

void solve(int tc)
{

}

signed main()
{
    pre();
    int t;
       cin >> t;

       while (t--) {
           int n;
           cin >> n;

           vector<Activity> activities(n);
           vector<int> startTimes(n);
           vector<int> endTimes(n);

           for (int i = 0; i < n; i++) {
               cin >> startTimes[i];
           }

           for (int i = 0; i < n; i++) {
               cin >> endTimes[i];
           }

           for (int i = 0; i < n; i++) {
               activities[i] = {startTimes[i], endTimes[i]};
           }


           int result = maxActivities(activities);
           cout << result << endl;
       }

       return 0;
}
