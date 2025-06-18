#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


void pre()
{
    fastio;

    
}
void sortAsc(int* a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
int maxFilled(int* a, int n, int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum > x){
            return i;
        }
    }
    
}


signed main()
{
    pre();

    int t, n, x;
    cin >> t;
    
    while(t--){
        cin >> n >> x;
        int a[1000];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sortAsc(a, n);
        cout << maxFilled(a, n, x) << endl;
    }

    return 0;
}
