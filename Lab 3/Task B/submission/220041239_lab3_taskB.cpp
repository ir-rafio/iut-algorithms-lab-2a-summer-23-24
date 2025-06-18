#include<bits/stdc++.h>

using namespace std;


void dfs(int peopleNum,int i,vector<vector<int>> &adj,int &count,vector<int> &visited){
visited[i]=1;
count++;
for(int j=1;j<=peopleNum;j++){
    if(!visited[j] && adj[i][j]){
    dfs(peopleNum,j,adj,count,visited);
    }
}

}


int main(){
int n,m;
cin>>n>>m;
 
vector<vector<int>> adj(n,vector<int>(n,0));
vector<int> visited(n,0);
while(m--){
int a,b;
cin>>a>>b;

adj[a][b]=1;
adj[b][a]=1;
}
int totalPair=(n*(n-1))/2;



for(int i=0;i<n;i++){
int count=0;
if(!visited[i]){
    dfs(n,i,adj,count,visited);
    totalPair-=(count*(count-1))/2;
}
}

cout<<totalPair<<endl;

}
