#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 11;
void dfs(int vertex , vector<int> graph[] , vector<int>&visited){
    visited[vertex] = 1;
    for(int child : graph[vertex]){
        if(visited[child]) continue;
        dfs(child ,graph ,visited);
    }

}
int main()
{
    int t;cin >> t;
    while(t--){
        int n,m , sum=0 , ans =0; cin >> n>>m ;
        vector<int > graph[n+1];
        vector<int> visited(n+1);
        vector<int> vc(n+1);
        for(int i=1;i<=n;i++) {cin >> vc[i] ;sum+= vc[i];}
        for(int i=0;i< m;i++) {
            int x,y; cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if(sum%n==0){
        sum/=n;
            dfs(1, graph , visited);
            for(int i=1;i<=n;i++){
                ans =1;
                if(visited[i]) continue;
                if(vc[i]!=sum){
                    ans =0;
                    break;
                }
            }
        }
        cout << "Case "<<t+1<<": ";
        if(ans)cout << "Yes"<< endl;
        else cout << "No"<< endl;

    }
}

