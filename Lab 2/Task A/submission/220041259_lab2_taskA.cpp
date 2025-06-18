#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>q){
                cout<<i<<endl;
                break;
            }
            else if(sum==q){
                cout<<i+1<<endl;
                break;
            }
        }
        if(sum<q){
            cout<<n-1<<endl;
        }
    }
}