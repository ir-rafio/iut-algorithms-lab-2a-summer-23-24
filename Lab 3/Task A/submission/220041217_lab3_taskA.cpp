#include <bits/stdc++.h>
using namespace std;
#define SONIC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ln '\n'
#define yes cout << "YES" << ln;
#define no  cout << "NO" << ln;
using ll = long long;

#define mx 1005

int money[mx];
vector<int>g[mx];
bool visited[mx];


int dfs(int src,int need){
    if(visited[src]) return 0;
    visited[src]=1;
    int ans = money[src]- need;
    for(int i = 0; i < g[src].size(); i++){
        ans += dfs(g[src][i],need);
    }
    return ans;
}

void solve(){
    int t;  cin>>t;
    for(int z = 1; z <= t; z++){
        int n,m;    cin>>n>>m;

        memset(g, 0, sizeof(g));
        memset(visited,0,sizeof(visited));
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

        if(sum % n != 0){
            cout << "Case " << z << ": No\n";
            continue;
        }

        int need = sum / n;
        int ans = 0;
        bool flag = true;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ans = dfs(i,need);
                if(ans != 0){
                    flag = false; break;
                }

            }
        }
        cout << "Case " << z << ": ";
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    SONIC;
//    ll t;
//    cin>>t;
//    while(t--){
        solve();
//    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}