#include <bits/stdc++.h>
using namespace std;
#define SONIC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ln '\n'
#define yes cout << "YES" << ln;
#define no  cout << "NO" << ln;
using ll = long long;

void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis, vector<int>& comp) {
    vis[node] = true;
    comp.push_back(node);
    for(int nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, adj, vis, comp);
        }
    }
}

int cnt_pairs(int n, int p, vector<pair<int, int>>& pairs) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for(auto& pr : pairs){
        adj[pr.first].push_back(pr.second);
        adj[pr.second].push_back(pr.first);
    }

    ll tot_pair = (ll)n*(n - 1)/2;
    ll inv_pair = 0;

    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            vector<int> c;
            dfs(i, adj, visited, c);
            int size = c.size();
            if(size > 1){
                inv_pair += (ll)size * (size - 1) / 2; // C(size, 2)
            }
        }
    }
    return tot_pair - inv_pair;
}

void solve(){
    int n,p;  cin>>n>>p;

    vector<pair<int,int>>pairs(p);
    for(int i =0; i< p;++i){
        cin >> pairs[i].first >> pairs[i].second;
    }

    int result = cnt_pairs(n, p, pairs);
    cout<<result<<endl;
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
