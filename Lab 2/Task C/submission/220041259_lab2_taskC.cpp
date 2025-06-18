// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(0); cin.tie(0)
// using ll = long long;

// int main(){

//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int arr[n];
//         int arr1[n];
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         for(int i=0;i<n;i++){
//             cin>>arr1[i];
//         }

//         vector<pair<int,int>>v;
//         for(int i=0;i<n;i++){
//             v.push_back(make_pair(arr1[i],arr[i]));
//         }
//         sort(v.begin(),v.end());

//         int count=0;
//         bool f=false;

//         for(int i=0;i<n-1;i++){
//             const auto &p=v[i];
//             for(int j=i+1;j<n;j++){
//                 const auto &p1=v[j];
//                 if((p.second-p1.first)<0){
//                     count++;
//                     f=true;
//                     break;
//                 }
//             }
//             if(f==true){
//                 continue;
//             }
//         }
//         cout<<count<<endl;
//     }


// }




#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int arr1[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(arr1[i],arr[i]));
        }
        sort(v.begin(),v.end());

        int count=0;
        int end=0;

        for(auto &p : v){
            if(p.second >= end){
                count++;
                end = p.first;
            }
        }
        cout<<count<<endl;
    }


}