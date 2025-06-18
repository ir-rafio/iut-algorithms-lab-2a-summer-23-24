#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

void unionSet(int a, int b)
{
     if(ans[a]||ans[b] == 0){   
        return;
     }
     else
       
       
}

signed main()
{
    pre();

    int ans, pair;
    cin>>ans>>pair;

    int numOfAns[ans];

    for(int x=0; x<ans; x++){
        cin>>numOfAns[x];
    }

    for(int x=0; x<ans; x++){
        cin>>pair[x];
    }

    if(pair == 0){
        return;
    }
    else
      int a, b;
      cin>>a>>b;
      unionSet(a,b)

      
    return 0;
}