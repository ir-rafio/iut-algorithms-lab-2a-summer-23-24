#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}
void dfs(LL start,vector<vector<LL>>&pairs,LL vis[],LL &size)
{
  for(auto it:pairs[start])
  {
    if(!vis[it])
    {
        vis[it]=1;
        size++;
        dfs(it,pairs,vis,size);
    }
  }
}



void solve(int tc)
{
    LL ast_no,pair_no,x,y;
    cin>>ast_no>>pair_no;
    vector<vector<LL>>pairs(ast_no);
    for(int i=1;i<=pair_no;i++)
    {
        cin>>x>>y;
        pairs[x].push_back(y);
    }
    LL vis[ast_no]={0};
    LL size=0;
    vector<LL>size_count;
    LL i;
    for( i=0;i<ast_no;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            size=0;
            dfs(i,pairs,vis,size);
            size_count.push_back(size);
        }
    }
    for(auto it:size_count)
    {
        cout<<it<<" ";
    }

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
    }

    return 0;
}