#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

struct Activity
{
    ll start;
    ll end;
};

bool compareByEnd(const Activity &a, const Activity &b)
{
    return a.end < b.end;
}

int maxNonOverlappingActivities(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compareByEnd);

    int count = 1; 
    ll lastEnd = activities[0].end;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= lastEnd)
        {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> StartingTimes(n);
        vector<ll> Endingtimes(n);

        for (int i = 0; i < n; i++)
            cin >> StartingTimes[i];
        for (int i = 0; i < n; i++)
            cin >> Endingtimes[i];

        vector<Activity> activities(n);
        for (int i = 0; i < n; i++)
        {
            activities[i].start = StartingTimes[i];
            activities[i].end = Endingtimes[i];
        }

        cout << maxNonOverlappingActivities(activities) << "\n";
    }

    return 0;
}
