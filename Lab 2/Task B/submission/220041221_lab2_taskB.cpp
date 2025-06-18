#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    vector<long long int> outputs;

    while (t--)
    {
        cin >> n;
        vector<long long int> a(n);
        vector<long long int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        sort(b.rbegin(), b.rend());

        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i] * b[i];
        }
        outputs.push_back(sum);
    }

    for (long long int x : outputs)
    {
        {
            cout << x << endl;
        }
    }
    return 0;
}