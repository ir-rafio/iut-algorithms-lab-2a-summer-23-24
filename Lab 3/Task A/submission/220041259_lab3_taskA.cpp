#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void dfs(int node,const vector<vector<int>>&adj,vector<int>&vis,vector<int>&component){
    vis[node]=1;
    component.push_back(node);
    for(int neighbor:adj[node]){
        if(!vis[neighbor]){
            dfs(neighbor,adj,vis,component);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        
        vector<int>v(n);
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        int sum=0;

        for(int j=0;j<n;j++){
            cin>>v[j];
            sum+=v[j];
        }

        for(int k=0;k<m;k++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout<<"Case "<<i<<": ";
        if(sum%n!=0){
            cout<<"No"<<endl;
            continue;
        }

        int avg=sum/n;
        bool possible=true;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>component;
                dfs(i,adj,vis,component);

                int comp_sum=0;
                for(int person:component){
                    comp_sum+=v[person];
                }

                if(comp_sum!=avg*component.size()){
                    possible=false;
                    break;
                }
            }
        }

        if(possible){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }

    return 0;
}