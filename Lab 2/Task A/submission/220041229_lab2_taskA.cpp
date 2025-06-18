#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using grid = vector<vi>;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
#define en "\n"
#define ln " \n"[i == n - 1]
#define sz(_O) _O.size()
#define fix(_O) cout << setprecision(_O) << fixed
#define fr(_O, _O2) for (int i = _O; i < _O2; i++)
#define fir(_O) for (int i = 0, ii = _O - 1; i < _O; ++i, --ii)
#define fjr(_O) for (int j = 0, jj = _O - 1; j < _O; ++j, --jj)
ll const inf = 1e18;    // 0x3f3f3f3f3f3f;
ll const mod = 1e9 + 7; // 998244353;

void process_case()
{
    ll n;
    cin >> n;
    ll x;
    cin >> x;

    vi v(n);
    fir(n) cin >> v[i];
    ll score = 0;
    sort(v.begin(), v.end());
    fir(n)
    {
        if (x <= 0)
            break;
        if (x >= v[i])
        {
            x -= v[i];
            score++;
        }
    }
    cout << score << en;
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef FARHAN_TAHSIN
    cin.tie(nullptr);
#endif

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases-- > 0)
        process_case();
}