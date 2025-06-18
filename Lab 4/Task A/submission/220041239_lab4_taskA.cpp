#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
     
    vector<vector<pair<long,long>>> adj(n+1); 
    vector<long long> dist(n+1);
    priority_queue<pair<long,long>,vector<pair<long ,long>>,greater<pair<long,long>>> pq;
    while(m--){
        long long a,b,d;
        cin>>a>>b>>d;
       
        adj[a].push_back({d,b});


    }

    long long max=1e16;

    for(long long i=0;i<=n;i++){
        dist[i]=max;
    }
    dist[0]=0;
    dist[1]=0;
    pq.push({0,1});
   while(!pq.empty()){
    int wieght=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto it: adj[node]){
        long long edgeweight=it.first;
        long long node2=it.second;

        if( edgeweight > dist[node2] )
       {
           continue;
       }


        if(edgeweight+wieght<dist[node2]){
            dist[node2]=edgeweight+wieght;
            pq.push({dist[node2],node2});
        }
    }
   }
  
  for(long long i=1;i<=n;i++){
    cout<<dist[i]<<" ";

  }

}
