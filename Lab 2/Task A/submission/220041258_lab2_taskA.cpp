#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a;
    int b;
    int arr[100];

    int option;
    cin>>option;
    for(int s=0; s<option; s++)
    {
        int sum=0;
        int count =0;
        cin>>a;
        cin>>b;

        for(int i=0; i<a; i++)
        {
            cin>>arr[i];
        }
        sort(arr,a);
        for(int i=0; i<a; i++)
        {
            sum+=arr[i];
            count++;
            if(sum>=b)
            {
                break;
            }
        }
        if(sum==b)
            cout<<count<<endl;
        else
            cout<<count-1<<endl;
    }

    return 0;
}
