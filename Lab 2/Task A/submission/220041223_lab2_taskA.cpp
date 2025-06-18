#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void selection_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min =i;
        for(int j =i+1; j<n; j++){
            if(a[j]<a[min]) min = j;
        }
        swap(a[min], a[i]);
    }
}

signed main(){
    pre();

    int tc, tt = 1, n, x;
    int a[10000];
    cin >> tt;


    while(tt--){
        cin>>n>>x;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        selection_sort(a, n);
        int sum =0;
        for(int k =0; k<n; k++){

            sum += a[k];
            //cout<<sum<<endl;
            if(sum>x){
            cout<<k<<endl;
            break;
                }
            }
    }

    return 0;
}
