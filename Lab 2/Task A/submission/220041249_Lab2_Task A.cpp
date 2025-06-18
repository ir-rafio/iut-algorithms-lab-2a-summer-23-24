#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    int n;
    long long x;
    cin>>n>>x;

    long long bott[n];
    int i;
    for(i=0;i<n;++i)
    { 
        cin>>bott[i];
    }
sort(bott,bott+n);
 int count=0;
int j;
 for (j=0;j<n;++j)
 {
    if(x>=bott[i])
    {
        x-=bott[i];
        count++;
    }
    else
    {
        break;
        }
 }
 cout<<count<<endl;
}