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
    pre();

    int tc;
    cin>>tc;

    int numOfBottles, totalCap;
        int reqWater;

    for(int i=0; i<tc; i++){
           
            cin>>numOfBottles>>totalCap;
            cin>>reqWater;

    }

  int sum = 0;
  for(int x=0; x<reqWater; x++){
    sum += reqWater;

    if(sum >1000000){
        break;
    }
  }

    return 0;
}
