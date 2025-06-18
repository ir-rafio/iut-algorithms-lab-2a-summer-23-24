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
    
}

signed main()
{
  int t , n ;
  cin >> t ;
  while(t--)
  {
   cin >> n ;
   int s[n] , e[n];
   for(int i = 0 ; i < n ; i++)
   {
    cin >> s[i];
   }
    for(int j = i ; j < n ; j++)
    {
     cin >> e[j];
    }
   
   int count = 0 ;
   for(int j = 0 ; j < n ; j++)
   {
    for(int i = j ; i < n ; i++)
    {
     if(e[j] <= s[i])
     count++;
    }
   }
   cout << count + 1 << endl;
  }
    }

    return 0;
}

