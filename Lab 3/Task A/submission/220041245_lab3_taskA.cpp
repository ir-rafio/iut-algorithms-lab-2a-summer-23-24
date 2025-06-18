#include<bits/stdc++.h>
using namespace std;


void dfs1(vector<int>adj[],int ar[],int eq, int n,int i){

    for(int neigh:adj[i]){
        int req=eq-ar[i];
        if(ar[neigh]>=req){
            ar[i]+=req;
            ar[neigh]-=req;
           
        }
             dfs1(adj,ar,eq,n,neigh);
        
    }



}

void dfs2(vector<int>adj[],int ar[],int eq, int n,int i){

    for(int neigh:adj[i]){
        int req=ar[i]-eq;
        if(ar[neigh]>=req){
            ar[i]-=req;
            ar[neigh]+=req;
           
        }
        
             dfs2(adj,ar,eq,n,neigh);
        
    }



}




int main(){

    int t;
    cin>>t;
    while(t--){

    int n,m;
    cin>>n>>m;
    int sum=0;
    int ar[n];
    vector<int>adj[n];
    for(int i=0;i<n;i++){
    	cin>>ar[i];
        sum+=ar[i];
    }
    if(sum%n!=0){
        cout<<"NO"<<endl;
    }
    else{
        int eq=sum/n;
    while(m--){
	int u,v;
	cin>>u>>v;
    u--;
    v--;
	
	adj[u].push_back(v);
    adj[v].push_back(u);


    }
    for (int i=0;i<n;i++){
        if(ar[i]<eq){
            dfs1(adj,ar,eq,n,i);
        }
        else if(ar[i]<eq){
            dfs2(adj,ar,eq,n,i);
        }
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        if(ar[i]!=ar[i+1]){
            flag=1;
            break;
        }
    }
    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    }



}

}
