#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using ll= long long;


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll arr1[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        for(ll i=0;i<n;i++){
            cin>>arr1[i];
        }
        sort(arr,arr+n);
        sort(arr1,arr1+n,greater<ll>());
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i]*arr1[i];
        }
        cout<<sum<<endl;
    }
}