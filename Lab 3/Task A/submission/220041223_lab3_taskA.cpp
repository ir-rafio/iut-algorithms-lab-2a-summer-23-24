#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

int n, m, u, v;
int pairSum, pairSize;
vector<int> money;
vector<vector<int>> adj;
vector<bool> visited;


void pre()
{
    fastio;


}

void dfs(int n)
{
    visited[n]= true;
    pairSum += money[n];
    pairSize++;

    for(auto k : adj[n])
    {
        if(visited[k]==false) dfs(k);
    }
}

signed main()
{
    pre();


    cin >> t;

    for(int j =0; j<t; j++)
    {
        cin>>n>>m;
        money.resize(n);
        adj.assign(n, vector<int>());
        visited.assign(n, false);

        int total =0;

        for(int i=0; i<n; i++)
        {
            cin>>money[i];
            total += i;
        }

        for(int i =0; i<m; i++)
        {
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }



        bool possible = true;



        if (total % n ==0)
        {
            for(int i =0; i<n; i++)
            {
                if(visited[i] == false)
                {
                    pairSum = 0;
                    pairSize =0;
                    dfs(i);




                    if(pairSum%pairSize != 0)
                    {
                        possible = false;
                        break;
                    }


                }
            }
        }


        if(possible) cout<<"Case "<<j+1<<": Yes"<<endl;
        else cout<<"Case "<<tc<<": No"<<endl;

    }



    return 0;
}
