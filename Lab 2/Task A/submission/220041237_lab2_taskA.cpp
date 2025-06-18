#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int bottle, max;
        cin >> bottle >> max;
        vector<int> arr;
        int x;
        for (int i = 0; i < bottle; i++)
        {
            cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());

        int sum = 0;
        for (int i = 0; i < bottle; i++)
        {
            sum += arr[i];
            if (sum == max)
            {
                cout << i + 1 << endl;
                break;
            }
            else if (sum > max)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}