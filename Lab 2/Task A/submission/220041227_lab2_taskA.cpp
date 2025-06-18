#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



int main(){
    int t;
    cin>>t;


    while(t--){
        int n;
        LL x;
        cin>>n>>x;

        vector<LL> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        sort(v.begin(),v.end());

        int count=0;
        for(int i=0; i<n; i++){
        if(x>=v[i]){
            x -= v[i];
            count++;

        } else break;


    }

    cout<< count <<endl;
    }

   return 0;

}

