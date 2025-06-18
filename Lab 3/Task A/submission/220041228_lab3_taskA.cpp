#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const int MAXX=1005;
vector<int>adj[MAXX];
bool visited[MAXX];
int money[MAXX];

void dfs(int u, int &c,LL &sum){
    visited[u]=true;
    c++;
    sum+=money[u];
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v,c,sum);
        }
    }
}



void pre()
{
    fastio;

    
}

void solve(int tc)
{

  int n, m;
  cin>>n>>m;
  LL total =0;
  for(int i=1; i<=n; i++){
    adj[i].clear();
    visited[i]=false;
  }

  for(int i=1; i<=n; i++){
    cin>>money[i];
    total+=money[i];
  }

  
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);

  }

  bool ok=true;
  if(total%n!=0){
    ok=false;
    
  }

  else 
  {
    LL target=total/n;
    for(int i=1; i<=n && ok; i++){
        if(!visited[i]){
            int c=0;
            LL sum=0;
            dfs(i, c,sum);
            if(sum!=c*target){
                ok=false;
                break;
            }
        }
    }
  }
 
  if(ok==true){
    cout<<"Yes";
  }
  else
  cout<<"NO";

     
     


   
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
