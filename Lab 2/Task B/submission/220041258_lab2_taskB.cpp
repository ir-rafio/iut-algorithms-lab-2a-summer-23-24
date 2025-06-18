#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


int main()
{

    int m;
    cin >> m;
    long long product= 0;
    while (m--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];


        for (int i = 0; i < n; ++i)
            cin >> b[i];


        sort(a.begin(), a.end());

        sort(b.begin(), b.end(), greater<long long>());

        for (int i = 0; i < n; ++i)
            product += a[i] * b[i];

        cout << product << '\n';
    }

    return 0;
}

