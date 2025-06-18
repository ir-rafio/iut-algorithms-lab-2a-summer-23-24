#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;





void pre()
{
    fastio;

    
}

bool dfs(int &i,vector<vector<int>> &adjMat,vector<int>&arr,int &cost,int &cnt,vector<int>&visited,int avg){
    visited[i]=1;
    cost+=arr[i];
    cnt++;

    for(auto child: adjMat[i]){
        if(visited[child]==1)
            continue;
        dfs(child,adjMat,arr,cost,cnt,visited,avg);

    }

    if(cost%cnt!=0)
        return false;
    else 
        return (cost/cnt)==avg;
}

void solve(int tc)
{
    int n,m;

    cin>>n>>m;

    vector<int>arr(n+1);
    int sum=0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    vector<vector<int>> adjMat(n+1);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adjMat[x].push_back(y);
        adjMat[y].push_back(x);
    }

    if(sum%n!=0){
        cout<<"No\n";
        return;
    } 

    int avg=sum/n;
    vector<int>visited(n+1,0);

    for(int i=1;i<=n;i++){
        int cost=0,cnt=0;
        bool flag=true;
        if(visited[i]!=1)
            flag=dfs(i,adjMat,arr,cost,cnt,visited,avg);

        if(flag==false){ 
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
         cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}