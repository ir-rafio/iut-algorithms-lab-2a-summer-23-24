#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void solve(int tc)
{
    LL n,m,p,qi;
    cin>>n>>m;
    LL money[n+1];

    for(int i=1;i<=n;i++)
    {
        cin>>money[i];
    }
    vector<vector<LL>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        cin>>p>>qi;
        adj[p].push_back(qi);
    }
    queue<int>q;
    LL vis[n+1]={0};
    // q.push[1];
    // vis[1]=1;
    LL money_count=0,node,people=0,equal=1;
    for(int i=1;i<=n;i++)
    {
        people=0;
        money_count=0;
      if(vis[i]!=1)
      {
         vis[i]=1;
         q.push(i);
         while(!q.empty())
         {
            node=q.front();
            q.pop();
            people++;
            money_count+=money[node];
            for(auto it:adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
         }
         //cout<<money_count<<" "<<people;
         if((money_count%people)!=0)
         {
            cout<<" No\n";
            equal=0;
            break;
         }
      }
    }
    if(equal==1)
    {
      cout<<"Yes\n";
    }
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