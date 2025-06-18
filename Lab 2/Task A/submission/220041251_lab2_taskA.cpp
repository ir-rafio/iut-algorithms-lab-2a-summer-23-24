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
 long long n, x;
 cin >> n >> x;
 vector<int> a(n);
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 sort(a.begin(), a.end());
 long long count = 0;
 for (int i = 0; i < n; i++) {
 if (x >= a[i]) {
 x -= a[i];
 count++;
 } else {
 break;
 }
 }
 cout << count << endl;
 }
 return 0;

}
