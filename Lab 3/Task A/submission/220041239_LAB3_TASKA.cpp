#include<bits/stdc++.h>

using namespace std;


void dfs(int peopleNum,int i,vector<vector<int>> &adj,vector<int> &moneys,int &sum,int &count,vector<int> &visited){
visited[i]=1;
count++;
sum+=moneys[i];
for(int j=1;j<=peopleNum;j++){
    if(!visited[j] && adj[i][j]){
    dfs(peopleNum,j,adj,moneys,sum,count,visited);
    }
}

}

int main(){
   int n;
   cin>>n;
while(n--){
    int peopleNum,Peoplerel;
    cin>>peopleNum>>Peoplerel;
    
    vector<vector<int>> adj(peopleNum+1,{peopleNum+1,0});

    vector<int> moneys(peopleNum+1);

    vector<int> visited(peopleNum+1,0);
     
    for(int i=1;i<=peopleNum;i++){
        cin>>moneys[i];
    }
    for(int i=1;i<=Peoplerel;i++){
    int m,n;
    cin>>m>>n; 

    adj[n][m]=1;
    adj[m][n]=1;
    }
    
 int ans=1;
    for(int i=1;i<=peopleNum;i++){
     int sum=0;int count=0;
    
     if(!visited[i]){
        dfs(peopleNum,i,adj,moneys,sum,count,visited);
        if(sum%count!=0){
          ans=0;
          break;
        }
     }

    }
    if(ans==0){
        cout<<"no"<<endl;
    }
    else{
        cout<<"yes"<<endl;
    }

}
}
