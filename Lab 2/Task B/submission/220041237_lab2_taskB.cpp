#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int size;
        cin >> size;
        vector<long long> a;
        vector<long long> b;
        int x;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += a[i] * b[i];
        }
        cout << sum << endl;
    }
    return 0;
}