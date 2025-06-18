#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

enum color{
    WHITE,
    GRAY,
    BLACK
};

int sum = 0;
int counter = 0;

void pre()
{
    fastio;

    
}

void dfsVisit(vector<int>& list, vector<int>& personMoney, vector<color>& clr, int node){
    clr[node] = GRAY;
    counter++;
    sum += personMoney[node];
    for(int i=1; i<=list[node].size(); i++){
        if(list[node][i]==WHITE){
            dfsVisit()
        }
    }
}

void dfs(vector<int>& list, vector<int>& personMoney, vector<color>& clr){
    for(int i=1; i<=list.size(); i++){
        if(clr[i]==WHITE)
            dfsVisit(vector<int>& list, vector<int>& personMoney, vector<color>& clr, i);
    }
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> list(n+1);
    vector<int> personMoney(n+1);
    vector<color> clr(n+1, WHITE);

    for(int i=0; i<n; i++){
        cin >> personMoney[i];
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    dfs(list, personMoney, clr);
}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        //cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}