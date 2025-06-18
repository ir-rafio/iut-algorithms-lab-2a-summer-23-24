#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}



signed main()
{

    int tc, tt = 1, n;
    cin >> tt;

    while(tt--){
        cin>>n;
        vector <LL> a(n);
        vector <LL> b(n);
        for(int i =0; i<n; i++){
            cin>>a[i];

        }
        sort(a.begin(), a.end(), greater<int>());
        for(int i =0; i<n; i++){
            cin>>b[i];
        }
        sort(b.begin(), b.end());

       LL dotprod=0;
        LL prod =0;

        for(int i =0; i<n; i++){

                prod = a[i]*b[i];
                dotprod +=prod;

        }
        cout<<dotprod<<endl;

    }
    return 0;
}
