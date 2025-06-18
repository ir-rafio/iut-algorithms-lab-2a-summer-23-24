#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        int n,m;
        cin>>n>>m;
        vector<int> arr,check(n+1,0);
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            arr.push_back(x);
        }
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            check[u]++;
            check[v]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int ans=0;
        
        if((sum%n==0)&&(n-m==1))cout<<"Case "<< j<<": Yes"<<endl;
        else cout<<"Case "<< j<<": No"<<endl;
    }
    return 0;
}