#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;




int main()
{
    int a;
    cin >> a;

    while (a--)
    {
        int n;
        cin >> n;

        vector<int> start(n), end(n);
        for (int i = 0; i < n; ++i)
            cin >> start[i];
        for (int i = 0; i < n; ++i)
            cin >> end[i];

        vector<pair<int, int>> s(n);
        for (int i = 0; i < n; ++i)
            s[i] = {end[i], start[i]};

        sort(s.begin(), s.end());

        int count = 0;
        int last_end_time = 0;

        for (const auto& v : s)
        {
            if (v.second >= last_end_time)
            {
                ++count;
                last_end_time = v.first;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
