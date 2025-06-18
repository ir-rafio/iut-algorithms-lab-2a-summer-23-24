#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
const int N =1e5;
int parent[N] , Size[N];
void make(int v){
    parent[v]=v;
    Size[v] =1;
}

int finds(int v){
    if(v==parent[v]) return v;
    return  parent[v] =  finds(parent[v]);
}

void Union(int a , int b){
    a = finds(a);
    b = finds(b);
    if(a!=b){
        if(Size[a]<Size[b])  swap(a,b);
        parent[b] = a;
        Size[a]+=Size[b];
    }
}
int main()
{   
    int n , p  , ans=0; cin >> n>> p;
    vector<int>v(n);
    for(int i =0;i<n;i++) { 
        make(i);
    }
    for(int i=0;i<p;i++){
        int x, y; cin >> x >> y ;
        Union(x, y);
    }
    for(int i=0;i<n;i++){
        v[parent[i]]++;
    }
    for(int i=0;i<n;i++){
        if(v[i]==0) continue;
        ans += (n-v[i])*v[i];
    }
    cout << ans/2<< endl;
      
}