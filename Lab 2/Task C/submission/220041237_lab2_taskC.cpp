#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> s(n), e(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> e[i];
        }

        vector<pair<int, int>> activities(n);
        for (int i = 0; i < n; ++i)
        {

            activities[i] = {e[i], s[i]};
        }
        sort(activities.begin(), activities.end());

        int count = 0, last_end = 0;
        for (auto [end, start] : activities)
        {
            if (start >= last_end)
            {
                count++;
                last_end = end;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
