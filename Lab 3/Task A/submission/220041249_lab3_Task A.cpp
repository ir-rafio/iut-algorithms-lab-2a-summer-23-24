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
    int n,m;
    cin>> n >> m;
    vector<int> money(n);
    for (int i=0;i<n;i++)
    {
        cin >> money[i];
    }
    vector<vector<int>> adj(n);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vst(n,false);
    bool possible = true;
    
    for (int i=0;i<n;i++)
    {
        if (!vst[i])
        {
            vector<int> comp;
            stack<int> stk;
            stk.push(i);
            vst[i]=true;

            while(!stk.empty())
            {
                int u=stk.top();
                stk.pop();
                comp.push_back(u);

                for(int j=0;j<adj[u].size();j++)
                {
                    int v=adj[u][j];
                    if(!vst[v])
                    {
                        vst[v]=true;
                        stk.push(v);
                    }
                }
            }

            LL sum=0;
            for (int j=0;j<comp.size();j++)
            {
                sum +=money[comp[j]];
            }
            if(sum%comp.size() !=0)
            {
                possible=false;
                break;
            }
        }
    }

    cout << "case "<< tc <<": "<< (possible ? "Yes" : "No");
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