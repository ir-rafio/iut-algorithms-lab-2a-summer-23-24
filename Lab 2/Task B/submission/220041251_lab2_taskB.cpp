#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



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
           vector<int> a(n), b(n);
           for (int i = 0; i < n; i++) {
               cin >> a[i];
           }
           for (int i = 0; i < n; i++) {
               cin >> b[i];
           }
           sort(a.begin(), a.end());
           sort(b.begin(), b.end(), greater<int>());

           long long dot_product = 0;
           for (int i = 0; i < n; i++) {
               dot_product += static_cast<long long>(a[i]) * b[i];
           }
           cout << dot_product << endl;
       }
       return 0;
}
