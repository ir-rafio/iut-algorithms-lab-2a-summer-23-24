#include<bits/stdc++.h>

#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)

#define mx 1005


using namespace std;
typedef long long ll;

int money[mx];
vector<int> g[mx];
int need;
bool visited[mx];
int dfs(int src){
    if(visited[src]) return 0;
    visited[src]=1;
    int ans = need-money[src];
    for(int i = 0; i < g[src].size(); i++){
        ans += dfs(g[src][i]);
    }
    return ans;
}

int main()
{
    int t;  cin>>t;
    for(int z = 1; z <= t; z++){
        memset(visited,0,sizeof(visited));
        int n,m;    cin>>n>>m;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin>>money[i];
            sum+=money[i];
        }

        int a,b;
        for(int i = 0; i < m; i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        need = sum/n;
        int ans = 0;
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ans = dfs(i);
                if(ans != 0)
                    flag = false;
            }
        }
        printf("Case %d: ",z);
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
}
